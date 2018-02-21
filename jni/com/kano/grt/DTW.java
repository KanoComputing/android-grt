package com.kano.grt;

public class DTW {
    static {
       System.loadLibrary("GRT");
    }
  
    public DTW() {
        instantiate();
    }

    public boolean train(TimeSeriesClassificationData sample) { return trainNative(sample); }
    public boolean predict(double[][] data) { return predictNative(data); }
    public int getPredictedClassLabel() { return getPredictedClassLabelNative(); }
    public double getMaximumLikelihood() { return getMaximumLikelihoodNative(); }

    private native void instantiate();
    private native boolean trainNative(TimeSeriesClassificationData sample);
    private native boolean predictNative(double[][] data);
    private native int getPredictedClassLabelNative();
    private native double getMaximumLikelihoodNative();

    private long nativeHandle;
}