#include <jni.h>
#include "../grt/GRT/GRT.h"
#include "handle.h"
#include "matrix.h"
#include "com_kano_grt_DTW.h"

JNIEXPORT void JNICALL Java_com_kano_grt_DTW_instantiate(JNIEnv * jenv, jobject obj) {
    GRT::DTW *t = new GRT::DTW();
    Handle<GRT::DTW>::setHandle(jenv, obj, t);
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_DTW_trainNative(JNIEnv *jenv, jobject obj, jobject jtscd){
    GRT::DTW *dtw = Handle<GRT::DTW>::getHandle(jenv, obj);
    GRT::TimeSeriesClassificationData *tscd = Handle<GRT::TimeSeriesClassificationData>::getHandle(jenv, jtscd);
    return (jboolean) dtw->train(*tscd);

}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_DTW_predictNative(JNIEnv *jenv, jobject obj, jobjectArray jdata){
    GRT::DTW *dtw = Handle<GRT::DTW>::getHandle(jenv, obj);
    GRT::MatrixFloat sample = JNIMatrix::sampleFromJObjectArray(jenv, jdata);
    bool result = dtw->predict(sample);
    return (jint) result;
}

JNIEXPORT jint JNICALL Java_com_kano_grt_DTW_getPredictedClassLabelNative(JNIEnv *jenv, jobject obj){
    GRT::DTW *dtw = Handle<GRT::DTW>::getHandle(jenv, obj);
    int result = dtw->getPredictedClassLabel();
    return (jint) result;
}

JNIEXPORT jdouble JNICALL Java_com_kano_grt_DTW_getMaximumLikelihoodNative(JNIEnv *jenv, jobject obj){
    GRT::DTW *dtw = Handle<GRT::DTW>::getHandle(jenv, obj);
    double result = dtw->getMaximumLikelihood();
    return (jdouble) result;
}