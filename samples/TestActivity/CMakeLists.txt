set(TEST_ACTIVITY_SOURCES
    TestActivity.cpp
    TestService.cpp
)

set(TEST_ACTIVITY_HEADERS
    TestActivity.h
    TestService.h
)

set(TEST_ACTIVITY_LIB_DEPS
    android++
)

if (WIN32)
    list(APPEND TEST_ACTIVITY_SOURCES
        DLLMain.cpp
    )
endif ()

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${LIBRARY_PRODUCT_DIR}/include/android++"
    "${LIBRARY_PRODUCT_DIR}/include/android++/android"
)

add_library(TestActivity SHARED ${TEST_ACTIVITY_SOURCES} ${TEST_ACTIVITY_HEADERS})
target_link_libraries(TestActivity ${TEST_ACTIVITY_LIB_DEPS})
target_compile_definitions(TestActivity PRIVATE "-DBUILDING_ANDROID_PACKAGE")

set(TEST_ACTIVITY_LAUNCHER_SOURCES
    Main.cpp
)

add_executable(TestActivityLauncher ${TEST_ACTIVITY_LAUNCHER_SOURCES})
target_link_libraries(TestActivityLauncher TestActivity)
