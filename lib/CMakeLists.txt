project(lib)

set(HEADER_FILES
        CountDownLatch.h
        CyclicBarrier.h
        Exchanger.h )

set(SOURCE_FILES
        CountDownLatch.cpp
        CyclicBarrier.cpp
        Exchanger.cpp )

add_library(c3xx_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})