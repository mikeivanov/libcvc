// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#include "highgui.h"

CvEnum cv_mouse_event_types_enum[] = {
    {"EVENT_MOUSEMOVE",     cv::EVENT_MOUSEMOVE},
    {"EVENT_LBUTTONDOWN",   cv::EVENT_LBUTTONDOWN},
    {"EVENT_RBUTTONDOWN",   cv::EVENT_RBUTTONDOWN},
    {"EVENT_MBUTTONDOWN",   cv::EVENT_MBUTTONDOWN},
    {"EVENT_LBUTTONUP",     cv::EVENT_LBUTTONUP},
    {"EVENT_RBUTTONUP",     cv::EVENT_RBUTTONUP},
    {"EVENT_MBUTTONUP",     cv::EVENT_MBUTTONUP},
    {"EVENT_LBUTTONDBLCLK", cv::EVENT_LBUTTONDBLCLK},
    {"EVENT_RBUTTONDBLCLK", cv::EVENT_RBUTTONDBLCLK},
    {"EVENT_MBUTTONDBLCLK", cv::EVENT_MBUTTONDBLCLK},
    {"EVENT_MOUSEWHEEL",    cv::EVENT_MOUSEWHEEL},
    {"EVENT_MOUSEHWHEEL",   cv::EVENT_MOUSEHWHEEL},
    {nullptr, 0}
};

CvEnum cv_mouse_event_flags_enum[] = {
    {"EVENT_FLAG_LBUTTON",  cv::EVENT_FLAG_LBUTTON},
    {"EVENT_FLAG_RBUTTON",  cv::EVENT_FLAG_RBUTTON},
    {"EVENT_FLAG_MBUTTON",  cv::EVENT_FLAG_MBUTTON},
    {"EVENT_FLAG_CTRLKEY",  cv::EVENT_FLAG_CTRLKEY},
    {"EVENT_FLAG_SHIFTKEY", cv::EVENT_FLAG_SHIFTKEY},
    {"EVENT_FLAG_ALTKEY",   cv::EVENT_FLAG_ALTKEY},
    {nullptr, 0}
};

// Window
error_t cv_named_window(const char* winname, int flags) {
    try_
        cv::namedWindow(winname, flags);
    end_
}

error_t cv_destroy_window(const char* winname) {
    try_
        cv::destroyWindow(winname);
    end_
}

error_t cv_destroy_all_windows() {
    try_
        cv::destroyAllWindows();
    end_
}

error_t cv_imshow(const char* winname, Mat mat) {
    try_
        cv::imshow(winname, *mat);
    end_
}

error_t cv_get_window_property(const char* winname, int flag, double * out_value) {
    try_
        *out_value = cv::getWindowProperty(winname, flag);
    end_
}

error_t cv_set_window_property(const char* winname, int flag, double value) {
    try_
        cv::setWindowProperty(winname, flag, value);
    end_
}

error_t cv_set_window_title(const char* winname, const char* title) {
    try_
        cv::setWindowTitle(winname, title);
    end_
}

error_t cv_wait_key(int delay, int * out_key) {
    try_
        *out_key = cv::waitKey(delay);
    end_
}

error_t cv_move_window(const char* winname, int x, int y) {
    try_
        cv::moveWindow(winname, x, y);
    end_
}

error_t cv_resize_window(const char* winname, int width, int height) {
    try_
        cv::resizeWindow(winname, width, height);
    end_
}

error_t cv_set_mouse_callback(const char * winname, MouseCallback on_mouse, void * userdata) {
    try_
        cv::setMouseCallback(winname, on_mouse, userdata);
    end_
}
