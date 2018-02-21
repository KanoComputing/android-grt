#include <jni.h>
#include "../grt/GRT/GRT.h"
#include "handle.h"
#include "matrix.h"
#include "com_kano_grt_TimeSeriesClassificationData.h"

#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1, 
  SWIG_JavaIOException, 
  SWIG_JavaRuntimeException, 
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIGUNUSED SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" }
  };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  jenv->ExceptionClear();
  excep = jenv->FindClass(except_ptr->java_exception);
  if (excep)
    jenv->ThrowNew(excep, msg);
}

JNIEXPORT void JNICALL Java_com_kano_grt_TimeSeriesClassificationData_instantiate(JNIEnv * jenv, jobject obj) {
    GRT::TimeSeriesClassificationData *t = new GRT::TimeSeriesClassificationData();
    Handle<GRT::TimeSeriesClassificationData>::setHandle(jenv, obj, t);
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_TimeSeriesClassificationData_setInfoTextNative(JNIEnv * jenv, jobject obj, jstring infoText) {
    GRT::TimeSeriesClassificationData *tscd = Handle<GRT::TimeSeriesClassificationData>::getHandle(jenv, obj);

    if(!infoText) {
        SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
        return 0;
    }
    const char *infoTextString = jenv->GetStringUTFChars(infoText, 0);
    if (!infoTextString) return 0;
    bool result = (bool)(tscd)->setInfoText(std::string(infoTextString));
    return (jboolean) result;
}

JNIEXPORT jstring JNICALL Java_com_kano_grt_TimeSeriesClassificationData_getInfoTextNative(JNIEnv * jenv, jobject obj) {
  GRT::TimeSeriesClassificationData *tscd = Handle<GRT::TimeSeriesClassificationData>::getHandle(jenv, obj);
  std::string result = tscd->getInfoText();
  return jenv->NewStringUTF(result.c_str());
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_TimeSeriesClassificationData_setDatasetNameNative(JNIEnv *jenv, jobject obj, jstring jname) {
  GRT::TimeSeriesClassificationData *tscd = Handle<GRT::TimeSeriesClassificationData>::getHandle(jenv, obj);

  if(!jname) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
      return 0;
  }
  const char *nameString = jenv->GetStringUTFChars(jname, 0);
  if (!nameString) return 0;
  bool result = (bool)(tscd)->setDatasetName(std::string(nameString));
  return (jboolean) result;
}

JNIEXPORT jstring JNICALL Java_com_kano_grt_TimeSeriesClassificationData_getDatasetNameNative(JNIEnv *jenv, jobject obj) {
  GRT::TimeSeriesClassificationData *tscd = Handle<GRT::TimeSeriesClassificationData>::getHandle(jenv, obj);
  std::string result = tscd->getDatasetName();
  return jenv->NewStringUTF(result.c_str());
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_TimeSeriesClassificationData_setNumDimensionsNative(JNIEnv *jenv, jobject obj, jint jn) {
  GRT::TimeSeriesClassificationData *tscd = Handle<GRT::TimeSeriesClassificationData>::getHandle(jenv, obj);

  if(!jn) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null int");
      return 0;
  }
  bool result = (bool)(tscd)->setNumDimensions((int) jn);
  return (jboolean) result;
}

JNIEXPORT jint JNICALL Java_com_kano_grt_TimeSeriesClassificationData_getNumDimensionsNative(JNIEnv *jenv, jobject obj) {
  GRT::TimeSeriesClassificationData *tscd = Handle<GRT::TimeSeriesClassificationData>::getHandle(jenv, obj);
  int result = tscd->getNumDimensions();
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_com_kano_grt_TimeSeriesClassificationData_getNumSamplesNative(JNIEnv *jenv, jobject obj) {
  GRT::TimeSeriesClassificationData *tscd = Handle<GRT::TimeSeriesClassificationData>::getHandle(jenv, obj);
  int result = tscd->getNumSamples();
  return (jint) result;
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_TimeSeriesClassificationData_addSampleNative(JNIEnv *jenv, jobject obj, jint label, jobjectArray jMatrix) {
  GRT::TimeSeriesClassificationData *tscd = Handle<GRT::TimeSeriesClassificationData>::getHandle(jenv, obj);
  GRT::MatrixFloat sample = JNIMatrix::sampleFromJObjectArray(jenv, jMatrix);
  bool result = tscd->addSample((int) label, sample);
  return (jint) result;
}