LOCAL_PATH := $(call my-dir)/../grt

include $(CLEAR_VARS)

LOCAL_C_INCLUDES += $(LOCAL_PATH) \
                    /GRT/** \
                    /GRT/**/** \
                    /GRT/**/**/**

LOCAL_MODULE    := GRT

LOCAL_SRC_FILES += $(wildcard $(LOCAL_PATH)/GRT/ClassificationModules/*/*.cpp) \
                   $(wildcard $(LOCAL_PATH)/GRT/ClassificationModules/**/**/*.cpp) \
                   $(wildcard $(LOCAL_PATH)/GRT/ClusteringModules/**/*.cpp) \
				   $(wildcard $(LOCAL_PATH)/GRT/ClusteringModules/**/**/*.cpp) \
                   $(wildcard $(LOCAL_PATH)/GRT/ContextModules/*.cpp) \
                   $(wildcard $(LOCAL_PATH)/GRT/CoreAlgorithms/**/*.cpp) \
                   $(wildcard $(LOCAL_PATH)/GRT/CoreModules/*.cpp) \
                   $(wildcard $(LOCAL_PATH)/GRT/DataStructures/*.cpp) \
                   $(wildcard $(LOCAL_PATH)/GRT/FeatureExtractionModules/**/*.cpp) \
                   $(wildcard $(LOCAL_PATH)/GRT/PostProcessingModules/*.cpp) \
                   $(wildcard $(LOCAL_PATH)/GRT/PreProcessingModules/*.cpp) \
                   $(wildcard $(LOCAL_PATH)/GRT/RegressionModules/**/**/*.cpp) \
                   $(wildcard $(LOCAL_PATH)/GRT/Util/*.cpp)

LOCAL_SRC_FILES += ../jni/com_kano_grt_TimeSeriesClassificationData.cxx
LOCAL_SRC_FILES += ../jni/com_kano_grt_DTW.cxx
LOCAL_SRC_FILES += ../jni/com_kano_grt_KMeansQuantizer.cxx
LOCAL_SRC_FILES += ../jni/com_kano_grt_HMM.cxx
LOCAL_SRC_FILES += ../jni/matrix.cxx

LOCAL_CPPFLAGS += -std=c++11

LOCAL_LDLIBS += -latomic
LOCAL_LDLIBS += -llog  

include $(BUILD_SHARED_LIBRARY)