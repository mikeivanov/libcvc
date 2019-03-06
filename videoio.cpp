#include "videoio.h"

VideoCapture cv_video_capture_new() {
    return new cv::VideoCapture();
}

void cv_video_capture_free(VideoCapture v) {
    delete v;
}

bool cv_video_capture_open_uri(VideoCapture v, const char* uri, int api_preference) {
    try {
        auto result = v->open(uri, api_preference);
        if (!result) cv_set_error("Can't read from URI.");
        return result;
    }
    catch_exceptions(false);
}

bool cv_video_capture_open_device(VideoCapture v, int device, int api_preference) {
    try {
        auto result = v->open(device, api_preference);
        if (!result) cv_set_error("Can't open device.");
        return result;
    }
    catch_exceptions(false);
}

void cv_video_capture_set(VideoCapture v, int prop, double param) {
    v->set(prop, param);
}

double cv_video_capture_get(VideoCapture v, int prop) {
    return v->get(prop);
}

bool cv_video_capture_is_opened(VideoCapture v) {
    return v->isOpened();
}

bool cv_video_capture_read(VideoCapture v, Mat buf) {
    return v->read(*buf);
}

bool cv_video_capture_grab(VideoCapture v) {
    return v->grab();
}

bool cv_video_capture_retrieve(VideoCapture v, Mat buf, int flag) {
    return v->retrieve(*buf, flag);
}

// VideoWriter
VideoWriter cv_video_writer_new() {
    return new cv::VideoWriter();
}

void cv_video_writer_free(VideoWriter vw) {
    delete vw;
}

int cv_video_writer_fourcc(char c1, char c2, char c3, char c4) {
    return cv::VideoWriter::fourcc(c1, c2, c3, c4);
}

bool cv_video_writer_open(VideoWriter vw, const char* name, int fourcc,
                          double fps, Size size, bool is_color)
{
    try {
        auto result = vw->open(name, fourcc, fps, *size, is_color);
        if (!result) cv_set_error("Can't create file.");
        return result;
    }
    catch_exceptions(false);
}

bool cv_video_writer_is_opened(VideoWriter vw) {
    return vw->isOpened();
}

bool cv_video_writer_write(VideoWriter vw, Mat img) {
    try {
        vw->write(*img);
        return true;
    }
    catch_exceptions(false);
}
