#include "matrix.h"

GRT::MatrixFloat JNIMatrix::sampleFromJObjectArray(JNIEnv *jenv, jobjectArray array) {
    int arrayLength = jenv->GetArrayLength(array);
    GRT::MatrixFloat sample;
    GRT::VectorFloat vector;
    for (unsigned int i = 0; i < arrayLength; i++) {
        jdoubleArray value = (jdoubleArray) jenv->GetObjectArrayElement(array, i);
        jdouble *doubleArray = jenv->GetDoubleArrayElements(value, 0);
        int rowLength = jenv->GetArrayLength(value);
        for (unsigned int j = 0; j < rowLength; j++) {
            jdouble item = doubleArray[j];
            vector.push_back((double) item);
        }
        sample.push_back(vector);
        vector.clear();
        jenv->ReleaseDoubleArrayElements(value, doubleArray, 0);
        jenv->DeleteLocalRef(value);
    }
    return sample;
}