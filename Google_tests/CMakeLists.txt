project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run
        CountDownLatch_Test.cpp
        Exchanger_Test.cpp)
target_link_libraries(Google_Tests_run c3xx_lib)
target_link_libraries(Google_Tests_run gtest gtest_main)