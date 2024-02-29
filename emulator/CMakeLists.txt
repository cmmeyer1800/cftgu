cmake_minimum_required(VERSION 3.10)

project(cgu_emu
        VERSION 0.0.1
        LANGUAGES CXX)

set(MAIN_SRCS
    src/cgu_emu.cpp
    src/core/core.cpp
)
set(TEST_SRCS
    src/test.cpp
)

# =====-----=====----- Argparse Lib Integration ----=====-----=====
include(FetchContent)
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)

# =====-----=====------ Catch2 Lib Integration -----=====-----=====
Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(cgu_emu ${MAIN_SRCS})
target_link_libraries(cgu_emu argparse)

add_executable(test ${TEST_SRCS})
target_link_libraries(test PRIVATE Catch2::Catch2WithMain)

install(TARGETS cgu_emu DESTINATION bin)