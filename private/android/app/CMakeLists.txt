set(APP_SOURCES
    ActivityPrivate.cpp
)

set(APP_HEADERS
    ActivityPrivate.h
)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}/android"
    "${CMAKE_SOURCE_DIR}/private"
    "${CMAKE_CURRENT_BINARY_DIR}"
    "${CMAKE_BINARY_DIR}"
    "${LIBRARY_PRODUCT_DIR}/include"
    "${ANGLE_LIBRARY_DIR}/include"
)

add_library(private.android.app OBJECT ${APP_HEADERS} ${APP_SOURCES})
