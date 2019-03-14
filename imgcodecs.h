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
    IMREAD_LOAD_GDAL = 8,
    IMREAD_REDUCED_GRAYSCALE_2 = 16,
    IMREAD_REDUCED_COLOR_2 = 17,
    IMREAD_REDUCED_GRAYSCALE_4 = 32,
    IMREAD_REDUCED_COLOR_4 = 33,
    IMREAD_REDUCED_GRAYSCALE_8 = 64,
    IMREAD_REDUCED_COLOR_8 = 65,
    IMREAD_IGNORE_ORIENTATION = 128
};

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"

Mat cv_imread(const char* filename, int flags);
Mat cv_imdecode(char * buf, int flags);

bool cv_imwrite(const char* filename, Mat img, Ints params);
Buffer cv_imencode(const char* file_ext, Mat img, Ints params);

#ifdef __cplusplus
}
#endif

#endif //CVC_IMGCODECS_H
