#include <jni.h>
#include "../grt/GRT/GRT.h"
#include "handle.h"
#include "matrix.h"
#include "com_kano_grt_HMM.h"

JNIEXPORT void JNICALL Java_com_kano_grt_HMM_instantiate(JNIEnv * jenv, jobject obj) {
    GRT::HMM *t = new GRT::HMM();
    Handle<GRT::HMM>::setHandle(jenv, obj, t);
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_HMM_trainNative(JNIEnv *jenv, jobject obj, jobject jtscd){
    GRT::HMM *hmm = Handle<GRT::HMM>::getHandle(jenv, obj);
    GRT::TimeSeriesClassificationData *tscd = Handle<GRT::TimeSeriesClassificationData>::getHandle(jenv, jtscd);
    return (jboolean) hmm->train(*tscd);

}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_HMM_predictNative(JNIEnv *jenv, jobject obj, jobjectArray jdata){
    GRT::HMM *hmm = Handle<GRT::HMM>::getHandle(jenv, obj);
    GRT::MatrixFloat sample = JNIMatrix::sampleFromJObjectArray(jenv, jdata);
    bool result = hmm->predict(sample);
    return (jint) result;
}

JNIEXPORT jint JNICALL Java_com_kano_grt_HMM_getPredictedClassLabelNative(JNIEnv *jenv, jobject obj){
    GRT::HMM *hmm = Handle<GRT::HMM>::getHandle(jenv, obj);
    int result = hmm->getPredictedClassLabel();
    return (jint) result;
}

JNIEXPORT jdoubleArray JNICALL Java_com_kano_grt_HMM_getClassLikelihoodsNative(JNIEnv *jenv, jobject obj){
    GRT::HMM *hmm = Handle<GRT::HMM>::getHandle(jenv, obj);
    GRT::VectorFloat vectorReturn = hmm->getClassLikelihoods();
    jdoubleArray result = jenv->NewDoubleArray(vectorReturn.getSize());
    for (unsigned int i = 0; i < vectorReturn.getSize(); i++) {
        jenv->SetDoubleArrayRegion(result, i, vectorReturn.getSize(), (const jdouble*) &vectorReturn[i] );
    }
    return result;
}


JNIEXPORT jboolean JNICALL Java_com_kano_grt_HMM_setHMMTypeNative(JNIEnv *jenv, jobject obj, jint n) {
    GRT::HMM *hmm = Handle<GRT::HMM>::getHandle(jenv, obj);
    return (jboolean) hmm->setHMMType((int) n);
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_HMM_setNumStatesNative(JNIEnv *jenv, jobject obj, jint n) {
    GRT::HMM *hmm = Handle<GRT::HMM>::getHandle(jenv, obj);
    return (jboolean) hmm->setNumStates((int) n);
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_HMM_setNumSymbolsNative(JNIEnv *jenv, jobject obj, jint n) {
    GRT::HMM *hmm = Handle<GRT::HMM>::getHandle(jenv, obj);
    return (jboolean) hmm->setNumSymbols((int) n);
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_HMM_setModelTypeNative(JNIEnv *jenv, jobject obj, jint n) {
    GRT::HMM *hmm = Handle<GRT::HMM>::getHandle(jenv, obj);
    return (jboolean) hmm->setModelType((int) n);
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_HMM_setMinChangeNative(JNIEnv *jenv, jobject obj, jfloat n) {
    GRT::HMM *hmm = Handle<GRT::HMM>::getHandle(jenv, obj);
    return (jboolean) hmm->setMinChange((float) n);
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_HMM_setMaxNumEpochsNative(JNIEnv *jenv, jobject obj, jint n) {
    GRT::HMM *hmm = Handle<GRT::HMM>::getHandle(jenv, obj);
    return (jboolean) hmm->setMaxNumEpochs((int) n);
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_HMM_setNumRandomTrainingIterationsNative(JNIEnv *jenv, jobject obj, jint n) {
    GRT::HMM *hmm = Handle<GRT::HMM>::getHandle(jenv, obj);
    return (jboolean) hmm->setNumRandomTrainingIterations((int) n);
}
