#ifndef _HANDLE_H_INCLUDED_
#define _HANDLE_H_INCLUDED_

#include <jni.h>

template <typename T>
class Handle {
    public:
        static jfieldID getHandleField(JNIEnv *env, jobject obj) {
            jclass c = env->GetObjectClass(obj);
            // J is the type signature for long:
            return env->GetFieldID(c, "nativeHandle", "J");
        }
        static T *getHandle(JNIEnv *env, jobject obj) {
            jlong handle = env->GetLongField(obj, getHandleField(env, obj));
            return reinterpret_cast<T *>(handle);
        }
        static void setHandle(JNIEnv *env, jobject obj, T *t) {
            jlong handle = reinterpret_cast<jlong>(t);
            env->SetLongField(obj, getHandleField(env, obj), handle);
        }
};

#endif