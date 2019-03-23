// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#ifndef CVC_CORE_H
#define CVC_CORE_H

#include <stdint.h>
#include <stdbool.h>

#include "types.h"

enum CvDepths {
    DEPTH_8U  = 0,
    DEPTH_8S  = 1,
    DEPTH_16U = 2,
    DEPTH_16S = 3,
    DEPTH_32S = 4,
    DEPTH_32F = 5,
    DEPTH_64F = 6,
    DEPTH_16F = 7
};

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#ifdef __cplusplus
typedef cv::Mat * Mat;
typedef std::vector<cv::Mat> * Mats;
#else
typedef void * Mat;
typedef void * Mats;
#endif

// Mats ------------

error_t cv_mats_new(Mats * out_new_mats);
error_t cv_mats_new_copy(Mats mats, Mats * out_new_mats);
error_t cv_mats_new_with_data(int count, const Mat * data, Mats * out_new_mats);
error_t cv_mats_add(Mats self, Mat mat);
error_t cv_mats_free(Mats self);
error_t cv_mats_count(Mats self, int * out_count);
error_t cv_mats_get(Mats self, int i, Mat * out_mat_ref);

// Type ---------------------

error_t cv_make_type(int depth, int channels, int * out_type);
error_t cv_type_depth(int type, int * out_depth);
error_t cv_type_channels(int type, int * out_channels);

// Mat ----------------------

error_t cv_mat_new(Mat * out_new_mat);
error_t cv_mat_new_copy(Mat self, Mat * out_new_mat);
error_t cv_mat_new_with_scalar(Ints shape, int type, Scalar scalar, Mat * out_new_mat);
error_t cv_mat_new_with_data(Ints shape, int type, void * data, Mat * out_new_mat);
error_t cv_mat_new_with_roi(Mat source, Rect roi, Mat * out_new_mat);
error_t cv_mat_free(Mat self);
error_t cv_mat_empty(Mat self, bool * out_value);
error_t cv_mat_copy_to(Mat self, Mat dst);
error_t cv_mat_copy_to_with_mask(Mat self, Mat dst, Mat mask);
error_t cv_mat_convert_to(Mat self, Mat dst, int type, double alpha, double beta);
error_t cv_mat_reshape(Mat self, int cn, Ints shape, Mat out_mat);
error_t cv_mat_patch_nans(Mat self, double val);
error_t cv_mat_mean(Mat self, Scalar out_scalar);
error_t cv_mat_lut(Mat self, Mat lut, Mat dst);
error_t cv_mat_rows(Mat self, int * out_rows);
error_t cv_mat_cols(Mat self, int * out_cols);
error_t cv_mat_channels(Mat self, int * out_channels);
error_t cv_mat_depth(Mat self, int * out_depth);
error_t cv_mat_type(Mat self, int * out_type);
error_t cv_mat_elem_size(Mat self, size_t * out_size);
error_t cv_mat_step(Mat self, size_t * out_step);
error_t cv_mat_is_continuous(Mat self, bool * out_continuous);
error_t cv_mat_total(Mat self, size_t * out_total);
error_t cv_mat_dims(Mat self, size_t * out_dims);
error_t cv_mat_size(Mat self, Ints out_size);
error_t cv_mat_get_ptr(Mat m, const int * idx, void ** out_ptr);
error_t cv_get_tick_count(int64_t * out_count);
error_t cv_get_tick_frequency(double * out_freq);

// array ops -------------------------------

error_t cv_extract_channel(Mat src, Mat dst, int coi);
error_t cv_merge(Mats channels, Mat out_mat);

// matx ops ------------------------

error_t cv_mat_add_mat(Mat mat, Mat addendum);
error_t cv_mat_add_scalar(Mat mat, Scalar addendum);
error_t cv_mat_mul_const(Mat mat, double multiplier);
error_t cv_mat_dot(Mat self, Mat m, double * out);


#ifdef __cplusplus
}
#endif

#endif //CVC_CORE_H
