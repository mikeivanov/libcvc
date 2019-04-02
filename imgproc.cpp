// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#include "imgproc.h"

CvEnum cv_line_types_enum[] = {
    {"FILLED",  cv::FILLED},
    {"LINE_4",  cv::LINE_4},
    {"LINE_8",  cv::LINE_8 },
    {"LINE_AA", cv::LINE_AA},
    {nullptr, 0}
};

CvEnum cv_hershey_fonts_enum[] = {
    {"FONT_HERSHEY_SIMPLEX",        cv::FONT_HERSHEY_SIMPLEX},
    {"FONT_HERSHEY_PLAIN",          cv::FONT_HERSHEY_PLAIN},
    {"FONT_HERSHEY_DUPLEX",         cv::FONT_HERSHEY_DUPLEX},
    {"FONT_HERSHEY_COMPLEX",        cv::FONT_HERSHEY_COMPLEX},
    {"FONT_HERSHEY_TRIPLEX",        cv::FONT_HERSHEY_TRIPLEX},
    {"FONT_HERSHEY_COMPLEX_SMALL",  cv::FONT_HERSHEY_COMPLEX_SMALL},
    {"FONT_HERSHEY_SCRIPT_SIMPLEX", cv::FONT_HERSHEY_SCRIPT_SIMPLEX},
    {"FONT_HERSHEY_SCRIPT_COMPLEX", cv::FONT_HERSHEY_SCRIPT_COMPLEX},
    {"FONT_ITALIC",                 cv::FONT_ITALIC},
    {nullptr, 0}
};

CvEnum cv_color_conversion_codes_enum[] = {
    {"COLOR_BGR2BGRA",        cv::COLOR_BGR2BGRA},
    {"COLOR_RGB2RGBA",        cv::COLOR_RGB2RGBA},
    {"COLOR_BGRA2BGR",        cv::COLOR_BGRA2BGR},
    {"COLOR_RGBA2RGB",        cv::COLOR_RGBA2RGB},
    {"COLOR_BGR2RGBA",        cv::COLOR_BGR2RGBA},
    {"COLOR_RGB2BGRA",        cv::COLOR_RGB2BGRA},
    {"COLOR_RGBA2BGR",        cv::COLOR_RGBA2BGR},
    {"COLOR_BGRA2RGB",        cv::COLOR_BGRA2RGB},
    {"COLOR_BGR2RGB",         cv::COLOR_BGR2RGB},
    {"COLOR_RGB2BGR",         cv::COLOR_RGB2BGR},
    {"COLOR_BGRA2RGBA",       cv::COLOR_BGRA2RGBA},
    {"COLOR_RGBA2BGRA",       cv::COLOR_RGBA2BGRA},
    {"COLOR_BGR2GRAY",        cv::COLOR_BGR2GRAY},
    {"COLOR_RGB2GRAY",        cv::COLOR_RGB2GRAY},
    {"COLOR_GRAY2BGR",        cv::COLOR_GRAY2BGR},
    {"COLOR_GRAY2RGB",        cv::COLOR_GRAY2RGB},
    {"COLOR_GRAY2BGRA",       cv::COLOR_GRAY2BGRA},
    {"COLOR_GRAY2RGBA",       cv::COLOR_GRAY2RGBA},
    {"COLOR_BGRA2GRAY",       cv::COLOR_BGRA2GRAY},
    {"COLOR_RGBA2GRAY",       cv::COLOR_RGBA2GRAY},
    {"COLOR_BGR2BGR565",      cv::COLOR_BGR2BGR565},
    {"COLOR_RGB2BGR565",      cv::COLOR_RGB2BGR565},
    {"COLOR_BGR5652BGR",      cv::COLOR_BGR5652BGR},
    {"COLOR_BGR5652RGB",      cv::COLOR_BGR5652RGB},
    {"COLOR_BGRA2BGR565",     cv::COLOR_BGRA2BGR565},
    {"COLOR_RGBA2BGR565",     cv::COLOR_RGBA2BGR565},
    {"COLOR_BGR5652BGRA",     cv::COLOR_BGR5652BGRA},
    {"COLOR_BGR5652RGBA",     cv::COLOR_BGR5652RGBA},
    {"COLOR_GRAY2BGR565",     cv::COLOR_GRAY2BGR565},
    {"COLOR_BGR5652GRAY",     cv::COLOR_BGR5652GRAY},
    {"COLOR_BGR2BGR555",      cv::COLOR_BGR2BGR555},
    {"COLOR_RGB2BGR555",      cv::COLOR_RGB2BGR555},
    {"COLOR_BGR5552BGR",      cv::COLOR_BGR5552BGR},
    {"COLOR_BGR5552RGB",      cv::COLOR_BGR5552RGB},
    {"COLOR_BGRA2BGR555",     cv::COLOR_BGRA2BGR555},
    {"COLOR_RGBA2BGR555",     cv::COLOR_RGBA2BGR555},
    {"COLOR_BGR5552BGRA",     cv::COLOR_BGR5552BGRA},
    {"COLOR_BGR5552RGBA",     cv::COLOR_BGR5552RGBA},
    {"COLOR_GRAY2BGR555",     cv::COLOR_GRAY2BGR555},
    {"COLOR_BGR5552GRAY",     cv::COLOR_BGR5552GRAY},
    {"COLOR_BGR2XYZ",         cv::COLOR_BGR2XYZ},
    {"COLOR_RGB2XYZ",         cv::COLOR_RGB2XYZ},
    {"COLOR_XYZ2BGR",         cv::COLOR_XYZ2BGR},
    {"COLOR_XYZ2RGB",         cv::COLOR_XYZ2RGB},
    {"COLOR_BGR2YCrCb",       cv::COLOR_BGR2YCrCb},
    {"COLOR_RGB2YCrCb",       cv::COLOR_RGB2YCrCb},
    {"COLOR_YCrCb2BGR",       cv::COLOR_YCrCb2BGR},
    {"COLOR_YCrCb2RGB",       cv::COLOR_YCrCb2RGB},
    {"COLOR_BGR2HSV",         cv::COLOR_BGR2HSV},
    {"COLOR_RGB2HSV",         cv::COLOR_RGB2HSV},
    {"COLOR_BGR2Lab",         cv::COLOR_BGR2Lab},
    {"COLOR_RGB2Lab",         cv::COLOR_RGB2Lab},
    {"COLOR_BGR2Luv",         cv::COLOR_BGR2Luv},
    {"COLOR_RGB2Luv",         cv::COLOR_RGB2Luv},
    {"COLOR_BGR2HLS",         cv::COLOR_BGR2HLS},
    {"COLOR_RGB2HLS",         cv::COLOR_RGB2HLS},
    {"COLOR_HSV2BGR",         cv::COLOR_HSV2BGR},
    {"COLOR_HSV2RGB",         cv::COLOR_HSV2RGB},
    {"COLOR_Lab2BGR",         cv::COLOR_Lab2BGR},
    {"COLOR_Lab2RGB",         cv::COLOR_Lab2RGB},
    {"COLOR_Luv2BGR",         cv::COLOR_Luv2BGR},
    {"COLOR_Luv2RGB",         cv::COLOR_Luv2RGB},
    {"COLOR_HLS2BGR",         cv::COLOR_HLS2BGR},
    {"COLOR_HLS2RGB",         cv::COLOR_HLS2RGB},
    {"COLOR_BGR2HSV_FULL",    cv::COLOR_BGR2HSV_FULL},
    {"COLOR_RGB2HSV_FULL",    cv::COLOR_RGB2HSV_FULL},
    {"COLOR_BGR2HLS_FULL",    cv::COLOR_BGR2HLS_FULL},
    {"COLOR_RGB2HLS_FULL",    cv::COLOR_RGB2HLS_FULL},
    {"COLOR_HSV2BGR_FULL",    cv::COLOR_HSV2BGR_FULL},
    {"COLOR_HSV2RGB_FULL",    cv::COLOR_HSV2RGB_FULL},
    {"COLOR_HLS2BGR_FULL",    cv::COLOR_HLS2BGR_FULL},
    {"COLOR_HLS2RGB_FULL",    cv::COLOR_HLS2RGB_FULL},
    {"COLOR_LBGR2Lab",        cv::COLOR_LBGR2Lab},
    {"COLOR_LRGB2Lab",        cv::COLOR_LRGB2Lab},
    {"COLOR_LBGR2Luv",        cv::COLOR_LBGR2Luv},
    {"COLOR_LRGB2Luv",        cv::COLOR_LRGB2Luv},
    {"COLOR_Lab2LBGR",        cv::COLOR_Lab2LBGR},
    {"COLOR_Lab2LRGB",        cv::COLOR_Lab2LRGB},
    {"COLOR_Luv2LBGR",        cv::COLOR_Luv2LBGR},
    {"COLOR_Luv2LRGB",        cv::COLOR_Luv2LRGB},
    {"COLOR_BGR2YUV",         cv::COLOR_BGR2YUV},
    {"COLOR_RGB2YUV",         cv::COLOR_RGB2YUV},
    {"COLOR_YUV2BGR",         cv::COLOR_YUV2BGR},
    {"COLOR_YUV2RGB",         cv::COLOR_YUV2RGB},
    {"COLOR_YUV2RGB_NV12",    cv::COLOR_YUV2RGB_NV12},
    {"COLOR_YUV2BGR_NV12",    cv::COLOR_YUV2BGR_NV12},
    {"COLOR_YUV2RGB_NV21",    cv::COLOR_YUV2RGB_NV21},
    {"COLOR_YUV2BGR_NV21",    cv::COLOR_YUV2BGR_NV21},
    {"COLOR_YUV420sp2RGB",    cv::COLOR_YUV420sp2RGB},
    {"COLOR_YUV420sp2BGR",    cv::COLOR_YUV420sp2BGR},
    {"COLOR_YUV2RGBA_NV12",   cv::COLOR_YUV2RGBA_NV12},
    {"COLOR_YUV2BGRA_NV12",   cv::COLOR_YUV2BGRA_NV12},
    {"COLOR_YUV2RGBA_NV21",   cv::COLOR_YUV2RGBA_NV21},
    {"COLOR_YUV2BGRA_NV21",   cv::COLOR_YUV2BGRA_NV21},
    {"COLOR_YUV420sp2RGBA",   cv::COLOR_YUV420sp2RGBA},
    {"COLOR_YUV420sp2BGRA",   cv::COLOR_YUV420sp2BGRA},
    {"COLOR_YUV2RGB_YV12",    cv::COLOR_YUV2RGB_YV12},
    {"COLOR_YUV2BGR_YV12",    cv::COLOR_YUV2BGR_YV12},
    {"COLOR_YUV2RGB_IYUV",    cv::COLOR_YUV2RGB_IYUV},
    {"COLOR_YUV2BGR_IYUV",    cv::COLOR_YUV2BGR_IYUV},
    {"COLOR_YUV2RGB_I420",    cv::COLOR_YUV2RGB_I420},
    {"COLOR_YUV2BGR_I420",    cv::COLOR_YUV2BGR_I420},
    {"COLOR_YUV420p2RGB",     cv::COLOR_YUV420p2RGB},
    {"COLOR_YUV420p2BGR",     cv::COLOR_YUV420p2BGR},
    {"COLOR_YUV2RGBA_YV12",   cv::COLOR_YUV2RGBA_YV12},
    {"COLOR_YUV2BGRA_YV12",   cv::COLOR_YUV2BGRA_YV12},
    {"COLOR_YUV2RGBA_IYUV",   cv::COLOR_YUV2RGBA_IYUV},
    {"COLOR_YUV2BGRA_IYUV",   cv::COLOR_YUV2BGRA_IYUV},
    {"COLOR_YUV2RGBA_I420",   cv::COLOR_YUV2RGBA_I420},
    {"COLOR_YUV2BGRA_I420",   cv::COLOR_YUV2BGRA_I420},
    {"COLOR_YUV420p2RGBA",    cv::COLOR_YUV420p2RGBA},
    {"COLOR_YUV420p2BGRA",    cv::COLOR_YUV420p2BGRA},
    {"COLOR_YUV2GRAY_420",    cv::COLOR_YUV2GRAY_420},
    {"COLOR_YUV2GRAY_NV21",   cv::COLOR_YUV2GRAY_NV21},
    {"COLOR_YUV2GRAY_NV12",   cv::COLOR_YUV2GRAY_NV12},
    {"COLOR_YUV2GRAY_YV12",   cv::COLOR_YUV2GRAY_YV12},
    {"COLOR_YUV2GRAY_IYUV",   cv::COLOR_YUV2GRAY_IYUV},
    {"COLOR_YUV2GRAY_I420",   cv::COLOR_YUV2GRAY_I420},
    {"COLOR_YUV420sp2GRAY",   cv::COLOR_YUV420sp2GRAY},
    {"COLOR_YUV420p2GRAY",    cv::COLOR_YUV420p2GRAY},
    {"COLOR_YUV2RGB_UYVY",    cv::COLOR_YUV2RGB_UYVY},
    {"COLOR_YUV2BGR_UYVY",    cv::COLOR_YUV2BGR_UYVY},
    {"COLOR_YUV2RGB_Y422",    cv::COLOR_YUV2RGB_Y422},
    {"COLOR_YUV2BGR_Y422",    cv::COLOR_YUV2BGR_Y422},
    {"COLOR_YUV2RGB_UYNV",    cv::COLOR_YUV2RGB_UYNV},
    {"COLOR_YUV2BGR_UYNV",    cv::COLOR_YUV2BGR_UYNV},
    {"COLOR_YUV2RGBA_UYVY",   cv::COLOR_YUV2RGBA_UYVY},
    {"COLOR_YUV2BGRA_UYVY",   cv::COLOR_YUV2BGRA_UYVY},
    {"COLOR_YUV2RGBA_Y422",   cv::COLOR_YUV2RGBA_Y422},
    {"COLOR_YUV2BGRA_Y422",   cv::COLOR_YUV2BGRA_Y422},
    {"COLOR_YUV2RGBA_UYNV",   cv::COLOR_YUV2RGBA_UYNV},
    {"COLOR_YUV2BGRA_UYNV",   cv::COLOR_YUV2BGRA_UYNV},
    {"COLOR_YUV2RGB_YUY2",    cv::COLOR_YUV2RGB_YUY2},
    {"COLOR_YUV2BGR_YUY2",    cv::COLOR_YUV2BGR_YUY2},
    {"COLOR_YUV2RGB_YVYU",    cv::COLOR_YUV2RGB_YVYU},
    {"COLOR_YUV2BGR_YVYU",    cv::COLOR_YUV2BGR_YVYU},
    {"COLOR_YUV2RGB_YUYV",    cv::COLOR_YUV2RGB_YUYV},
    {"COLOR_YUV2BGR_YUYV",    cv::COLOR_YUV2BGR_YUYV},
    {"COLOR_YUV2RGB_YUNV",    cv::COLOR_YUV2RGB_YUNV},
    {"COLOR_YUV2BGR_YUNV",    cv::COLOR_YUV2BGR_YUNV},
    {"COLOR_YUV2RGBA_YUY2",   cv::COLOR_YUV2RGBA_YUY2},
    {"COLOR_YUV2BGRA_YUY2",   cv::COLOR_YUV2BGRA_YUY2},
    {"COLOR_YUV2RGBA_YVYU",   cv::COLOR_YUV2RGBA_YVYU},
    {"COLOR_YUV2BGRA_YVYU",   cv::COLOR_YUV2BGRA_YVYU},
    {"COLOR_YUV2RGBA_YUYV",   cv::COLOR_YUV2RGBA_YUYV},
    {"COLOR_YUV2BGRA_YUYV",   cv::COLOR_YUV2BGRA_YUYV},
    {"COLOR_YUV2RGBA_YUNV",   cv::COLOR_YUV2RGBA_YUNV},
    {"COLOR_YUV2BGRA_YUNV",   cv::COLOR_YUV2BGRA_YUNV},
    {"COLOR_YUV2GRAY_UYVY",   cv::COLOR_YUV2GRAY_UYVY},
    {"COLOR_YUV2GRAY_YUY2",   cv::COLOR_YUV2GRAY_YUY2},
    {"COLOR_YUV2GRAY_Y422",   cv::COLOR_YUV2GRAY_Y422},
    {"COLOR_YUV2GRAY_UYNV",   cv::COLOR_YUV2GRAY_UYNV},
    {"COLOR_YUV2GRAY_YVYU",   cv::COLOR_YUV2GRAY_YVYU},
    {"COLOR_YUV2GRAY_YUYV",   cv::COLOR_YUV2GRAY_YUYV},
    {"COLOR_YUV2GRAY_YUNV",   cv::COLOR_YUV2GRAY_YUNV},
    {"COLOR_RGBA2mRGBA",      cv::COLOR_RGBA2mRGBA},
    {"COLOR_mRGBA2RGBA",      cv::COLOR_mRGBA2RGBA},
    {"COLOR_RGB2YUV_I420",    cv::COLOR_RGB2YUV_I420},
    {"COLOR_BGR2YUV_I420",    cv::COLOR_BGR2YUV_I420},
    {"COLOR_RGB2YUV_IYUV",    cv::COLOR_RGB2YUV_IYUV},
    {"COLOR_BGR2YUV_IYUV",    cv::COLOR_BGR2YUV_IYUV},
    {"COLOR_RGBA2YUV_I420",   cv::COLOR_RGBA2YUV_I420},
    {"COLOR_BGRA2YUV_I420",   cv::COLOR_BGRA2YUV_I420},
    {"COLOR_RGBA2YUV_IYUV",   cv::COLOR_RGBA2YUV_IYUV},
    {"COLOR_BGRA2YUV_IYUV",   cv::COLOR_BGRA2YUV_IYUV},
    {"COLOR_RGB2YUV_YV12",    cv::COLOR_RGB2YUV_YV12},
    {"COLOR_BGR2YUV_YV12",    cv::COLOR_BGR2YUV_YV12},
    {"COLOR_RGBA2YUV_YV12",   cv::COLOR_RGBA2YUV_YV12},
    {"COLOR_BGRA2YUV_YV12",   cv::COLOR_BGRA2YUV_YV12},
    {"COLOR_BayerBG2BGR",     cv::COLOR_BayerBG2BGR},
    {"COLOR_BayerGB2BGR",     cv::COLOR_BayerGB2BGR},
    {"COLOR_BayerRG2BGR",     cv::COLOR_BayerRG2BGR},
    {"COLOR_BayerGR2BGR",     cv::COLOR_BayerGR2BGR},
    {"COLOR_BayerBG2RGB",     cv::COLOR_BayerBG2RGB},
    {"COLOR_BayerGB2RGB",     cv::COLOR_BayerGB2RGB},
    {"COLOR_BayerRG2RGB",     cv::COLOR_BayerRG2RGB},
    {"COLOR_BayerGR2RGB",     cv::COLOR_BayerGR2RGB},
    {"COLOR_BayerBG2GRAY",    cv::COLOR_BayerBG2GRAY},
    {"COLOR_BayerGB2GRAY",    cv::COLOR_BayerGB2GRAY},
    {"COLOR_BayerRG2GRAY",    cv::COLOR_BayerRG2GRAY},
    {"COLOR_BayerGR2GRAY",    cv::COLOR_BayerGR2GRAY},
    {"COLOR_BayerBG2BGR_VNG", cv::COLOR_BayerBG2BGR_VNG},
    {"COLOR_BayerGB2BGR_VNG", cv::COLOR_BayerGB2BGR_VNG},
    {"COLOR_BayerRG2BGR_VNG", cv::COLOR_BayerRG2BGR_VNG},
    {"COLOR_BayerGR2BGR_VNG", cv::COLOR_BayerGR2BGR_VNG},
    {"COLOR_BayerBG2RGB_VNG", cv::COLOR_BayerBG2RGB_VNG},
    {"COLOR_BayerGB2RGB_VNG", cv::COLOR_BayerGB2RGB_VNG},
    {"COLOR_BayerRG2RGB_VNG", cv::COLOR_BayerRG2RGB_VNG},
    {"COLOR_BayerGR2RGB_VNG", cv::COLOR_BayerGR2RGB_VNG},
    {"COLOR_BayerBG2BGR_EA",  cv::COLOR_BayerBG2BGR_EA},
    {"COLOR_BayerGB2BGR_EA",  cv::COLOR_BayerGB2BGR_EA},
    {"COLOR_BayerRG2BGR_EA",  cv::COLOR_BayerRG2BGR_EA},
    {"COLOR_BayerGR2BGR_EA",  cv::COLOR_BayerGR2BGR_EA},
    {"COLOR_BayerBG2RGB_EA",  cv::COLOR_BayerBG2RGB_EA},
    {"COLOR_BayerGB2RGB_EA",  cv::COLOR_BayerGB2RGB_EA},
    {"COLOR_BayerRG2RGB_EA",  cv::COLOR_BayerRG2RGB_EA},
    {"COLOR_BayerGR2RGB_EA",  cv::COLOR_BayerGR2RGB_EA},
    {"COLOR_BayerBG2BGRA",    cv::COLOR_BayerBG2BGRA},
    {"COLOR_BayerGB2BGRA",    cv::COLOR_BayerGB2BGRA},
    {"COLOR_BayerRG2BGRA",    cv::COLOR_BayerRG2BGRA},
    {"COLOR_BayerGR2BGRA",    cv::COLOR_BayerGR2BGRA},
    {"COLOR_BayerBG2RGBA",    cv::COLOR_BayerBG2RGBA},
    {"COLOR_BayerGB2RGBA",    cv::COLOR_BayerGB2RGBA},
    {"COLOR_BayerRG2RGBA",    cv::COLOR_BayerRG2RGBA},
    {"COLOR_BayerGR2RGBA",    cv::COLOR_BayerGR2RGBA},
    {"COLOR_COLORCVT_MAX",    cv::COLOR_COLORCVT_MAX},
    {nullptr, 0}
};

CvEnum cv_interpolation_flags_enum[] = {
    {"INTER_NEAREST",      cv::INTER_NEAREST},
    {"INTER_LINEAR",       cv::INTER_LINEAR},
    {"INTER_CUBIC",        cv::INTER_CUBIC},
    {"INTER_AREA",         cv::INTER_AREA},
    {"INTER_LANCZOS4",     cv::INTER_LANCZOS4},
    {"INTER_LINEAR_EXACT", cv::INTER_LINEAR_EXACT},
    {"INTER_MAX",          cv::INTER_MAX},
    {nullptr, 0}
};

// Glued to cv::InterpolationFlags in OpenCV
// Splitting it out because they are semantically different.
CvEnum cv_interpolation_warp_enum[] = {
    {"WARP_NONE",          0}, // adding for consistency
    {"WARP_FILL_OUTLIERS", cv::WARP_FILL_OUTLIERS},
    {"WARP_INVERSE_MAP",   cv::WARP_INVERSE_MAP},
    {nullptr, 0}
};

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
