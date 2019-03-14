// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

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

// Not sure if this is a good idea
enum CvColorConversionCodes {
    COLOR_BGR2BGRA = 0,
    COLOR_RGB2RGBA = 0, //COLOR_BGR2BGRA,
    COLOR_BGRA2BGR = 1,
    COLOR_RGBA2RGB = 1, //COLOR_BGRA2BGR,
    COLOR_BGR2RGBA = 2,
    COLOR_RGB2BGRA = 2, //COLOR_BGR2RGBA,
    COLOR_RGBA2BGR = 3,
    COLOR_BGRA2RGB = 3, //COLOR_RGBA2BGR,
    COLOR_BGR2RGB = 4,
    COLOR_RGB2BGR = 4, //COLOR_BGR2RGB,
    COLOR_BGRA2RGBA = 5,
    COLOR_RGBA2BGRA = 5, //COLOR_BGRA2RGBA,
    COLOR_BGR2GRAY = 6,
    COLOR_RGB2GRAY = 7,
    COLOR_GRAY2BGR = 8,
    COLOR_GRAY2RGB = 8, //COLOR_GRAY2BGR,
    COLOR_GRAY2BGRA = 9,
    COLOR_GRAY2RGBA = 9, //COLOR_GRAY2BGRA,
    COLOR_BGRA2GRAY = 10,
    COLOR_RGBA2GRAY = 11,
    COLOR_BGR2BGR565 = 12,
    COLOR_RGB2BGR565 = 13,
    COLOR_BGR5652BGR = 14,
    COLOR_BGR5652RGB = 15,
    COLOR_BGRA2BGR565 = 16,
    COLOR_RGBA2BGR565 = 17,
    COLOR_BGR5652BGRA = 18,
    COLOR_BGR5652RGBA = 19,
    COLOR_GRAY2BGR565 = 20,
    COLOR_BGR5652GRAY = 21,
    COLOR_BGR2BGR555 = 22,
    COLOR_RGB2BGR555 = 23,
    COLOR_BGR5552BGR = 24,
    COLOR_BGR5552RGB = 25,
    COLOR_BGRA2BGR555 = 26,
    COLOR_RGBA2BGR555 = 27,
    COLOR_BGR5552BGRA = 28,
    COLOR_BGR5552RGBA = 29,
    COLOR_GRAY2BGR555 = 30,
    COLOR_BGR5552GRAY = 31,
    COLOR_BGR2XYZ = 32,
    COLOR_RGB2XYZ = 33,
    COLOR_XYZ2BGR = 34,
    COLOR_XYZ2RGB = 35,
    COLOR_BGR2YCrCb = 36,
    COLOR_RGB2YCrCb = 37,
    COLOR_YCrCb2BGR = 38,
    COLOR_YCrCb2RGB = 39,
    COLOR_BGR2HSV = 40,
    COLOR_RGB2HSV = 41,
    COLOR_BGR2Lab = 44,
    COLOR_RGB2Lab = 45,
    COLOR_BGR2Luv = 50,
    COLOR_RGB2Luv = 51,
    COLOR_BGR2HLS = 52,
    COLOR_RGB2HLS = 53,
    COLOR_HSV2BGR = 54,
    COLOR_HSV2RGB = 55,
    COLOR_Lab2BGR = 56,
    COLOR_Lab2RGB = 57,
    COLOR_Luv2BGR = 58,
    COLOR_Luv2RGB = 59,
    COLOR_HLS2BGR = 60,
    COLOR_HLS2RGB = 61,
    COLOR_BGR2HSV_FULL = 66,
    COLOR_RGB2HSV_FULL = 67,
    COLOR_BGR2HLS_FULL = 68,
    COLOR_RGB2HLS_FULL = 69,
    COLOR_HSV2BGR_FULL = 70,
    COLOR_HSV2RGB_FULL = 71,
    COLOR_HLS2BGR_FULL = 72,
    COLOR_HLS2RGB_FULL = 73,
    COLOR_LBGR2Lab = 74,
    COLOR_LRGB2Lab = 75,
    COLOR_LBGR2Luv = 76,
    COLOR_LRGB2Luv = 77,
    COLOR_Lab2LBGR = 78,
    COLOR_Lab2LRGB = 79,
    COLOR_Luv2LBGR = 80,
    COLOR_Luv2LRGB = 81,
    COLOR_BGR2YUV = 82,
    COLOR_RGB2YUV = 83,
    COLOR_YUV2BGR = 84,
    COLOR_YUV2RGB = 85,
    COLOR_YUV2RGB_NV12 = 90,
    COLOR_YUV2BGR_NV12 = 91,
    COLOR_YUV2RGB_NV21 = 92,
    COLOR_YUV2BGR_NV21 = 93,
    COLOR_YUV420sp2RGB = 92, //COLOR_YUV2RGB_NV21,
    COLOR_YUV420sp2BGR = 93, //COLOR_YUV2BGR_NV21,
    COLOR_YUV2RGBA_NV12 = 94,
    COLOR_YUV2BGRA_NV12 = 95,
    COLOR_YUV2RGBA_NV21 = 96,
    COLOR_YUV2BGRA_NV21 = 97,
    COLOR_YUV420sp2RGBA = 96, //COLOR_YUV2RGBA_NV21,
    COLOR_YUV420sp2BGRA = 97, //COLOR_YUV2BGRA_NV21,
    COLOR_YUV2RGB_YV12 = 98,
    COLOR_YUV2BGR_YV12 = 99,
    COLOR_YUV2RGB_IYUV = 100,
    COLOR_YUV2BGR_IYUV = 101,
    COLOR_YUV2RGB_I420 = 100, //COLOR_YUV2RGB_IYUV,
    COLOR_YUV2BGR_I420 = 101, //COLOR_YUV2BGR_IYUV,
    COLOR_YUV420p2RGB = 98, //COLOR_YUV2RGB_YV12,
    COLOR_YUV420p2BGR = 99, //COLOR_YUV2BGR_YV12,
    COLOR_YUV2RGBA_YV12 = 102,
    COLOR_YUV2BGRA_YV12 = 103,
    COLOR_YUV2RGBA_IYUV = 104,
    COLOR_YUV2BGRA_IYUV = 105,
    COLOR_YUV2RGBA_I420 = 104, //COLOR_YUV2RGBA_IYUV,
    COLOR_YUV2BGRA_I420 = 105, //COLOR_YUV2BGRA_IYUV,
    COLOR_YUV420p2RGBA = 102, //COLOR_YUV2RGBA_YV12,
    COLOR_YUV420p2BGRA = 103, //COLOR_YUV2BGRA_YV12,
    COLOR_YUV2GRAY_420 = 106,
    COLOR_YUV2GRAY_NV21 = 106, //COLOR_YUV2GRAY_420,
    COLOR_YUV2GRAY_NV12 = 106, //COLOR_YUV2GRAY_420,
    COLOR_YUV2GRAY_YV12 = 106, //COLOR_YUV2GRAY_420,
    COLOR_YUV2GRAY_IYUV = 106, //COLOR_YUV2GRAY_420,
    COLOR_YUV2GRAY_I420 = 106, //COLOR_YUV2GRAY_420,
    COLOR_YUV420sp2GRAY = 106, //COLOR_YUV2GRAY_420,
    COLOR_YUV420p2GRAY = 106, //COLOR_YUV2GRAY_420,
    COLOR_YUV2RGB_UYVY = 107,
    COLOR_YUV2BGR_UYVY = 108,
    COLOR_YUV2RGB_Y422 = 108, //COLOR_YUV2RGB_UYVY,
    COLOR_YUV2BGR_Y422 = 108, //COLOR_YUV2BGR_UYVY,
    COLOR_YUV2RGB_UYNV = 108, //COLOR_YUV2RGB_UYVY,
    COLOR_YUV2BGR_UYNV = 108, //COLOR_YUV2BGR_UYVY,
    COLOR_YUV2RGBA_UYVY = 111,
    COLOR_YUV2BGRA_UYVY = 112,
    COLOR_YUV2RGBA_Y422 = 111, //COLOR_YUV2RGBA_UYVY,
    COLOR_YUV2BGRA_Y422 = 112, //COLOR_YUV2BGRA_UYVY,
    COLOR_YUV2RGBA_UYNV = 111, //COLOR_YUV2RGBA_UYVY,
    COLOR_YUV2BGRA_UYNV = 112, //COLOR_YUV2BGRA_UYVY,
    COLOR_YUV2RGB_YUY2 = 115,
    COLOR_YUV2BGR_YUY2 = 116,
    COLOR_YUV2RGB_YVYU = 117,
    COLOR_YUV2BGR_YVYU = 118,
    COLOR_YUV2RGB_YUYV = 115, //COLOR_YUV2RGB_YUY2,
    COLOR_YUV2BGR_YUYV = 116, //COLOR_YUV2BGR_YUY2,
    COLOR_YUV2RGB_YUNV = 115, //COLOR_YUV2RGB_YUY2,
    COLOR_YUV2BGR_YUNV = 116, //COLOR_YUV2BGR_YUY2,
    COLOR_YUV2RGBA_YUY2 = 119,
    COLOR_YUV2BGRA_YUY2 = 120,
    COLOR_YUV2RGBA_YVYU = 121,
    COLOR_YUV2BGRA_YVYU = 122,
    COLOR_YUV2RGBA_YUYV = 119, //COLOR_YUV2RGBA_YUY2,
    COLOR_YUV2BGRA_YUYV = 120, //COLOR_YUV2BGRA_YUY2,
    COLOR_YUV2RGBA_YUNV = 119, //COLOR_YUV2RGBA_YUY2,
    COLOR_YUV2BGRA_YUNV = 120, //COLOR_YUV2BGRA_YUY2,
    COLOR_YUV2GRAY_UYVY = 123,
    COLOR_YUV2GRAY_YUY2 = 124,
    COLOR_YUV2GRAY_Y422 = 123, //COLOR_YUV2GRAY_UYVY,
    COLOR_YUV2GRAY_UYNV = 123, //COLOR_YUV2GRAY_UYVY,
    COLOR_YUV2GRAY_YVYU = 124, //COLOR_YUV2GRAY_YUY2,
    COLOR_YUV2GRAY_YUYV = 124, //COLOR_YUV2GRAY_YUY2,
    COLOR_YUV2GRAY_YUNV = 124, //COLOR_YUV2GRAY_YUY2,
    COLOR_RGBA2mRGBA = 125,
    COLOR_mRGBA2RGBA = 126,
    COLOR_RGB2YUV_I420 = 127,
    COLOR_BGR2YUV_I420 = 128,
    COLOR_RGB2YUV_IYUV = 127, //COLOR_RGB2YUV_I420,
    COLOR_BGR2YUV_IYUV = 128, //COLOR_BGR2YUV_I420,
    COLOR_RGBA2YUV_I420 = 129,
    COLOR_BGRA2YUV_I420 = 130,
    COLOR_RGBA2YUV_IYUV = 129, //COLOR_RGBA2YUV_I420,
    COLOR_BGRA2YUV_IYUV = 130, //COLOR_BGRA2YUV_I420,
    COLOR_RGB2YUV_YV12 = 131,
    COLOR_BGR2YUV_YV12 = 132,
    COLOR_RGBA2YUV_YV12 = 133,
    COLOR_BGRA2YUV_YV12 = 134,
    COLOR_BayerBG2BGR = 46,
    COLOR_BayerGB2BGR = 47,
    COLOR_BayerRG2BGR = 48,
    COLOR_BayerGR2BGR = 49,
    COLOR_BayerBG2RGB = 48, //COLOR_BayerRG2BGR,
    COLOR_BayerGB2RGB = 49, //COLOR_BayerGR2BGR,
    COLOR_BayerRG2RGB = 46, //COLOR_BayerBG2BGR,
    COLOR_BayerGR2RGB = 47, //COLOR_BayerGB2BGR,
    COLOR_BayerBG2GRAY = 86,
    COLOR_BayerGB2GRAY = 87,
    COLOR_BayerRG2GRAY = 88,
    COLOR_BayerGR2GRAY = 89,
    COLOR_BayerBG2BGR_VNG = 62,
    COLOR_BayerGB2BGR_VNG = 63,
    COLOR_BayerRG2BGR_VNG = 64,
    COLOR_BayerGR2BGR_VNG = 65,
    COLOR_BayerBG2RGB_VNG = 64, //COLOR_BayerRG2BGR_VNG,
    COLOR_BayerGB2RGB_VNG = 65, //COLOR_BayerGR2BGR_VNG,
    COLOR_BayerRG2RGB_VNG = 62, //COLOR_BayerBG2BGR_VNG,
    COLOR_BayerGR2RGB_VNG = 63, //COLOR_BayerGB2BGR_VNG,
    COLOR_BayerBG2BGR_EA = 135,
    COLOR_BayerGB2BGR_EA = 136,
    COLOR_BayerRG2BGR_EA = 137,
    COLOR_BayerGR2BGR_EA = 138,
    COLOR_BayerBG2RGB_EA = 137, //COLOR_BayerRG2BGR_EA,
    COLOR_BayerGB2RGB_EA = 138, //COLOR_BayerGR2BGR_EA,
    COLOR_BayerRG2RGB_EA = 135, //COLOR_BayerBG2BGR_EA,
    COLOR_BayerGR2RGB_EA = 136, //COLOR_BayerGB2BGR_EA,
    COLOR_BayerBG2BGRA = 139,
    COLOR_BayerGB2BGRA = 140,
    COLOR_BayerRG2BGRA = 141,
    COLOR_BayerGR2BGRA = 142,
    COLOR_BayerBG2RGBA = 141, //COLOR_BayerRG2BGRA,
    COLOR_BayerGB2RGBA = 142, //COLOR_BayerGR2BGRA,
    COLOR_BayerRG2RGBA = 139, //COLOR_BayerBG2BGRA,
    COLOR_BayerGR2RGBA = 140, //COLOR_BayerGB2BGRA,
    COLOR_COLORCVT_MAX = 143
};

enum CvInterpolationFlags {
    INTER_NEAREST        = 0,
    INTER_LINEAR         = 1,
    INTER_CUBIC          = 2,
    INTER_AREA           = 3,
    INTER_LANCZOS4       = 4,
    INTER_LINEAR_EXACT = 5,
    INTER_MAX            = 7,
    WARP_FILL_OUTLIERS   = 8,
    WARP_INVERSE_MAP     = 16
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
