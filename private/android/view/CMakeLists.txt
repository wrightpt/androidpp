set(VIEW_SOURCES
    KeyEventPrivate.cpp
    MotionEventPrivate.cpp
    ViewHostWindow.cpp
    ViewPrivate.cpp
    WindowProvider.cpp
)

set(VIEW_HEADERS
    CompositionClause.h
    Cursor.h
    KeyEventPrivate.h
    MotionEventPrivate.h
    ViewHostWindow.h
    ViewPrivate.h
    WindowHandle.h
    WindowProvider.h
)

if (WIN32)
    list(APPEND VIEW_SOURCES
        win/CursorWin.cpp
        win/MenuWin.cpp
        win/WindowProviderWin.cpp
    )

    list(APPEND VIEW_HEADERS
        win/CursorWin.h
        win/MenuWin.h
        win/WindowProviderWin.h
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
    "${LIBRARY_PRODUCT_DIR}/include/wtl"
    "${ANGLE_LIBRARY_DIR}/include"
)

add_subdirectory(inputmethod)

add_library(private.android.view OBJECT ${VIEW_HEADERS} ${VIEW_SOURCES})
