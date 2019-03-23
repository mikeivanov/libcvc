// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#include "imgproc.h"

error_t cv_cvt_color(Mat src, Mat dst, int code, int dstCn) {
    try_
        cv::cvtColor(*src, *dst, code, dstCn);
    end_
}

error_t cv_blur(Mat src, Mat dst, Size ksize, Point anchor, int borderType) {
    try_
        cv::blur(*src, *dst, *ksize, *anchor, borderType);
    end_
}

error_t cv_resize(Mat src, Mat dst, Size dsize, double fx, double fy, int interpolation) {
    try_
        cv::resize(*src, *dst, *dsize, fx, fy, interpolation);
    end_
}

error_t cv_line(Mat img, Point pt1, Point pt2, Scalar color, int thickness, int line_type, int shift) {
    try_
        cv::line(*img, *pt1, *pt2, *color, thickness, line_type, shift);
    end_
}

error_t cv_arrowed_line(Mat img, Point pt1, Point pt2, Scalar color,
                     int thickness, int line_type, int shift, double tipLength)
{
    try_
        cv::arrowedLine(*img, *pt1, *pt2, *color,
                        thickness, line_type, shift, tipLength);
    end_
}

error_t cv_circle(Mat img, Point center, int radius, Scalar color, int thickness, int lineType, int shift) {
    try_
        cv::circle(*img, *center, radius, *color, thickness, lineType, shift);
    end_
}

error_t cv_ellipse(Mat img, Point center, Size axes,
                   double angle, double startAngle, double endAngle,
                   Scalar color, int thickness, int lineType, int shift)
{
    try_
        cv::ellipse(*img, *center, *axes,
                    angle, startAngle, endAngle, *color, thickness, lineType, shift);
    end_
}

error_t cv_rectangle(Mat img, Rect rect, Scalar color, int thickness, int lineType, int shift) {
    try_
        cv::rectangle(*img, *rect, *color, thickness, lineType, shift);
    end_
}

error_t cv_get_text_size(const char* text, int fontFace, double fontScale, int thickness,
                         int * out_baseline, Size out_size)
{
    try_
        auto size = cv::getTextSize(text, fontFace, fontScale, thickness, out_baseline);
        out_size->operator=(size);
    end_
}

error_t cv_put_text(Mat img, const char* text, Point org, int fontFace, double fontScale,
                    Scalar color, int thickness, int lineType, bool bottomLeftOrigin)
{
    try_
        cv::putText(*img, text, *org, fontFace, fontScale,
                    *color, thickness, lineType, bottomLeftOrigin);
    end_
}

error_t cv_median_blur(Mat input, Mat output, int ksize) {
    try_
        cv::medianBlur(*input, *output, ksize);
    end_
}
