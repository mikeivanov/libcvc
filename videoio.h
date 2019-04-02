// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#ifndef CVC_VIDEOIO_H
#define CVC_VIDEOIO_H

#include "core.h"

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#ifdef __cplusplus
typedef cv::VideoCapture* VideoCapture;
typedef cv::VideoWriter* VideoWriter;
#else
typedef void* VideoCapture;
typedef void* VideoWriter;
#endif

extern CvEnum cv_video_capture_apis_enum[];

error_t cv_video_capture_new(VideoCapture * out_capture);
error_t cv_video_capture_free(VideoCapture v);
error_t cv_video_capture_open_uri(VideoCapture v, const char* uri, int api_preference);
error_t cv_video_capture_open_device(VideoCapture v, int device, int api_preference);
error_t cv_video_capture_set(VideoCapture v, int prop, double param);
error_t cv_video_capture_get(VideoCapture v, int prop, double * out_value);
error_t cv_video_capture_is_opened(VideoCapture v, bool * out_value);
error_t cv_video_capture_read(VideoCapture v, Mat buf, bool * out_value);
error_t cv_video_capture_grab(VideoCapture v, bool * out_value);
error_t cv_video_capture_retrieve(VideoCapture v, Mat buf, int flag, bool * out_value);
error_t cv_video_writer_new(VideoWriter * out_writer);
error_t cv_video_writer_free(VideoWriter vw);
error_t cv_video_writer_fourcc(char c1, char c2, char c3, char c4, int * out_value);
error_t cv_video_writer_open(VideoWriter vw, const char* name, int fourcc,
                             double fps, Size size, bool is_color);
error_t cv_video_writer_is_opened(VideoWriter vw, bool * out_value);
error_t cv_video_writer_write(VideoWriter vw, Mat img);

#ifdef __cplusplus
}
#endif

#endif //CVC_VIDEOIO_H
