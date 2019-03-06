#ifndef CVC_IMGPROC_H
#define CVC_IMGPROC_H

#include <stdbool.h>

enum CvLineTypes {
    FILLED  = -1,
    LINE_4  = 4, //!< 4-connected line
    LINE_8  = 8, //!< 8-connected line
    LINE_AA = 16 //!< antialiased line
};

enum CvHersheyFonts {
    FONT_HERSHEY_SIMPLEX        = 0, //!< normal size sans-serif font
    FONT_HERSHEY_PLAIN          = 1, //!< small size sans-serif font
    FONT_HERSHEY_DUPLEX         = 2, //!< normal size sans-serif font (more complex than FONT_HERSHEY_SIMPLEX)
    FONT_HERSHEY_COMPLEX        = 3, //!< normal size serif font
    FONT_HERSHEY_TRIPLEX        = 4, //!< normal size serif font (more complex than FONT_HERSHEY_COMPLEX)
    FONT_HERSHEY_COMPLEX_SMALL  = 5, //!< smaller version of FONT_HERSHEY_COMPLEX
    FONT_HERSHEY_SCRIPT_SIMPLEX = 6, //!< hand-writing style font
    FONT_HERSHEY_SCRIPT_COMPLEX = 7, //!< more complex variant of FONT_HERSHEY_SCRIPT_SIMPLEX
    FONT_ITALIC                 = 16 //!< flag for italic font
};

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"

bool cv_cvt_color(Mat src, Mat dst, int code, int dst_cn);
bool cv_blur(Mat src, Mat dst, Size ksize, Point anchor, int border_type);
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
