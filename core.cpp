// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#include "core.h"
#include <string.h>

error_t cv_mats_new(Mats * out_new_mats) {
    try_
        *out_new_mats = new std::vector<cv::Mat>;
    end_
}

error_t cv_mats_new_copy(Mats mats, Mats * out_new_mats) {
    try_
        *out_new_mats = new std::vector<cv::Mat>(*mats);
    end_
}

error_t cv_mats_new_with_data(int count, const Mat * data, Mats * out_new_mats) {
    try_
        auto vec = new std::vector<cv::Mat>();
        for (int i = 0; i < count; i++) {
            vec->emplace_back(*(data[i]));
        }
        *out_new_mats = vec;
    end_
}

error_t cv_mats_add(Mats self, Mat mat) {
    try_
        self->emplace_back(*mat);
    end_
}

error_t cv_mats_free(Mats self) {
    try_
        delete self;
    end_
}

error_t cv_mats_count(Mats self, int * out_count) {
    try_
        *out_count = (int) self->size();
    end_
}

error_t cv_mats_get(Mats self, int i, Mat * out_mat_ref) {
    try_
         *out_mat_ref = &(self->at((size_t) i));
    end_
}

// ---------------------

error_t cv_make_type(int depth, int channels, int * out_type) {
    try_
        *out_type = CV_MAKETYPE(depth, channels);
    end_
}

error_t cv_type_depth(int type, int * out_depth) {
    try_
        *out_depth = CV_MAT_DEPTH(type);
    end_
}

error_t cv_type_channels(int type, int * out_channels) {
    try_
        *out_channels = type >> CV_CN_SHIFT;
    end_
}

// ----------------------

error_t cv_mat_new(Mat * out_new_mat) {
    try_
        *out_new_mat = new cv::Mat();
    end_
}

error_t cv_mat_new_copy(Mat self, Mat * out_new_mat) {
    try_
        *out_new_mat = new cv::Mat(*self);
    end_
}

error_t cv_mat_new_with_scalar(Ints shape, int type, Scalar scalar, Mat * out_new_mat) {
    try_
        *out_new_mat = new cv::Mat(*shape, type, *scalar);
    end_
}

error_t cv_mat_new_with_data(Ints shape, int type, void * data, Mat * out_new_mat) {
    try_
        *out_new_mat = new cv::Mat(*shape, type, data);
    end_
}

error_t cv_mat_new_with_roi(Mat source, Rect roi, Mat * out_new_mat) {
    try_
        *out_new_mat = new cv::Mat(*source, *roi);
    end_
}

error_t cv_mat_free(Mat self) {
    try_
        delete self;
    end_
}

error_t cv_mat_empty(Mat self, bool * out_value) {
    try_
        *out_value = self->empty();
    end_
}

error_t cv_mat_copy_to(Mat self, Mat dst) {
    try_
        self->copyTo(*dst);
    end_
}

error_t cv_mat_copy_to_with_mask(Mat self, Mat dst, Mat mask) {
    try_
        self->copyTo(*dst, *mask);
    end_
}

error_t cv_mat_convert_to(Mat self, Mat dst, int type, double alpha, double beta) {
    try_
        self->convertTo(*dst, type, alpha, beta);
    end_
}

error_t cv_mat_reshape(Mat self, int cn, Ints shape, Mat out_mat) {
    try_
        out_mat->operator=(self->reshape(cn, *shape));
    end_
}

error_t cv_mat_patch_nans(Mat self, double val) {
    try_
        cv::patchNaNs(*self, val);
    end_
}

error_t cv_mat_mean(Mat self, Scalar out_scalar) {
    try_
        out_scalar->operator=(cv::mean(*self));
    end_
}

error_t cv_mat_lut(Mat self, Mat lut, Mat dst) {
    try_
        cv::LUT(*self, *lut, *dst);
    end_
}

error_t cv_mat_rows(Mat self, int * out_rows) {
    try_
        *out_rows = self->rows;
    end_
}

error_t cv_mat_cols(Mat self, int * out_cols) {
    try_
        *out_cols = self->cols;
    end_
}

error_t cv_mat_channels(Mat self, int * out_channels) {
    try_
        *out_channels = self->channels();
    end_
}

error_t cv_mat_depth(Mat self, int * out_depth) {
    try_
        *out_depth = self->depth();
    end_
}

error_t cv_mat_type(Mat self, int * out_type) {
    try_
        *out_type = self->type();
    end_
}

error_t cv_mat_elem_size(Mat self, size_t * out_size) {
    try_
        *out_size = self->elemSize();
    end_
}

error_t cv_mat_step(Mat self, size_t * out_step) {
    try_
        *out_step = self->step;
    end_
}

error_t cv_mat_is_continuous(Mat self, bool * out_continuous) {
    try_
        *out_continuous = self->isContinuous();
    end_
}

error_t cv_mat_total(Mat self, size_t * out_total) {
    try_
        *out_total = self->total();
    end_
}

error_t cv_mat_dims(Mat self, size_t * out_dims) {
    try_
        *out_dims = self->dims;
    end_
}

error_t cv_mat_size(Mat self, Ints out_size) {
    try_
        auto n = (size_t) self->size.dims();
        const int * s = self->size;
        out_size->operator=(std::vector<int>(s, s + n));
    end_
}

error_t cv_mat_get_ptr(Mat m, const int * idx, void ** out_ptr) {
    try_
        switch (m->depth()) {
            case CV_8U:
                *out_ptr = m->ptr<uchar>(idx);
                break;
            case CV_8S:
                *out_ptr = m->ptr<schar>(idx);
                break;
            case CV_16U:
                *out_ptr = m->ptr<ushort>(idx);
                break;
            case CV_16S:
                *out_ptr = m->ptr<short>(idx);
                break;
            case CV_32S:
                *out_ptr = m->ptr<int>(idx);
                break;
            case CV_32F:
                *out_ptr = m->ptr<float>(idx);
                break;
            case CV_64F:
                *out_ptr = m->ptr<double>(idx);
                break;
            default:
                return cv_set_error(OTHER_ERROR, "Unsupported mat depth");
                break;
        }
    end_
}

error_t cv_get_tick_count(int64_t * out_count) {
    try_
        *out_count = cv::getTickCount();
    end_
}

error_t cv_get_tick_frequency(double * out_freq) {
    try_
        *out_freq = cv::getTickFrequency();
    end_
}

// array ops -------------------------------

error_t cv_extract_channel(Mat src, Mat dst, int coi) {
    try_
        cv::extractChannel(*src, *dst, coi);
    end_
}

error_t cv_merge(Mats channels, Mat out_mat) {
    try_
        cv::merge(*channels, *out_mat);
    end_
}

// matx ops ------------------------

error_t cv_mat_add_mat(Mat mat, Mat addendum) {
    try_
        (*mat) += *addendum;
    end_
}

error_t cv_mat_add_scalar(Mat mat, Scalar addendum) {
    try_
        (*mat) += *addendum;
    end_
}

error_t cv_mat_mul_const(Mat mat, double multiplier) {
    try_
        (*mat) *= multiplier;
    end_
}

error_t cv_mat_dot(Mat self, Mat m, double * out) {
    try_
        *out = self->dot(*m);
    end_
}
