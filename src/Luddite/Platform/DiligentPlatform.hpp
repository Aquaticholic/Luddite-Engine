#pragma once
#ifdef LD_PLATFORM_WINDOWS
    #define PLATFORM_WIN32 1
#endif //LD_PLATFORM_WINDOWS

#ifdef LD_PLATFORM_LINUX
    #define PLATFORM_LINUX 1
#endif //LD_PLATFORM_LINUX

#ifdef LD_PLATFORM_MACOS
    #define PLATFORM_MACOS 1
#endif //LD_PLATFORM_MACOS

#ifdef LD_PLATFORM_ANDROID
    #define PLATFORM_ANDROID 1
#endif //LD_PLATFORM_ANDROID

#ifdef LD_PLATFORM_IOS
    #define PLATFORM_IOS 1
#endif //LD_PLATFORM_IOS

#ifdef LD_DEBUG
    #ifndef DILIGENT_DEBUG
        #define DILIGENT_DEBUG
    #endif //DILIGENT_DEBUG
#else
    #ifdef DILIGENT_DEBUG
        #undef DILIGENT_DEBUG
    #endif //DILIGENT_DEBUG
#endif //LD_DEBUG