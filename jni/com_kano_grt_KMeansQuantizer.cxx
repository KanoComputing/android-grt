#include <jni.h>
#include "../grt/GRT/GRT.h"
#include "handle.h"
#include "matrix.h"
#include "com_kano_grt_KMeansQuantizer.h"

JNIEXPORT void JNICALL Java_com_kano_grt_KMeansQuantizer_instantiate(JNIEnv * jenv, jobject obj) {
    GRT::KMeansQuantizer *t = new GRT::KMeansQuantizer();
    Handle<GRT::KMeansQuantizer>::setHandle(jenv, obj, t);
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_KMeansQuantizer_trainNative(JNIEnv *jenv, jobject obj, jobject jtscd){
    GRT::KMeansQuantizer *quantizer = Handle<GRT::KMeansQuantizer>::getHandle(jenv, obj);
    GRT::TimeSeriesClassificationData *tscd = Handle<GRT::TimeSeriesClassificationData>::getHandle(jenv, jtscd);
    return (jboolean) quantizer->train(*tscd);

}

JNIEXPORT jint JNICALL Java_com_kano_grt_KMeansQuantizer_quantizeNative(JNIEnv *jenv, jobject obj, jdoubleArray jdata){
    GRT::KMeansQuantizer *quantizer = Handle<GRT::KMeansQuantizer>::getHandle(jenv, obj);
    jdouble *doubleArray = jenv->GetDoubleArrayElements(jdata, 0);
    int rowLength = jenv->GetArrayLength(jdata);
    GRT::VectorFloat vector;
    for (unsigned int j = 0; j < rowLength; j++) {
        jdouble item = doubleArray[j];
        vector.push_back((double) item);
    }
    jenv->ReleaseDoubleArrayElements(jdata, doubleArray, 0);
    int result = quantizer->quantize(vector);
    return (jint) result;
}

JNIEXPORT jdoubleArray JNICALL Java_com_kano_grt_KMeansQuantizer_getFeatureVectorNative(JNIEnv *jenv, jobject obj){
    GRT::KMeansQuantizer *quantizer = Handle<GRT::KMeansQuantizer>::getHandle(jenv, obj);
    GRT::VectorFloat vectorReturn = quantizer->getFeatureVector();
    jdoubleArray result = jenv->NewDoubleArray(vectorReturn.getSize());
    for (unsigned int i = 0; i < vectorReturn.getSize(); i++) {
        jenv->SetDoubleArrayRegion(result, i, vectorReturn.getSize(), (const jdouble*) &vectorReturn[i] );
    }
    return result;
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_KMeansQuantizer_clearNative(JNIEnv *jenv, jobject obj){
    GRT::KMeansQuantizer *quantizer = Handle<GRT::KMeansQuantizer>::getHandle(jenv, obj);
    double result = quantizer->clear();
    return (jdouble) result;
}
