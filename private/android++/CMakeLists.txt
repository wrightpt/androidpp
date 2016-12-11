if (NOT ANDROID)
    set(ANDROID_SOURCES)
    set(ANDROID_LIB_DEPS
        cairo
        jsoncpp
    )

    if (WIN32)
        list(APPEND ANDROID_SOURCES
            DLLMain.cpp
        )
        list(APPEND ANDROID_LIB_DEPS
            mfuuid
            platforms
            pthreadnp
            ${WIN32_SYSTEM_LIBRARIES}
        )
    endif ()

    add_library(android++ SHARED
        ${ANDROID_SOURCES}
        $<TARGET_OBJECTS:android.content>
        $<TARGET_OBJECTS:android.content.res>
        $<TARGET_OBJECTS:android.graphics>
        $<TARGET_OBJECTS:android.media>
        $<TARGET_OBJECTS:android.media.appkit>
        $<TARGET_OBJECTS:android.opengl>
        $<TARGET_OBJECTS:android.opengl.appkit>
        $<TARGET_OBJECTS:android.os>
        $<TARGET_OBJECTS:android.os.appkit>
        $<TARGET_OBJECTS:android.util>
        $<TARGET_OBJECTS:android.view>
        $<TARGET_OBJECTS:android.view.appkit>
        $<TARGET_OBJECTS:android.view.inputmethod>
        $<TARGET_OBJECTS:android.widget>
        $<TARGET_OBJECTS:java.lang>
        $<TARGET_OBJECTS:platforms.c++>
        $<TARGET_OBJECTS:private.android.content>
        $<TARGET_OBJECTS:private.android.media>
        $<TARGET_OBJECTS:private.android.media.appkit>
        $<TARGET_OBJECTS:private.android.opengl>
        $<TARGET_OBJECTS:private.android.opengl.appkit>
        $<TARGET_OBJECTS:private.android.os>
        $<TARGET_OBJECTS:private.android.os.appkit>
        $<TARGET_OBJECTS:private.android.util>
        $<TARGET_OBJECTS:private.android.view>
        $<TARGET_OBJECTS:private.android.view.appkit>
        $<TARGET_OBJECTS:private.android.view.inputmethod>
        $<TARGET_OBJECTS:private.android.widget>
    )

    target_link_libraries(android++ ${ANDROID_LIB_DEPS})
endif ()
