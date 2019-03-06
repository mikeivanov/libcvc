#include "imgproc.h"

bool cv_cvt_color(Mat src, Mat dst, int code, int dstCn) {
    try {
        cv::cvtColor(*src, *dst, code, dstCn);
        return true;
    }
    catch_exceptions(false);
}

bool cv_blur(Mat src, Mat dst, Size ksize, Point anchor, int borderType) {
    try {
        cv::blur(*src, *dst, *ksize, *anchor, borderType);
        return true;
    }
    catch_exceptions(false);
}

bool cv_resize(Mat src, Mat dst, Size dsize, double fx, double fy, int interpolation) {
    try {
        cv::resize(*src, *dst, *dsize, fx, fy, interpolation);
        return true;
    }
    catch_exceptions(false);
}

void cv_line(Mat img, Point pt1, Point pt2, Scalar color, int thickness, int line_type, int shift) {
    cv::line(*img, *pt1, *pt2, *color, thickness, line_type, shift);
}

void cv_arrowed_line(Mat img, Point pt1, Point pt2, Scalar color,
                     int thickness, int line_type, int shift, double tipLength)
{
    cv::arrowedLine(*img, *pt1, *pt2, *color,
                    thickness, line_type, shift, tipLength);
}

void cv_circle(Mat img, Point center, int radius, Scalar color, int thickness, int lineType, int shift) {
    cv::circle(*img, *center, radius, *color, thickness, lineType, shift);
}

void cv_ellipse(Mat img, Point center, Size axes,
                double angle, double startAngle, double endAngle,
                Scalar color, int thickness, int lineType, int shift)
{
    cv::ellipse(*img, *center, *axes,
                angle, startAngle, endAngle, *color, thickness, lineType, shift);
}

void cv_rectangle(Mat img, Rect rect, Scalar color, int thickness, int lineType, int shift) {
    cv::rectangle(*img, *rect, *color, thickness, lineType, shift);
}

Size cv_get_text_size(const char* text, int fontFace, double fontScale, int thickness, int * baseLine) {
    try {
        int out_baseline = 0;
        auto size = cv::getTextSize(text, fontFace, fontScale, thickness, &out_baseline);
        if (baseLine != nullptr) {
            *baseLine = out_baseline;
        }
        return new cv::Size2f(size);
    }
    catch_exceptions(nullptr);
}

bool cv_put_text(Mat img, const char* text, Point org, int fontFace, double fontScale,
                 Scalar color, int thickness, int lineType, bool bottomLeftOrigin)
{
    try {
        cv::putText(*img, text, *org, fontFace, fontScale,
                    *color, thickness, lineType, bottomLeftOrigin);
        return true;
    }
    catch_exceptions(false);
}

