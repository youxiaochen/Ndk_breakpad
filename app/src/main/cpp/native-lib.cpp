#include <jni.h>
#include <stdio.h>

#include "Log.h"

struct Dog {
    int age;
};

extern "C" JNIEXPORT void JNICALL
Java_you_chen_linuxtest_MainActivity_test(JNIEnv *env, jobject /* this */) {
    Dog *dog = NULL;
    LOGD("dog age = %d", dog->age);
}

