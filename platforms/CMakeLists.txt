set(PLATFORMS_SOURCES
    LogHelper.cpp
)

set(PLATFORMS_HEADERS
    CompilerMacros.h
    ExportMacros.h
    Functional.h
    KeywordMacros.h
    LogHelper.h
    Noncopyable.h
    Platform.h
    StringConversion.h
)

if (WIN32)
    list(APPEND PLATFORMS_SOURCES
        win/Assertions.cpp
    )

    list(APPEND PLATFORMS_HEADERS
        win/Assertions.h
        win/COMPtr.h
        win/SoftLinking.h
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
)

add_library(platforms.c++ OBJECT ${PLATFORMS_HEADERS} ${PLATFORMS_SOURCES})
