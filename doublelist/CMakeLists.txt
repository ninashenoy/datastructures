cmake_minimum_required(VERSION 3.0.0)
project(linkedlist VERSION 0.1.0)

include(CTest)
enable_testing()
add_subdirectory(googletest)

add_executable(dlltest test.cpp dll.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

TARGET_LINK_LIBRARIES(dlltest gtest)
TARGET_COMPILE_DEFINITIONS(dlltest PRIVATE gtest_disable_pthreads=ON)
