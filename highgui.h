// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#ifndef CVC_HIGHGUI_H
#define CVC_HIGHGUI_H

#include "core.h"

#ifdef __cplusplus

typedef cv::MouseCallback MouseCallback;

extern "C" {

#else

typedef void(*MouseCallback) (int event, int x, int y, int flags, void *userdata);

#endif

extern CvEnum cv_mouse_event_types_enum[];
extern CvEnum cv_mouse_event_flags_enum[];

error_t cv_named_window(const char* winname, int flags);
error_t cv_destroy_window(const char* winname);
error_t cv_destroy_all_windows();
error_t cv_imshow(const char* winname, Mat mat);
error_t cv_get_window_property(const char* winname, int flag, double * out_value);
error_t cv_set_window_property(const char* winname, int flag, double value);
error_t cv_set_window_title(const char* winname, const char* title);
error_t cv_wait_key(int delay, int * out_key);
error_t cv_move_window(const char* winname, int x, int y);
error_t cv_resize_window(const char* winname, int width, int height);
error_t cv_set_mouse_callback(const char * winname, MouseCallback on_mouse, void * userdata);

#ifdef __cplusplus
}
#endif

#endif //CVC_HIGHGUI_H
