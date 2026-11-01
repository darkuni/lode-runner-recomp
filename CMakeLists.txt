# lode_runner - ReXGlue Recompiled Project
#
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(lode_runner LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(generated/rexglue.cmake)

# Sources
set(LODERUNNER_SOURCES
    src/main.cpp
    src/game_menu.cpp
    src/crash_handler.cpp
    src/package_setup.cpp
)

if(WIN32)
    add_executable(lode_runner WIN32 ${LODERUNNER_SOURCES})
else()
    add_executable(lode_runner ${LODERUNNER_SOURCES})
endif()

rexglue_setup_target(lode_runner GPU_PLUGINS xenos)

# Linker map: turns crash-report offsets (lode_runner.exe+0x...) into
# recompiled function names.
if(WIN32)
    target_link_options(lode_runner PRIVATE "LINKER:/MAP:${CMAKE_BINARY_DIR}/lode_runner.map")
endif()
