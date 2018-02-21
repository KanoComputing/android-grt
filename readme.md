# android-grt

Android JNI bindings for GRT

## Supported API

Only a subset of the GRT API has bindings defined through JNI. Please check the `jni/com/kano/grt` to check the supported API

## Developing

If you create a new file to implement a new class, don't forget to add the `.cxx` file to the `Android.mk` file so that the compiler picks it up.

If you want to generate a new class, follw this template:

```java
package com.kano.grt;

public class MyClass {
    // Load the library at runtime
    static {
       System.loadLibrary("GRT");
    }
  
    // This will generate a handle attached to the instance for your method to reference
    public MyClass() {
        instantiate();
    }

    // Your method, they will be available to use in the final API
    public boolean myMethod() { return myMethodNative(); }
    public boolean myMethod(int n) { return myMethodNative(n); }

    // Create the c++ instance and save a reference to it in the handle
    private native void instantiate();

    // Matching native methods
    private native boolean myMethodNative();
    private native boolean myMethodNative(int n);

    // Handle to the c++ instance
    private long nativeHandle;
}
```

To generate the `.h` file containing the definitions of your methods, run:

```sh
javac com/kano/grt/MyClass.java
javah com.kano.grt.MyClass
```

After generating the header you should have a `com_kano_grt_MyClass.h` file, copy the method declarations and create their definitions

```c++

#include <jni.h>
#include "../grt/GRT/GRT.h"
// Handle provides a way to attach adn retrieve a c++ instance to the jobject
#include "handle.h"
#include "com_kano_grt_DTW.h"

JNIEXPORT void JNICALL Java_com_kano_grt_MyMethod_instantiate(JNIEnv * jenv, jobject obj) {
    // Instantiate c++ object
    GRT::GRTClass *t = new GRT::GRTClass();
    // Set the Java instance handle
    Handle<GRT::GRTClass>::setHandle(jenv, obj, t);
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_DTW_myMethod(JNIEnv *jenv, jobject obj){
    // Retrieve the c++ class using the handle
    GRT::GRTClass *instance = Handle<GRT::GRTClass>::getHandle(jenv, obj);
    // Call the method and return its result
    return (jboolean) instance->nativeMethod();
}

JNIEXPORT jboolean JNICALL Java_com_kano_grt_DTW_myMethod(JNIEnv *jenv, jobject obj, jint n){
    // Retrieve the c++ class using the handle
    GRT::GRTClass *instance = Handle<GRT::GRTClass>::getHandle(jenv, obj);
    // Call the method and return its result
    return (jboolean) instance->nativeMethod((int) n);
}

```

This should expose a java class called `MyClass` with one method with two signatures `myMethod` that calls an underlying method in the GRT library to the `GRTClass` class.

## Building

You will need the android-ndk installed on your system. In the `jni` directory, run `ndk-build`. The generated libraries will be saved in the `libs` directory.

If you wish to only build for one platform during development, edit the `APP_ABI` section in the `Application.mk` file and set it to your testing device's platform.

