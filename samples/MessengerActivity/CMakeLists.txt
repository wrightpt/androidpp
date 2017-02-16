set(MESSENGER_ACTIVITY_SOURCES
    MessengerActivity.cpp
    MessengerService.cpp
)

set(MESSENGER_ACTIVITY_HEADERS
    MessengerActivity.h
    MessengerService.h
)

set(MESSENGER_ACTIVITY_LIB_DEPS
    android++
)

if (WIN32)
    list(APPEND MESSENGER_ACTIVITY_SOURCES
        DLLMain.cpp
    )
endif ()

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${LIBRARY_PRODUCT_DIR}/include/android++"
    "${LIBRARY_PRODUCT_DIR}/include/android++/android"
)

add_library(MessengerActivity SHARED ${MESSENGER_ACTIVITY_SOURCES} ${MESSENGER_ACTIVITY_HEADERS})
target_link_libraries(MessengerActivity ${MESSENGER_ACTIVITY_LIB_DEPS})
target_compile_definitions(MessengerActivity PRIVATE "-DBUILDING_ANDROID_PACKAGE")

set(MESSENGER_ACTIVITY_LAUNCHER_SOURCES
    Main.cpp
)

add_executable(MessengerActivityLauncher ${MESSENGER_ACTIVITY_LAUNCHER_SOURCES})
target_link_libraries(MessengerActivityLauncher MessengerActivity)
