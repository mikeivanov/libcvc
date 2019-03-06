#ifndef CVC_VIDEOIO_H
#define CVC_VIDEOIO_H

enum CvVideoCaptureAPIs {
    CAP_ANY          = 0,            //!< Auto detect == 0
    CAP_VFW          = 200,          //!< Video For Windows (obsolete, removed)
    CAP_V4L          = 200,          //!< V4L/V4L2 capturing support
    CAP_V4L2         = 200,      //!< Same as CAP_V4L
    CAP_FIREWIRE     = 300,          //!< IEEE 1394 drivers
    CAP_FIREWARE     = 300, //!< Same value as CAP_FIREWIRE
    CAP_IEEE1394     = 300, //!< Same value as CAP_FIREWIRE
    CAP_DC1394       = 300, //!< Same value as CAP_FIREWIRE
    CAP_CMU1394      = 300, //!< Same value as CAP_FIREWIRE
    CAP_QT           = 500,          //!< QuickTime (obsolete, removed)
    CAP_UNICAP       = 600,          //!< Unicap drivers (obsolete, removed)
    CAP_DSHOW        = 700,          //!< DirectShow (via videoInput)
    CAP_PVAPI        = 800,          //!< PvAPI, Prosilica GigE SDK
    CAP_OPENNI       = 900,          //!< OpenNI (for Kinect)
    CAP_OPENNI_ASUS  = 910,          //!< OpenNI (for Asus Xtion)
    CAP_ANDROID      = 1000,         //!< Android - not used
    CAP_XIAPI        = 1100,         //!< XIMEA Camera API
    CAP_AVFOUNDATION = 1200,         //!< AVFoundation framework for iOS (OS X Lion will have the same API)
    CAP_GIGANETIX    = 1300,         //!< Smartek Giganetix GigEVisionSDK
    CAP_MSMF         = 1400,         //!< Microsoft Media Foundation (via videoInput)
    CAP_WINRT        = 1410,         //!< Microsoft Windows Runtime using Media Foundation
    CAP_INTELPERC    = 1500,         //!< Intel Perceptual Computing SDK
    CAP_OPENNI2      = 1600,         //!< OpenNI2 (for Kinect)
    CAP_OPENNI2_ASUS = 1610,         //!< OpenNI2 (for Asus Xtion and Occipital Structure sensors)
    CAP_GPHOTO2      = 1700,         //!< gPhoto2 connection
    CAP_GSTREAMER    = 1800,         //!< GStreamer
    CAP_FFMPEG       = 1900,         //!< Open and record video file or stream using the FFMPEG library
    CAP_IMAGES       = 2000,         //!< OpenCV Image Sequence (e.g. img_%02d.jpg)
    CAP_ARAVIS       = 2100,         //!< Aravis SDK
    CAP_OPENCV_MJPEG = 2200,         //!< Built-in OpenCV MotionJPEG codec
    CAP_INTEL_MFX    = 2300,         //!< Intel MediaSDK
    CAP_XINE         = 2400,         //!< XINE engine (Linux)
};

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"

#ifdef __cplusplus
typedef cv::VideoCapture* VideoCapture;
typedef cv::VideoWriter* VideoWriter;
#else
typedef void* VideoCapture;
typedef void* VideoWriter;
#endif

// VideoCapture
VideoCapture cv_video_capture_new();
void cv_video_capture_free(VideoCapture v);

bool cv_video_capture_open_uri(VideoCapture v, const char* uri, int api_preference);
bool cv_video_capture_open_device(VideoCapture v, int device, int api_preference);
void cv_video_capture_set(VideoCapture v, int prop, double param);
double cv_video_capture_get(VideoCapture v, int prop);
bool cv_video_capture_is_opened(VideoCapture v);
bool cv_video_capture_read(VideoCapture v, Mat buf);
bool cv_video_capture_grab(VideoCapture v);
bool cv_video_capture_retrieve(VideoCapture v, Mat buf, int flag);

// VideoWriter
VideoWriter cv_video_writer_new();
void cv_video_writer_free(VideoWriter vw);

int cv_video_writer_fourcc(char c1, char c2, char c3, char c4);
bool cv_video_writer_open(VideoWriter vw, const char* name, int fourcc,
                          double fps, Size size, bool isColor);
bool cv_video_writer_is_opened(VideoWriter vw);
bool cv_video_writer_write(VideoWriter vw, Mat img);

#ifdef __cplusplus
}
#endif

#endif //CVC_VIDEOIO_H
