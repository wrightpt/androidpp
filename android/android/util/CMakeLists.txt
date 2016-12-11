set(UTIL_SOURCES
    DisplayMetrics.cpp
    Log.cpp
)

set(UTIL_HEADERS
    DisplayMetrics.h
    Log.h
)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${LIBRARY_PRODUCT_DIR}/include"
    "${LIBRARY_PRODUCT_DIR}/include/android"
    "${CMAKE_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}/android"
    "${CMAKE_SOURCE_DIR}/private"
    "${CMAKE_CURRENT_BINARY_DIR}"
    "${CMAKE_BINARY_DIR}"
)

add_library(android.util OBJECT ${UTIL_HEADERS} ${UTIL_SOURCES})
