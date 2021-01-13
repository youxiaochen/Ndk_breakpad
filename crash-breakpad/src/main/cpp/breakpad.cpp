#include <stdio.h>
#include <jni.h>
#include <android/log.h>

#include "client/linux/handler/exception_handler.h"
#include "client/linux/handler/minidump_descriptor.h"

#define LOG_TAG "youxiaochen"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)


bool DumpCallback(const google_breakpad::MinidumpDescriptor &descriptor, void *context, bool succeeded) {
    LOGD("===============crrrrash================");
    LOGD("Dump path: %s\n", descriptor.path());
    return succeeded;
}

extern "C"
JNIEXPORT void JNICALL
Java_you_chen_breakpad_BreakpadInit_initBreakpadNative(JNIEnv *env, jclass type, jstring path_) {
    const char *path = env->GetStringUTFChars(path_, 0);

    google_breakpad::MinidumpDescriptor descriptor(path);
    static google_breakpad::ExceptionHandler eh(descriptor, NULL, DumpCallback, NULL, true, -1);

    env->ReleaseStringUTFChars(path_, path);
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    return JNI_VERSION_1_6;
}