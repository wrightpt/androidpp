set(VIEW_SOURCES
    ContextMenu.cpp
    InputEvent.cpp
    KeyEvent.cpp
    MotionEvent.cpp
    View.cpp
    ViewGroup.cpp
)

set(VIEW_HEADERS
    ContextMenu.h
    InputDevice.h
    InputEvent.h
    KeyEvent.h
    Menu.h
    MenuItem.h
    MotionEvent.h
    View.h
    ViewGroup.h
    Window.h
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

add_subdirectory(inputmethod)

add_library(android.view OBJECT ${VIEW_HEADERS} ${VIEW_SOURCES})
