/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_kano_grt_KMeansQuantizer */

#ifndef _Included_com_kano_grt_KMeansQuantizer
#define _Included_com_kano_grt_KMeansQuantizer
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_kano_grt_KMeansQuantizer
 * Method:    instantiate
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_kano_grt_KMeansQuantizer_instantiate
  (JNIEnv *, jobject);

/*
 * Class:     com_kano_grt_KMeansQuantizer
 * Method:    setNumClustersNative
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_com_kano_grt_KMeansQuantizer_setNumClustersNative
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_kano_grt_KMeansQuantizer
 * Method:    trainNative
 * Signature: (Lcom/kano/grt/TimeSeriesClassificationData;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_kano_grt_KMeansQuantizer_trainNative
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_kano_grt_KMeansQuantizer
 * Method:    quantizeNative
 * Signature: ([D)I
 */
JNIEXPORT jint JNICALL Java_com_kano_grt_KMeansQuantizer_quantizeNative
  (JNIEnv *, jobject, jdoubleArray);

/*
 * Class:     com_kano_grt_KMeansQuantizer
 * Method:    getFeatureVectorNative
 * Signature: ()[D
 */
JNIEXPORT jdoubleArray JNICALL Java_com_kano_grt_KMeansQuantizer_getFeatureVectorNative
  (JNIEnv *, jobject);

/*
 * Class:     com_kano_grt_KMeansQuantizer
 * Method:    clearNative
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_kano_grt_KMeansQuantizer_clearNative
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
