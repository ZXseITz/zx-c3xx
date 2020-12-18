project(lib)

set(HEADER_FILES
        Exchanger.h
        )

set(SOURCE_FILES
        Exchanger.cpp
        )

add_library(c3xx_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})