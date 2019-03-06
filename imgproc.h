#ifndef CVC_IMGPROC_H
#define CVC_IMGPROC_H

#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"

Points cv_box_points(RotatedRect rect);
bool cv_cvt_color(Mat src, Mat dst, int code, int dstCn);
bool cv_blur(Mat src, Mat dst, Size ksize, Point anchor, int borderType);
bool cv_resize(Mat src, Mat dst, Size dsize, double fx, double fy, int interpolation);

void cv_line(Mat img, Point pt1, Point pt2, Scalar color, int thickness, int line_type, int shift);
void cv_arrowed_line(Mat img, Point pt1, Point pt2, Scalar color,
                    int thickness, int line_type, int shift, double tipLength);
void cv_circle(Mat img, Point center, int radius, Scalar color, int thickness, int line_type, int shift);
void cv_ellipse(Mat img, Point center, Size axes,
                double angle, double start_angle, double end_angle,
                Scalar color, int thickness, int line_type, int shift);
void cv_rectangle(Mat img, Rect rect, Scalar color, int thickness, int lineType, int shift);

Size cv_get_text_size(const char* text, int font_face, double font_scale, int thickness, int * base_line);
bool cv_put_text(Mat img, const char* text, Point org, int font_face, double font_scale,
                 Scalar color, int thickness, int line_type, bool bottom_left_origin);

#ifdef __cplusplus
}
#endif


#endif //CVC_IMGPROC_H
