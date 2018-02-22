package com.kano.grt;

public class HMM {
    static {
       System.loadLibrary("GRT");
    }
  
    public HMM() {
        instantiate();
    }

    public boolean train(TimeSeriesClassificationData sample) { return trainNative(sample); }
    public boolean predict(double[][] data) { return predictNative(data); }
    public int getPredictedClassLabel() { return getPredictedClassLabelNative(); }
    public double getMaximumLikelihood() { return getMaximumLikelihoodNative(); }
    public boolean setHMMType(int n) { return setHMMTypeNative(n); }
    public boolean setNumStates(int n) { return setNumStatesNative(n); }
    public boolean setNumSymbols(int n) { return setNumSymbolsNative(n); }
    public boolean setModelType(int n) { return setModelTypeNative(n); }
    public boolean setMinChange(float n) { return setMinChangeNative(n); }
    public boolean setMaxNumEpochs(int n) { return setMaxNumEpochsNative(n); }
    public boolean setNumRandomTrainingIterations(int n) { return setNumRandomTrainingIterationsNative(n); }

    private native void instantiate();
    private native boolean trainNative(TimeSeriesClassificationData sample);
    private native boolean predictNative(double[][] data);
    private native int getPredictedClassLabelNative();
    private native double getMaximumLikelihoodNative();
    private native boolean setHMMTypeNative(int n);
    private native boolean setNumStatesNative(int n);
    private native boolean setNumSymbolsNative(int n);
    private native boolean setModelTypeNative(int n);
    private native boolean setMinChangeNative(float n);
    private native boolean setMaxNumEpochsNative(int n);
    private native boolean setNumRandomTrainingIterationsNative(int n);

    private long nativeHandle;
}
