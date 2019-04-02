// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#ifndef CVC_IMGCODECS_H
#define CVC_IMGCODECS_H

#include <stdbool.h>
#include "core.h"

#ifdef __cplusplus

#include <opencv2/opencv.hpp>

extern "C" {

#endif

extern CvEnum cv_imread_modes_enum[];
extern CvEnum cv_imread_flags_enum[];
extern CvEnum cv_imwrite_flags_enum[];
extern CvEnum cv_imwrite_exr_type_flags_enum[];
extern CvEnum cv_imwrite_png_flags_enum[];
extern CvEnum cv_imwrite_pam_flags_enum[];

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
