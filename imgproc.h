// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#ifndef CVC_IMGPROC_H
#define CVC_IMGPROC_H

#include <stdbool.h>
#include "core.h"

#ifdef __cplusplus

#include <opencv2/opencv.hpp>

extern "C" {

#endif

extern CvEnum cv_line_types_enum[];
extern CvEnum cv_hershey_fonts_enum[];
extern CvEnum cv_color_conversion_codes_enum[];
extern CvEnum cv_interpolation_flags_enum[];
extern CvEnum cv_interpolation_warp_enum[];

error_t cv_cvt_color(Mat src, Mat dst, int code, int dstCn);
error_t cv_blur(Mat src, Mat dst, Size ksize, Point anchor, int borderType);
error_t cv_resize(Mat src, Mat dst, Size dsize, double fx, double fy, int interpolation);
error_t cv_line(Mat img, Point pt1, Point pt2, Scalar color, int thickness, int line_type, int shift);
error_t cv_arrowed_line(Mat img, Point pt1, Point pt2, Scalar color,
                        int thickness, int line_type, int shift, double tipLength);
error_t cv_circle(Mat img, Point center, int radius, Scalar color, int thickness, int lineType, int shift);
error_t cv_ellipse(Mat img, Point center, Size axes,
                   double angle, double startAngle, double endAngle,
                   Scalar color, int thickness, int lineType, int shift);
error_t cv_rectangle(Mat img, Rect rect, Scalar color, int thickness, int lineType, int shift);
error_t cv_get_text_size(const char* text, int fontFace, double fontScale, int thickness,
                         int * out_baseline, Size out_size);
error_t cv_put_text(Mat img, const char* text, Point org, int fontFace, double fontScale,
                    Scalar color, int thickness, int lineType, bool bottomLeftOrigin);
error_t cv_median_blur(Mat input, Mat output, int ksize);

#ifdef __cplusplus
}
#endif


#endif //CVC_IMGPROC_H
