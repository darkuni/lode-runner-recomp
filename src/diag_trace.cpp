// Diagnostic: Lode Runner crashes in sub_822C9188 (a state-machine method)
// with r31 == 0. Logs to diag_trace.txt when it is entered with a null
// object, and when any function it calls returns with a callee-saved register
// (r14-r31) changed. Only writes on an anomaly.

#include "generated/default/lode_runner_init.h"

#include <cstdio>
#include <mutex>

namespace {
std::mutex g_mu;
std::FILE* g_f = nullptr;
inline uint32_t Ld32(uint8_t* base, uint32_t a) { return REX_LOAD_U32(a); }
bool Valid(uint32_t a) { return a >= 0x40000000u && a < 0xFFFF0000u && (a & 3) == 0; }
void Open() { if (!g_f) g_f = std::fopen("diag_trace.txt", "w"); }
void Stack(PPCContext& ctx, uint8_t* base) {
  std::fprintf(g_f, " lr=%08X", uint32_t(ctx.lr));
  const uint32_t sp0 = ctx.r1.u32;
  uint32_t sp = sp0;
  for (int i = 0; i < 16 && Valid(sp); i++) {
    const uint32_t next = Ld32(base, sp);
    if (!Valid(next) || next <= sp || next - sp > 0x10000 || next - sp0 > 0x80000) break;
    const uint32_t ret = Ld32(base, next - 8);
    if (ret < 0x82000000u || ret >= 0x828D0000u) break;
    std::fprintf(g_f, " %08X", ret);
    sp = next;
  }
}
}  // namespace

extern "C" void __imp__sub_822C9188(PPCContext&, uint8_t*);
extern "C" void sub_822C9188(PPCContext& ctx, uint8_t* base) {
  if (ctx.r3.u32 == 0) {
    std::lock_guard<std::mutex> lk(g_mu);
    Open();
    if (g_f) {
      std::fprintf(g_f, "sub_822C9188 entered with r3=0");
      Stack(ctx, base);
      std::fprintf(g_f, "\n");
      std::fflush(g_f);
    }
  }
  __imp__sub_822C9188(ctx, base);
}

#define SAVED_CHECK(name)                                                         \
  extern "C" void __imp__##name(PPCContext&, uint8_t*);                            \
  extern "C" void name(PPCContext& ctx, uint8_t* base) {                           \
    uint64_t before[18];                                                           \
    const PPCRegister* r = &ctx.r14;                                               \
    for (int i = 0; i < 18; i++) before[i] = r[i].u64;                             \
    const uint32_t sp = ctx.r1.u32, r3 = ctx.r3.u32;                               \
    __imp__##name(ctx, base);                                                      \
    for (int i = 0; i < 18; i++) {                                                 \
      if ((uint32_t)r[i].u64 != (uint32_t)before[i] || ctx.r1.u32 != sp) {         \
        std::lock_guard<std::mutex> lk(g_mu);                                      \
        Open();                                                                    \
        if (g_f) {                                                                 \
          std::fprintf(g_f, #name " (r3=%08X) changed r%d %08X -> %08X, r1 %08X -> %08X", \
                       r3, 14 + i, (uint32_t)before[i], (uint32_t)r[i].u64, sp, ctx.r1.u32); \
          Stack(ctx, base);                                                        \
          std::fprintf(g_f, "\n");                                                 \
          std::fflush(g_f);                                                        \
        }                                                                          \
        break;                                                                     \
      }                                                                            \
    }                                                                              \
  }

SAVED_CHECK(sub_822C77A0)
SAVED_CHECK(sub_822C7880)
SAVED_CHECK(sub_822C7CD0)
SAVED_CHECK(sub_822C8088)
SAVED_CHECK(sub_822C8428)
SAVED_CHECK(sub_822C8738)
SAVED_CHECK(sub_822C8E28)
SAVED_CHECK(sub_822C8F28)
SAVED_CHECK(sub_822C90A8)
