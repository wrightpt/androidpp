set(ACTIVITY_SOURCES
    TestActivity.cpp
    Main.cpp
)

set(ACTIVITY_HEADERS
    TestActivity.h
)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${LIBRARY_PRODUCT_DIR}/include/android++"
    "${LIBRARY_PRODUCT_DIR}/include/android++/android"
)

add_executable(TestActivity ${ACTIVITY_HEADERS} ${ACTIVITY_SOURCES})
