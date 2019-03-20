// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#include "highgui.h"

// Window
void cv_named_window(const char* winname, int flags) {
    cv::namedWindow(winname, flags);
}

void cv_destroy_window(const char* winname) {
    cv::destroyWindow(winname);
}

void cv_destroy_all_windows() {
    cv::destroyAllWindows();
}

bool cv_imshow(const char* winname, Mat mat) {
    try {
        cv::imshow(winname, *mat);
        return true;
    }
    catch_exceptions(false);
}

double cv_get_window_property(const char* winname, int flag) {
    return cv::getWindowProperty(winname, flag);
}

void cv_set_window_property(const char* winname, int flag, double value) {
    cv::setWindowProperty(winname, flag, value);
}

void cv_set_window_title(const char* winname, const char* title) {
    cv::setWindowTitle(winname, title);
}

int cv_wait_key(int delay) {
    return cv::waitKey(delay);
}

void cv_move_window(const char* winname, int x, int y) {
    cv::moveWindow(winname, x, y);
}

void cv_resize_window(const char* winname, int width, int height) {
    cv::resizeWindow(winname, width, height);
}

bool cv_set_mouse_callback(const char * winname, MouseCallback on_mouse, void * userdata) {
    try {
        cv::setMouseCallback(winname, on_mouse, userdata);
        return true;
    }
    catch_exceptions(false);
}
