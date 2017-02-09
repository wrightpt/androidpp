set(OS_SOURCES
    Bundle.cpp
    Handler.cpp
    Looper.cpp
    Message.cpp
    Messenger.cpp
    ParcelFileDescriptor.cpp
    Parcel.cpp
    Parcelable.cpp
)

set(OS_HEADERS
    Bundle.h
    Handler.h
    IBinder.h
    Looper.h
    Message.h
    Messenger.h
    Parcel.h
    ParcelFileDescriptor.h
    Parcelable.h
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

add_subdirectory(appkit)

add_library(android.os OBJECT ${OS_HEADERS} ${OS_SOURCES})
