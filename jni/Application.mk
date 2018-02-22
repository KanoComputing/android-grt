APP_ABI := armeabi-v7a
APP_PLATFORM := android-14

NDK_TOOLCHAIN_VERSION := clang
APP_STL := gnustl_static
APP_CPPFLAGS += -frtti
APP_CPPFLAGS += -fexceptions
APP_BUILD_SCRIPT := Android.mk