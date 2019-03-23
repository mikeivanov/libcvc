// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#include "videoio.h"

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
