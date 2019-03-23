// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#ifndef CVC_IMGCODECS_H
#define CVC_IMGCODECS_H

#include <stdbool.h>

enum CvImreadModes {
    IMREAD_UNCHANGED = -1,
    IMREAD_GRAYSCALE = 0,
    IMREAD_COLOR = 1,
    IMREAD_ANYDEPTH = 2,
    IMREAD_ANYCOLOR = 4,
    IMREAD_REDUCED_GRAYSCALE_2 = 16,
    IMREAD_REDUCED_COLOR_2 = 17,
    IMREAD_REDUCED_GRAYSCALE_4 = 32,
    IMREAD_REDUCED_COLOR_4 = 33,
    IMREAD_REDUCED_GRAYSCALE_8 = 64,
    IMREAD_REDUCED_COLOR_8 = 65
};

enum CvImreadFlags {
    IMREAD_LOAD_GDAL = 8,
    IMREAD_IGNORE_ORIENTATION = 128
};

enum CvImwriteFlags {
    IMWRITE_JPEG_QUALITY        = 1,  //!< For JPEG, it can be a quality from 0 to 100 (the higher is the better). Default value is 95.
    IMWRITE_JPEG_PROGRESSIVE    = 2,  //!< Enable JPEG features, 0 or 1, default is False.
    IMWRITE_JPEG_OPTIMIZE       = 3,  //!< Enable JPEG features, 0 or 1, default is False.
    IMWRITE_JPEG_RST_INTERVAL   = 4,  //!< JPEG restart interval, 0 - 65535, default is 0 - no restart.
    IMWRITE_JPEG_LUMA_QUALITY   = 5,  //!< Separate luma quality level, 0 - 100, default is 0 - don't use.
    IMWRITE_JPEG_CHROMA_QUALITY = 6,  //!< Separate chroma quality level, 0 - 100, default is 0 - don't use.
    IMWRITE_PNG_COMPRESSION     = 16, //!< For PNG, it can be the compression level from 0 to 9. A higher value means a smaller size and longer compression time. If specified, strategy is changed to IMWRITE_PNG_STRATEGY_DEFAULT (Z_DEFAULT_STRATEGY). Default value is 1 (best speed setting).
    IMWRITE_PNG_STRATEGY        = 17, //!< One of cv::ImwritePNGFlags, default is IMWRITE_PNG_STRATEGY_RLE.
    IMWRITE_PNG_BILEVEL         = 18, //!< Binary level PNG, 0 or 1, default is 0.
    IMWRITE_PXM_BINARY          = 32, //!< For PPM, PGM, or PBM, it can be a binary format flag, 0 or 1. Default value is 1.
    IMWRITE_EXR_TYPE            = (3 << 4) + 0, /* 48 */ //!< override EXR storage type (FLOAT (FP32) is default)
    IMWRITE_WEBP_QUALITY        = 64, //!< For WEBP, it can be a quality from 1 to 100 (the higher is the better). By default (without any parameter) and for quality above 100 the lossless compression is used.
    IMWRITE_PAM_TUPLETYPE       = 128,//!< For PAM, sets the TUPLETYPE field to the corresponding string value that is defined for the format
    IMWRITE_TIFF_RESUNIT = 256,//!< For TIFF, use to specify which DPI resolution unit to set; see libtiff documentation for valid values
    IMWRITE_TIFF_XDPI = 257,//!< For TIFF, use to specify the X direction DPI
    IMWRITE_TIFF_YDPI = 258, //!< For TIFF, use to specify the Y direction DPI

    //enum ImwriteEXRTypeFlags {
    /*IMWRITE_EXR_TYPE_UNIT = 0, //!< not supported */
    IMWRITE_EXR_TYPE_HALF = 1,   //!< store as HALF (FP16)
    IMWRITE_EXR_TYPE_FLOAT = 2,   //!< store as FP32 (default)

    //enum ImwritePNGFlags {
    IMWRITE_PNG_STRATEGY_DEFAULT      = 0, //!< Use this value for normal data.
    IMWRITE_PNG_STRATEGY_FILTERED     = 1, //!< Use this value for data produced by a filter (or predictor).Filtered data consists mostly of small values with a somewhat random distribution. In this case, the compression algorithm is tuned to compress them better.
    IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY = 2, //!< Use this value to force Huffman encoding only (no string match).
    IMWRITE_PNG_STRATEGY_RLE          = 3, //!< Use this value to limit match distances to one (run-length encoding).
    IMWRITE_PNG_STRATEGY_FIXED        = 4,  //!< Using this value prevents the use of dynamic Huffman codes, allowing for a simpler decoder for special applications.

    //! Imwrite PAM specific tupletype flags used to define the 'TUPETYPE' field of a PAM file.
    //enum ImwritePAMFlags {
    IMWRITE_PAM_FORMAT_NULL = 0,
    IMWRITE_PAM_FORMAT_BLACKANDWHITE = 1,
    IMWRITE_PAM_FORMAT_GRAYSCALE = 2,
    IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA = 3,
    IMWRITE_PAM_FORMAT_RGB = 4,
    IMWRITE_PAM_FORMAT_RGB_ALPHA = 5
};

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"

error_t cv_imread(const char * filename, int flags, Mat out_img);
error_t cv_imread_multi(const char * filename, Mats mats, int flags);
error_t cv_imdecode(Buffer buf, int flags, Mat out_img);
error_t cv_imwrite(const char * filename, Mat img, Ints params);
error_t cv_imencode(const char * file_ext, Mat img, Ints params, Buffer out_buffer);
error_t cv_have_image_reader(const char * filename, bool * out_result);
error_t cv_have_image_writer(const char * filename, bool * out_result);

#ifdef __cplusplus
}
#endif

#endif //CVC_IMGCODECS_H
