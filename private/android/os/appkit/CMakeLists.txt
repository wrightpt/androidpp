set(OS_SOURCES
)

set(OS_HEADERS
)

if (WIN32)
    list(APPEND OS_SOURCES
        win/MainWin.cpp
        win/ProcessLauncherWin.cpp
        win/ProcessWin.cpp
        win/ThreadWin.cpp
    )

    list(APPEND OS_HEADERS
    )
endif ()

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}/android"
    "${CMAKE_SOURCE_DIR}/private"
    "${CMAKE_CURRENT_BINARY_DIR}"
    "${CMAKE_BINARY_DIR}"
    "${LIBRARY_PRODUCT_DIR}/include"
    "${LIBRARY_PRODUCT_DIR}/include/ndk"
    "${ANGLE_LIBRARY_DIR}/include"
)

add_library(private.android.os.appkit OBJECT ${OS_HEADERS} ${OS_SOURCES})
