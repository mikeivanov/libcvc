// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#ifndef CVC_HIGHGUI_H
#define CVC_HIGHGUI_H

enum CvMouseEventTypes {
    EVENT_MOUSEMOVE = 0,
    EVENT_LBUTTONDOWN = 1,
    EVENT_RBUTTONDOWN = 2,
    EVENT_MBUTTONDOWN = 3,
    EVENT_LBUTTONUP = 4,
    EVENT_RBUTTONUP = 5,
    EVENT_MBUTTONUP = 6,
    EVENT_LBUTTONDBLCLK = 7,
    EVENT_RBUTTONDBLCLK = 8,
    EVENT_MBUTTONDBLCLK = 9,
    EVENT_MOUSEWHEEL = 10,
    EVENT_MOUSEHWHEEL = 11
};

enum CvMouseEventFlags {
    EVENT_FLAG_LBUTTON = 1,
    EVENT_FLAG_RBUTTON = 2,
    EVENT_FLAG_MBUTTON = 4,
    EVENT_FLAG_CTRLKEY = 8,
    EVENT_FLAG_SHIFTKEY = 16,
    EVENT_FLAG_ALTKEY = 32
};

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"

#ifdef __cplusplus
typedef cv::MouseCallback MouseCallback;
typedef std::vector<cv::Mat> * Mats;
#else
typedef void(*MouseCallback) (int event, int x, int y, int flags, void *userdata);
#endif


void cv_named_window(const char* winname, int flags);
void cv_destroy_window(const char* winname);
void cv_destroy_all_windows();
bool cv_imshow(const char* winname, Mat mat);
double cv_get_window_property(const char* winname, int flag);
void cv_set_window_property(const char* winname, int flag, double value);
void cv_set_window_title(const char* winname, const char* title);
int cv_wait_key(int delay);
void cv_move_window(const char* winname, int x, int y);
void cv_resize_window(const char* winname, int width, int height);

bool cv_set_mouse_callback(const char * winname, MouseCallback on_mouse, void * userdata);

#ifdef __cplusplus
}
#endif

#endif //CVC_HIGHGUI_H
