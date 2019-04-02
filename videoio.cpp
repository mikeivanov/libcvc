// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#include "videoio.h"

CvEnum cv_video_capture_apis_enum[] = {
    {"CAP_ANY",          cv::CAP_ANY}, 
    {"CAP_VFW",          cv::CAP_VFW},
    {"CAP_V4L",          cv::CAP_V4L},
    {"CAP_V4L2",         cv::CAP_V4L2},
    {"CAP_FIREWIRE",     cv::CAP_FIREWIRE},
    {"CAP_FIREWARE",     cv::CAP_FIREWARE},
    {"CAP_IEEE1394",     cv::CAP_IEEE1394},
    {"CAP_DC1394",       cv::CAP_DC1394},
    {"CAP_CMU1394",      cv::CAP_CMU1394},
    {"CAP_QT",           cv::CAP_QT},
    {"CAP_UNICAP",       cv::CAP_UNICAP},
    {"CAP_DSHOW",        cv::CAP_DSHOW},
    {"CAP_PVAPI",        cv::CAP_PVAPI},
    {"CAP_OPENNI",       cv::CAP_OPENNI},
    {"CAP_OPENNI_ASUS",  cv::CAP_OPENNI_ASUS},
    {"CAP_ANDROID",      cv::CAP_ANDROID},
    {"CAP_XIAPI",        cv::CAP_XIAPI},
    {"CAP_AVFOUNDATION", cv::CAP_AVFOUNDATION},
    {"CAP_GIGANETIX",    cv::CAP_GIGANETIX},
    {"CAP_MSMF",         cv::CAP_MSMF},
    {"CAP_WINRT",        cv::CAP_WINRT},
    {"CAP_INTELPERC",    cv::CAP_INTELPERC},
    {"CAP_OPENNI2",      cv::CAP_OPENNI2},
    {"CAP_OPENNI2_ASUS", cv::CAP_OPENNI2_ASUS},
    {"CAP_GPHOTO2",      cv::CAP_GPHOTO2},
    {"CAP_GSTREAMER",    cv::CAP_GSTREAMER},
    {"CAP_FFMPEG",       cv::CAP_FFMPEG},
    {"CAP_IMAGES",       cv::CAP_IMAGES},
    {"CAP_ARAVIS",       cv::CAP_ARAVIS},
    {"CAP_OPENCV_MJPEG", cv::CAP_OPENCV_MJPEG},
    {"CAP_INTEL_MFX",    cv::CAP_INTEL_MFX},
    {"CAP_XINE",         cv::CAP_XINE},
    {nullptr, 0}
};

error_t cv_video_capture_new(VideoCapture * out_capture) {
    try_
        *out_capture = new cv::VideoCapture();
    end_
}

error_t cv_video_capture_free(VideoCapture v) {
    try_
        delete v;
    end_
}

error_t cv_video_capture_open_uri(VideoCapture v, const char* uri, int api_preference) {
    try_
        auto ok = v->open(uri, api_preference);
        if (!ok) return cv_set_error(OTHER_ERROR, "Cannot open URI");
    end_
}

error_t cv_video_capture_open_device(VideoCapture v, int device, int api_preference) {
    try_
        auto ok = v->open(device, api_preference);
        if (!ok) return cv_set_error(OTHER_ERROR, "Cannot open device");
    end_
}

error_t cv_video_capture_set(VideoCapture v, int prop, double param) {
    try_
        v->set(prop, param);
    end_
}

error_t cv_video_capture_get(VideoCapture v, int prop, double * out_value) {
    try_
        *out_value = v->get(prop);
    end_
}

error_t cv_video_capture_is_opened(VideoCapture v, bool * out_value) {
    try_
        *out_value = v->isOpened();
    end_
}

error_t cv_video_capture_read(VideoCapture v, Mat buf, bool * out_has_frame) {
    try_
        *out_has_frame = v->read(*buf);
    end_
}

error_t cv_video_capture_grab(VideoCapture v, bool * out_has_frame) {
    try_
        *out_has_frame = v->grab();
    end_
}

error_t cv_video_capture_retrieve(VideoCapture v, Mat buf, int flag, bool * out_has_frame) {
    try_
        *out_has_frame = v->retrieve(*buf, flag);
    end_
}

// VideoWriter
error_t cv_video_writer_new(VideoWriter * out_writer) {
    try_
        *out_writer = new cv::VideoWriter();
    end_
}

error_t cv_video_writer_free(VideoWriter vw) {
    try_
        delete vw;
    end_
}

error_t cv_video_writer_fourcc(char c1, char c2, char c3, char c4, int * out_value) {
    try_
        *out_value = cv::VideoWriter::fourcc(c1, c2, c3, c4);
    end_
}

error_t cv_video_writer_open(VideoWriter vw, const char* name, int fourcc,
                             double fps, Size size, bool is_color)
{
    try_
        auto ok = vw->open(name, fourcc, fps, *size, is_color);
        if (!ok) return cv_set_error(OTHER_ERROR, "Cannot open video writer");
    end_
}

error_t cv_video_writer_is_opened(VideoWriter vw, bool * out_value) {
    try_
        *out_value = vw->isOpened();
    end_
}

error_t cv_video_writer_write(VideoWriter vw, Mat img) {
    try_
        vw->write(*img);
    end_
}
