// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#include "core.h"
#include <string.h>

Mats cv_mats_new() {
    return new std::vector<cv::Mat>;
}

Mats cv_mats_new_with_data(int count, const Mat * data) {
    auto vec = new std::vector<cv::Mat>();
    for (int i = 0; i < count; i++) {
        vec->emplace_back(*(data[i]));
    }
    return vec;
}

Mat cv_mats_copy(Mat self) {
    return new cv::Mat(*self);
}

Mats cv_mats_add(Mats self, Mat mat) {
    self->emplace_back(*mat);
    return self;
}

void cv_mats_free(Mats self) {
    delete self;
}

int cv_mats_count(Mats self) {
    return (int) self->size();
}

Mat cv_mats_get(Mats self, int i) {
    return &(self->at((size_t) i));
}

// ---------------------

int cv_make_type(int depth, int channels) {
    return CV_MAKETYPE(depth, channels);
}

int cv_type_depth(int type) {
    return CV_MAT_DEPTH(type);
}

int cv_type_channels(int type) {
    return type >> CV_CN_SHIFT;
}

// ----------------------

Mat cv_mat_new() {
    return new cv::Mat();
}

Mat cv_mat_new_with_scalar(Ints shape, int type, Scalar scalar) {
    try {
        return new cv::Mat(*shape, type, *scalar);
    }
    catch_exceptions(nullptr);
}

Mat cv_mat_new_with_data(Ints shape, int type, void * data) {
    try {
        return new cv::Mat(*shape, type, data);
    }
    catch_exceptions(nullptr);
}

Mat cv_mat_copy(Mat self) {
    try {
        return new cv::Mat(*self);
    }
    catch_exceptions(nullptr);
}

void cv_mat_free(Mat self) {
    delete self;
}

bool cv_mat_empty(Mat self) {
    return self->empty();
}

bool cv_mat_copy_to(Mat self, Mat dst) {
    try {
        self->copyTo(*dst);
        return true;
    }
    catch_exceptions(false);
}

bool cv_mat_copy_to_with_mask(Mat self, Mat dst, Mat mask) {
    try {
        self->copyTo(*dst, *mask);
        return true;
    }
    catch_exceptions(false);
}

bool cv_mat_convert_to(Mat self, Mat dst, int type, double alpha, double beta) {
    try {
        self->convertTo(*dst, type, alpha, beta);
        return true;
    }
    catch_exceptions(false);
}

Mat cv_mat_reshape(Mat self, int cn, Ints shape) {
    try {
        return new cv::Mat(self->reshape(cn, *shape));
    }
    catch_exceptions(nullptr);
}

void cv_mat_patch_nans(Mat self, double val) {
    cv::patchNaNs(*self, val);
}

Scalar cv_mat_mean(Mat self) {
    return new cv::Scalar(cv::mean(*self));
}

bool cv_mat_lut(Mat self, Mat lut, Mat dst) {
    try {
        cv::LUT(*self, *lut, *dst);
        return true;
    }
    catch_exceptions(false);
}

int cv_mat_rows(Mat self) {
    return self->rows;
}

int cv_mat_cols(Mat self) {
    return self->cols;
}

int cv_mat_channels(Mat self) {
    return self->channels();
}

int cv_mat_depth(Mat self) {
    return self->depth();
}

int cv_mat_type(Mat self) {
    return self->type();
}

size_t cv_mat_elem_size(Mat self) {
    return self->elemSize();
}

size_t cv_mat_step(Mat self) {
    return self->step;
}

bool cv_mat_is_continuous(Mat self) {
    return self->isContinuous();
}

size_t cv_mat_total(Mat self) {
    return self->total();
}

int cv_mat_dims(Mat self) {
    return self->dims;
}

Ints cv_mat_size(Mat self) {
    auto n = (size_t) self->size.dims();
    const int * s = self->size;
    return new std::vector<int>(s, s + n);
}

void * cv_mat_get_ptr(Mat m, const int * idx) {
    try {
        switch (m->depth()) {
            case CV_8U:
                return m->ptr<uchar>(idx);
            case CV_8S:
                return m->ptr<schar>(idx);
            case CV_16U:
                return m->ptr<ushort>(idx);
            case CV_16S:
                return m->ptr<short>(idx);
            case CV_32S:
                return m->ptr<int>(idx);
            case CV_32F:
                return m->ptr<float>(idx);
            case CV_64F:
                return m->ptr<double>(idx);
            default:
                assert(false);
        }
    }
    catch_exceptions(nullptr);
}

int64_t cv_get_tick_count() {
    return cv::getTickCount();
}

double cv_get_tick_frequency() {
    return cv::getTickFrequency();
}

// array ops -------------------------------

bool cv_extract_channel(Mat src, Mat dst, int coi) {
    try {
        cv::extractChannel(*src, *dst, coi);
        return true;
    }
    catch_exceptions(false);
}

Mat cv_merge(Mats channels) {
    try {
        auto mat = new cv::Mat();
        cv::merge(*channels, *mat);
        return mat;
    }
    catch_exceptions(nullptr);
}

// matx ops ------------------------

bool cv_mat_add_scalar(Mat mat, Scalar addendum) {
    try {
        (*mat) += *addendum;
        return true;
    }
    catch_exceptions(false);
}

bool cv_mat_mul_const(Mat mat, double multiplier) {
    try {
        (*mat) *= multiplier;
        return true;
    }
    catch_exceptions(false);
}

