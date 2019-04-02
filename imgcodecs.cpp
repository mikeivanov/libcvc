// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#include "imgcodecs.h"

CvEnum cv_imread_modes_enum[] = {
    {"IMREAD_UNCHANGED",           cv::IMREAD_UNCHANGED},
    {"IMREAD_GRAYSCALE",           cv::IMREAD_GRAYSCALE},
    {"IMREAD_COLOR",               cv::IMREAD_COLOR},
    {"IMREAD_ANYDEPTH",            cv::IMREAD_ANYDEPTH},
    {"IMREAD_ANYCOLOR",            cv::IMREAD_ANYCOLOR},
    {"IMREAD_REDUCED_GRAYSCALE_2", cv::IMREAD_REDUCED_GRAYSCALE_2},
    {"IMREAD_REDUCED_COLOR_2",     cv::IMREAD_REDUCED_COLOR_2},
    {"IMREAD_REDUCED_GRAYSCALE_4", cv::IMREAD_REDUCED_GRAYSCALE_4},
    {"IMREAD_REDUCED_COLOR_4",     cv::IMREAD_REDUCED_COLOR_4},
    {"IMREAD_REDUCED_GRAYSCALE_8", cv::IMREAD_REDUCED_GRAYSCALE_8},
    {"IMREAD_REDUCED_COLOR_8",     cv::IMREAD_REDUCED_COLOR_8},
    {nullptr, 0}
};

CvEnum cv_imread_flags_enum[] = {
    {"IMREAD_LOAD_GDAL",          cv::IMREAD_LOAD_GDAL},
    {"IMREAD_IGNORE_ORIENTATION", cv::IMREAD_IGNORE_ORIENTATION},
    {nullptr, 0}
};

CvEnum cv_imwrite_flags_enum[] = {
    {"IMWRITE_JPEG_QUALITY",          cv::IMWRITE_JPEG_QUALITY},
    {"IMWRITE_JPEG_PROGRESSIVE",      cv::IMWRITE_JPEG_PROGRESSIVE},
    {"IMWRITE_JPEG_OPTIMIZE",         cv::IMWRITE_JPEG_OPTIMIZE},
    {"IMWRITE_JPEG_RST_INTERVAL",     cv::IMWRITE_JPEG_RST_INTERVAL},
    {"IMWRITE_JPEG_LUMA_QUALITY",     cv::IMWRITE_JPEG_LUMA_QUALITY},
    {"IMWRITE_JPEG_CHROMA_QUALITY",   cv::IMWRITE_JPEG_CHROMA_QUALITY},
    {"IMWRITE_PNG_COMPRESSION",       cv::IMWRITE_PNG_COMPRESSION},
    {"IMWRITE_PNG_STRATEGY",          cv::IMWRITE_PNG_STRATEGY},
    {"IMWRITE_PNG_BILEVEL",           cv::IMWRITE_PNG_BILEVEL},
    {"IMWRITE_PXM_BINARY",            cv::IMWRITE_PXM_BINARY},
    {"IMWRITE_EXR_TYPE",              cv::IMWRITE_EXR_TYPE},
    {"IMWRITE_WEBP_QUALITY",          cv::IMWRITE_WEBP_QUALITY},
    {"IMWRITE_PAM_TUPLETYPE",         cv::IMWRITE_PAM_TUPLETYPE},
    {"IMWRITE_TIFF_RESUNIT",          cv::IMWRITE_TIFF_RESUNIT},
    {"IMWRITE_TIFF_XDPI",             cv::IMWRITE_TIFF_XDPI},
    {"IMWRITE_TIFF_YDPI",             cv::IMWRITE_TIFF_YDPI},
    {nullptr, 0}
};

CvEnum cv_imwrite_exr_type_flags_enum[] = {
    {"IMWRITE_EXR_TYPE_HALF",  cv::IMWRITE_EXR_TYPE_HALF},
    {"IMWRITE_EXR_TYPE_FLOAT", cv::IMWRITE_EXR_TYPE_FLOAT},
    {nullptr, 0}
};

CvEnum cv_imwrite_png_flags_enum[] = {
    {"IMWRITE_PNG_STRATEGY_DEFAULT",      cv::IMWRITE_PNG_STRATEGY_DEFAULT},
    {"IMWRITE_PNG_STRATEGY_FILTERED",     cv::IMWRITE_PNG_STRATEGY_FILTERED},
    {"IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY", cv::IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY},
    {"IMWRITE_PNG_STRATEGY_RLE",          cv::IMWRITE_PNG_STRATEGY_RLE},
    {"IMWRITE_PNG_STRATEGY_FIXED",        cv::IMWRITE_PNG_STRATEGY_FIXED},
    {nullptr, 0}
};

CvEnum cv_imwrite_pam_flags_enum[] = {
    {"IMWRITE_PAM_FORMAT_NULL",             cv::IMWRITE_PAM_FORMAT_NULL},
    {"IMWRITE_PAM_FORMAT_BLACKANDWHITE",    cv::IMWRITE_PAM_FORMAT_BLACKANDWHITE},
    {"IMWRITE_PAM_FORMAT_GRAYSCALE",        cv::IMWRITE_PAM_FORMAT_GRAYSCALE},
    {"IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA",  cv::IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA},
    {"IMWRITE_PAM_FORMAT_RGB",              cv::IMWRITE_PAM_FORMAT_RGB},
    {"IMWRITE_PAM_FORMAT_RGB_ALPHA",        cv::IMWRITE_PAM_FORMAT_RGB_ALPHA},
    {nullptr, 0}
};

error_t cv_imread(const char * filename, int flags, Mat out_img) {
    try_
        cv::Mat img = cv::imread(filename, flags);
        if (img.empty()) {
            return cv_set_error(OTHER_ERROR, "Cannot read image");
        }
        out_img->operator=(img);
    end_
}

error_t cv_imread_multi(const char * filename, Mats mats, int flags) {
    try_
        auto ok = imreadmulti(filename, *mats, flags);
        if (!ok) {
            return cv_set_error(OTHER_ERROR, "Cannot read image");
        }
    end_
}

error_t cv_imdecode(Buffer buf, int flags, Mat out_img) {
    try_
        cv::imdecode(*buf, flags, out_img);
        if (out_img->empty()) {
            return cv_set_error(OTHER_ERROR, "Cannot decode image");
        }
    end_
}

error_t cv_imwrite(const char* filename, Mat img, Ints params) {
    try_
        auto ok = cv::imwrite(filename, *img, *params);
        if (!ok) {
            return cv_set_error(OTHER_ERROR, "Cannot write image");
        }
    end_
}

error_t cv_imencode(const char * file_ext, Mat img, Ints params, Buffer out_buffer) {
    try_
        std::vector<uchar> buffer;
        auto ok = cv::imencode(file_ext, *img, buffer, *params);
        if (!ok) {
            return cv_set_error(OTHER_ERROR, "Cannot encode image");
        }
        out_buffer->operator=(buffer);
    end_
}

error_t cv_have_image_reader(const char * filename, bool * out_result) {
    try_
        *out_result = cv::haveImageReader(filename);
    end_
}

error_t cv_have_image_writer(const char * filename, bool * out_result) {
    try_
        *out_result = cv::haveImageWriter(filename);
    end_
}
