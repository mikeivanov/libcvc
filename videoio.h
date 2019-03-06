#ifndef CVC_VIDEOIO_H
#define CVC_VIDEOIO_H

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"

#ifdef __cplusplus
typedef cv::VideoCapture* VideoCapture;
typedef cv::VideoWriter* VideoWriter;
#else
typedef void* VideoCapture;
typedef void* VideoWriter;
#endif

// VideoCapture
VideoCapture cv_video_capture_new();
void cv_video_capture_free(VideoCapture v);

bool cv_video_capture_open_uri(VideoCapture v, const char* uri, int api_preference);
bool cv_video_capture_open_device(VideoCapture v, int device, int api_preference);
void cv_video_capture_set(VideoCapture v, int prop, double param);
double cv_video_capture_get(VideoCapture v, int prop);
bool cv_video_capture_is_opened(VideoCapture v);
bool cv_video_capture_read(VideoCapture v, Mat buf);
bool cv_video_capture_grab(VideoCapture v);
bool cv_video_capture_retrieve(VideoCapture v, Mat buf, int flag);

// VideoWriter
VideoWriter cv_video_writer_new();
void cv_video_writer_free(VideoWriter vw);

int cv_video_writer_fourcc(char c1, char c2, char c3, char c4);
bool cv_video_writer_open(VideoWriter vw, const char* name, int fourcc,
                          double fps, Size size, bool isColor);
bool cv_video_writer_is_opened(VideoWriter vw);
bool cv_video_writer_write(VideoWriter vw, Mat img);

#ifdef __cplusplus
}
#endif

#endif //CVC_VIDEOIO_H
