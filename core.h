#ifndef CVC_CORE_H
#define CVC_CORE_H

#include <stdint.h>
#include <stdbool.h>

#include "types.h"

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

typedef int mat_type_t;

// Mats ------------------------------------------------------------

Mats cv_mats_new();
Mats cv_mats_new_with_data(int size, const Mat * data);
void cv_mats_free(Mats self);
Mats cv_mats_add(Mats self, Mat mat);
int cv_mats_count(Mats self);
Mat cv_mats_get(Mats self, int i);

// Type ------------------------------------------

int cv_make_type(int depth, int channels);
int cv_type_depth(int type);
int cv_type_channels(int type);

// Mat --------------------------------------------------------

Mat cv_mat_new();
Mat cv_mat_new_with_scalar(Ints shape, int type, Scalar scalar);
Mat cv_mat_new_with_bytes(Ints shape, int type, uchar * bytes);
Mat cv_mat_copy(Mat self);
void cv_mat_free(Mat m);

bool cv_mat_empty(Mat m);

bool cv_mat_copy_to(Mat m, Mat dst);
bool cv_mat_copy_to_to_with_mask(Mat m, Mat dst, Mat mask);
bool cv_mat_convert_to(Mat m, Ints shape);
Buffer cv_mat_to_buffer(Mat m);

void cv_mat_patch_nans(Mat m, double val);
Scalar cv_mat_mean(Mat m);
bool cv_mat_lut(Mat src, Mat lut, Mat dst);

int cv_mat_channels(Mat m);
int cv_mat_depth(Mat m);
int cv_mat_type(Mat m);

size_t cv_mat_step(Mat m);
bool cv_mat_is_continuous(Mat m);
size_t cv_mat_total(Mat m);

int cv_mat_dims(Mat m);
void cv_mat_size(Mat m, int * size);
int cv_mat_rows(Mat m);
int cv_mat_cols(Mat m);

Mat cv_mat_reshape(Mat m, int cn, int dims, int * sizes);

int32_t cv_mat_get_int(Mat m, const int *idx);
double cv_mat_get_double(Mat m, const int * idx);
void * cv_mat_get_ptr(Mat m, const int * idx);

bool cv_mat_set_int(Mat m, const int *idx, int n_idx, int val);
bool cv_mat_set_double(Mat m, const int *idx, int n_idx, double val);

int64 cv_get_tick_count();
double cv_get_tick_frequency();

#ifdef __cplusplus
}
#endif

#endif //CVC_CORE_H
