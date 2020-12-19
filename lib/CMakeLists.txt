project(lib)

set(HEADER_FILES
        CountDownLatch.h
        Exchanger.h
        )

set(SOURCE_FILES
        CountDownLatch.cpp
        Exchanger.cpp
        )

add_library(c3xx_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})