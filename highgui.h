// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#ifndef CVC_HIGHGUI_H
#define CVC_HIGHGUI_H

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"

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

#ifdef __cplusplus
}
#endif

#endif //CVC_HIGHGUI_H
