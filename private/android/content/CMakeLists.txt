set(CONTENT_SOURCES
    ContextPrivate.cpp
)

set(CONTENT_HEADERS
    ContextPrivate.h
)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${LIBRARY_PRODUCT_DIR}/include"
    "${LIBRARY_PRODUCT_DIR}/include/android"
    "${ANGLE_LIBRARY_DIR}/include"
    "${CMAKE_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}/android"
    "${CMAKE_SOURCE_DIR}/private"
    "${CMAKE_CURRENT_BINARY_DIR}"
    "${CMAKE_BINARY_DIR}"
)

add_library(private.android.content OBJECT ${CONTENT_HEADERS} ${CONTENT_SOURCES})
