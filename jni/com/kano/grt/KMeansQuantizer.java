package com.kano.grt;

public class KMeansQuantizer {
    static {
       System.loadLibrary("GRT");
    }
  
    public KMeansQuantizer() {
        instantiate();
    }

    public boolean train(TimeSeriesClassificationData sample) { return trainNative(sample); }
    public int quantize(double[] data) { return quantizeNative(data); }
    public double[] getFeatureVector() { return getFeatureVectorNative(); }
    public boolean clear() { return clearNative(); }

    private native void instantiate();
    private native boolean trainNative(TimeSeriesClassificationData sample);
    private native int quantizeNative(double[] data);
    private native double[] getFeatureVectorNative();
    private native boolean clearNative();

    private long nativeHandle;
}
