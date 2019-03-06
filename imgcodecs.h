#ifndef CVC_IMGCODECS_H
#define CVC_IMGCODECS_H

#include <stdbool.h>

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
