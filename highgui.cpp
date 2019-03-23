// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#include "highgui.h"

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
