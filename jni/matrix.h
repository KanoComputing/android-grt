#ifndef _MATRIX_H_INCLUDED_
#define _MATRIX_H_INCLUDED_

#include <jni.h>
#include "../grt/GRT/GRT.h"

class JNIMatrix {
    public: 
        static GRT::MatrixFloat sampleFromJObjectArray(JNIEnv *jenv, jobjectArray array);
};


#endif