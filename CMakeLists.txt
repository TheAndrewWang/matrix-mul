cmake_minimum_required(VERSION 3.14)
project(matrixm)

add_executable(
    matrixm 
    src/matrixm.cpp
)

target_include_directories(matrixm PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    matrix_tests
    src/matrix_tests.cc
    src/matrixm.cpp
)
target_compile_definitions(matrix_tests PRIVATE MATRIXM_UNIT_TEST)
target_include_directories(matrix_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(
    matrix_tests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(matrix_tests)