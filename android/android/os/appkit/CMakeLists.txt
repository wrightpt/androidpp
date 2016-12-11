set(OS_SOURCES
    MessageChannel.cpp
    MessageHost.cpp
    Messages.cpp
    Process.cpp
    ProcessLauncher.cpp
    Thread.cpp
)

set(OS_HEADERS
    MessageChannel.h
    MessageChannelMessages.h
    MessageHost.h
    MessageHostMessages.h
    Process.h
    ProcessLauncher.h
    ProcessMessages.h
    MessageFilter.h
    Messages.h
    Thread.h
)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}/android"
    "${CMAKE_SOURCE_DIR}/private"
    "${CMAKE_CURRENT_BINARY_DIR}"
    "${CMAKE_BINARY_DIR}"
    "${LIBRARY_PRODUCT_DIR}/include"
    "${LIBRARY_PRODUCT_DIR}/include/platforms"
    "${ANGLE_LIBRARY_DIR}/include"
)

add_library(android.os.appkit OBJECT ${OS_HEADERS} ${OS_SOURCES})
