package com.kano.grt;

public class TimeSeriesClassificationData {
    static {
       System.loadLibrary("GRT");
    }
  
    public TimeSeriesClassificationData() {
        instantiate();
    }

    public boolean setInfoText(String infoText) { return setInfoTextNative(infoText); }
    public String getInfoText() { return getInfoTextNative(); }
    public boolean setDatasetName(String name) { return setDatasetNameNative(name); }
    public String getDatasetName() { return getDatasetNameNative(); }
    public boolean setNumDimensions(int n) { return setNumDimensionsNative(n); }
    public int getNumDimensions() { return getNumDimensionsNative(); }
    public int getNumSamples() { return getNumSamplesNative(); }
    public boolean addSample(int label, double[][] matrix) { return addSampleNative(label, matrix); }

    private native void instantiate();
    private native boolean setInfoTextNative(String infoText);
    private native String getInfoTextNative();
    private native boolean setDatasetNameNative(String name);
    private native String getDatasetNameNative();
    private native boolean setNumDimensionsNative(int n);
    private native int getNumDimensionsNative();
    private native int getNumSamplesNative();
    private native boolean addSampleNative(int label, double[][] data);

    private long nativeHandle;
}