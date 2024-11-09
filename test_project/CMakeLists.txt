cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  test1
  test1.cpp
)
target_link_libraries(
  test1
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test1)