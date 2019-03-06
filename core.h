#ifndef CVC_CORE_H
#define CVC_CORE_H

#include <stdint.h>
#include <stdbool.h>

#include "types.h"

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#else
#define CV_8U   0
#define CV_8S   1
#define CV_16U  2
#define CV_16S  3
#define CV_32S  4
#define CV_32F  5
#define CV_64F  6
#define CV_16F  7
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
bool cv_mat_copy_to_with_mask(Mat m, Mat dst, Mat mask);
bool cv_mat_convert_to(Mat self, Mat dst, int type, double alpha, double beta);
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
Ints cv_mat_size(Mat self);
int cv_mat_rows(Mat m);
int cv_mat_cols(Mat m);

Mat cv_mat_reshape(Mat m, int cn, Ints shape);

int32_t cv_mat_get_int(Mat m, const int * idx);
double cv_mat_get_double(Mat m, const int * idx);
void * cv_mat_get_ptr(Mat m, const int * idx);

bool cv_mat_set_int(Mat m, const int * idx, int val);
bool cv_mat_set_double(Mat m, const int * idx, double val);

int64_t cv_get_tick_count();
double cv_get_tick_frequency();

#ifdef __cplusplus
}
#endif

#endif //CVC_CORE_H
