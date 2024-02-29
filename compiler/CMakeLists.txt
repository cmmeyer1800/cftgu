cmake_minimum_required(VERSION 3.10)

project(cgu_cmp
        VERSION 0.0.1
        LANGUAGES CXX)

set(MAIN_SRCS
    src/cgu_cmp.cpp
    src/file/file.cpp
    src/parser/parser.cpp
    src/token/token.cpp
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

add_executable(cgu_cmp ${MAIN_SRCS})
target_link_libraries(cgu_cmp argparse)

add_executable(test ${TEST_SRCS})
target_link_libraries(test PRIVATE Catch2::Catch2WithMain)

install(TARGETS cgu_cmp DESTINATION bin)
