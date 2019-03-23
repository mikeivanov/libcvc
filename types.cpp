// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#include "types.h"
#include <string.h>

__thread char _cv_error_message[1024];
__thread error_t  _cv_error_code = NO_ERROR;

const error_t cv_get_error_code() { return _cv_error_code; }
const char * cv_get_error_message() { return _cv_error_message; }

error_t cv_set_error(error_t code, const char * msg) {
    _cv_error_code = code;
    strncpy(_cv_error_message, msg, 1024);
    return code;
}

void cv_clear_error() {
    _cv_error_message[0] = 0;
    _cv_error_code = NO_ERROR;
}

// Strings ---------------------

error_t cv_strings_new(Strings * out_new_strings) {
    try_
        *out_new_strings = new std::vector<cv::String>();
    end_
}

error_t cv_strings_new_with_data(int count, const char ** data, Strings * out_new_strings) {
    try_
        *out_new_strings =  new std::vector<cv::String>(data, data + count);
    end_
}

error_t cv_strings_add(Strings self, char * string) {
    try_
        self->emplace_back(string);
    end_
}

error_t cv_strings_free(Strings self) {
    try_
        delete self;
    end_
}

error_t cv_strings_count(Strings self, size_t * out_count) {
    try_
        *out_count = self->size();
    end_
}

error_t cv_strings_get(Strings self, int idx, const char ** out_string ) {
    try_
        *out_string = (*self)[idx].c_str();
    end_
}

// Buffer ----------------------------------

error_t cv_buffer_new(Buffer * out_new_buffer) {
    try_
        *out_new_buffer = new std::vector<uchar>();
    end_
}

error_t cv_buffer_new_with_data(int size, uchar * data, Buffer * out_new_buffer) {
    try_
        *out_new_buffer = new std::vector<uchar>(data, data + size);
    end_
}

error_t cv_buffer_free(Buffer self) {
    try_
        delete self;
    end_
}

error_t cv_buffer_size(Buffer self, size_t * out_size) {
    try_
        *out_size = self->size();
    end_
}

error_t cv_buffer_data(Buffer self, const uchar ** data) {
    try_
        *data = self->data();
    end_
}

// Floats ------------------------------------

error_t cv_floats_new(Floats * out_new_floats) {
    try_
        *out_new_floats = new std::vector<float>();
    end_
}

error_t cv_float_new_with_data(int size, float * data, Floats * out_new_floats) {
    try_
        *out_new_floats = new std::vector<float>(data, data + size);
    end_
}

error_t cv_floats_free(Floats self) {
    try_
        delete self;
    end_
}

error_t cv_floats_count(Floats self, size_t * out_count) {
    try_
        *out_count = self->size();
    end_
}

error_t cv_floats_add(Floats self, float val) {
    try_
        self->emplace_back(val);
    end_
}

error_t cv_floats_get(Floats self, int idx, float * out_value) {
    try_
        *out_value = (*self)[idx];
    end_
}

error_t cv_floats_data(Floats self, float ** out_data) {
    try_
        *out_data = self->data();
    end_
}

// Doubles -----------------------------------

error_t cv_doubles_new(Doubles * out_new_doubles) {
    try_
        *out_new_doubles = new std::vector<double>();
    end_
}

error_t cv_doubles_new_with_data(int size, const double * data, Doubles * out_new_doubles) {
    try_
        *out_new_doubles = new std::vector<double>(data, data + size);
    end_
}

error_t cv_doubles_free(Doubles self) {
    try_
        delete self;
    end_
}

error_t cv_doubles_count(Doubles self, size_t * out_size) {
    try_
        *out_size = self->size();
    end_
}

error_t cv_doubles_add(Doubles self, double val) {
    try_
        self->emplace_back(val);
    end_
}

error_t cv_doubles_get(Doubles self, int idx, double * out_value) {
    try_
        *out_value = (*self)[idx];
    end_
}

error_t cv_doubles_data(Doubles self, double ** out_data) {
    try_
        *out_data = self->data();
    end_
}

// Ints ----------------------

error_t cv_ints_new(Ints * out_new_ints) {
    try_
        *out_new_ints = new std::vector<int>();
    end_
}

error_t cv_ints_new_with_data(int count, const int * data, Ints * out_new_ints) {
    try_
        *out_new_ints = new std::vector<int>(data, data + count);
    end_
}

error_t cv_ints_free(Ints self) {
    try_
        delete self;
    end_
}

error_t cv_ints_count(Ints self, size_t * out_size) {
    try_
        *out_size = self->size();
    end_
}

error_t cv_ints_add(Ints self, int val) {
    try_
        self->emplace_back(val);
    end_
}

error_t cv_ints_get(Ints self, int idx, int * out_value) {
    try_
        *out_value = (*self)[idx];
    end_
}

error_t cv_ints_data(Ints self, int ** out_data) {
    try_
        *out_data = self->data();
    end_
}

// Scalar ---------------------

error_t cv_scalar_new(double a, double b, double c, double d, Scalar * out_scalar) {
    try_
        *out_scalar = new cv::Scalar(a, b, c, d);
    end_
}

error_t cv_scalar_copy(Scalar self, Scalar * out_scalar) {
    try_
        *out_scalar = new cv::Scalar(*self);
    end_
}

error_t cv_scalar_free(Scalar self) {
    try_
        delete self;
    end_
}

error_t cv_scalar_data(Scalar self, double ** out_data) {
    try_
        *out_data = self->val;
    end_
}

// ------------------------------

error_t cv_size_new(float w, float h, Size * out_new_size) {
    try_
        *out_new_size = new cv::Size2f(w, h);
    end_
}

error_t cv_size_copy(Size self, Size * out_new_size) {
    try_
        *out_new_size = new cv::Size2f(*self);
    end_
}

error_t cv_size_free(Size self) {
    try_
        delete self;
    end_
}

error_t cv_size_width(Size self, float * out_width) {
    try_
        *out_width = self->width;
    end_
}

error_t cv_size_height(Size self, float * out_height) {
    try_
        *out_height = self->height;
    end_
}

// ------------------------------

error_t cv_point_new(float x, float y, Point * out_new_point) {
    try_
        *out_new_point = new cv::Point2f(x, y);
    end_
}

error_t cv_point_copy(Point self, Point * out_new_point) {
    try_
        *out_new_point = new cv::Point2f(*self);
    end_
}

error_t cv_point_free(Point self) {
    try_
        delete self;
    end_
}

error_t cv_point_x(Point self, float * out_x) {
    try_
        *out_x = self->x;
    end_
}

error_t cv_point_y(Point self, float * out_y) {
    try_
        *out_y = self->y;
    end_
}

error_t cv_points_new(Points * out_new_points) {
    try_
        *out_new_points = new std::vector<cv::Point2f>();
    end_
}

error_t cv_points_new_with_data(int count, Point * data, Points * out_new_points) {
    try_
        auto vec = new std::vector<cv::Point2f>();
        for (int i = 0; i < count; i++) {
            vec->emplace_back(*(data[i]));
        }
        *out_new_points = vec;
    end_
}

error_t cv_points_add(Points self, Point point) {
    try_
        self->emplace_back(*point);
    end_
}

error_t cv_points_free(Points self) {
    try_
        delete self;
    end_
}

error_t cv_points_count(Points self, size_t * out_count) {
    try_
        *out_count = self->size();
    end_
}

error_t cv_points_get(Points self, int idx, Point * out_point) {
    try_
         *out_point = &(self->at((size_t) idx));
    end_
}

// Rect ------------------------------

error_t cv_rect_new(float x, float y, float w, float h, Rect * out_new_rect) {
    try_
        *out_new_rect = new cv::Rect2f(x, y, w, h);
    end_
}

error_t cv_rect_copy(Rect self, Rect * out_new_rect) {
    try_
        *out_new_rect = new cv::Rect2f(*self);
    end_
}

error_t cv_rect_free(Rect self) {
    try_
        delete self;
    end_
}

error_t cv_rect_x(Rect self, float * out_x) {
    try_
        *out_x = self->x;
    end_
}

error_t cv_rect_y(Rect self, float * out_y) {
    try_
        *out_y = self->y;
    end_
}

error_t cv_rect_width(Rect self, float * out_width) {
    try_
        *out_width = self->width;
    end_
}

error_t cv_rect_height(Rect self, float * out_height) {
    try_
        *out_height = self->height;
    end_
}

// RotatedRect ----------------

error_t cv_rotated_rect_new(float x, float y, float width, float height, float angle, RotatedRect * out_new_rr) {
    try_
        *out_new_rr = new cv::RotatedRect(cv::Point2f(x, y), cv::Size2f(width, height), angle);
    end_
}

error_t cv_rotated_rect_copy(RotatedRect self, RotatedRect * out_new_rr) {
    try_
        *out_new_rr = new cv::RotatedRect(*self);
    end_
}

error_t cv_rotated_rect_free(RotatedRect self) {
    try_
        delete self;
    end_
}

error_t cv_rotated_rect_x(RotatedRect self, float * out_x) {
    try_
        *out_x = self->center.x;
    end_
}

error_t cv_rotated_rect_y(RotatedRect self, float * out_y) {
    try_
        *out_y = self->center.y;
    end_
}

error_t cv_rotated_rect_width(RotatedRect self, float * out_width) {
    try_
        *out_width =  self->size.width;
    end_
}

error_t cv_rotated_rect_height(RotatedRect self, float * out_height) {
    try_
        *out_height = self->size.height;
    end_
}

error_t cv_rotated_rect_angle(RotatedRect self, float * out_angle) {
    try_
        *out_angle = self->angle;
    end_
}

error_t cv_rotated_rect_points(RotatedRect self, Points * out_new_points) {
    try_
        cv::Point2f pts[4];
        self->points(pts);
        *out_new_points = new std::vector<cv::Point2f>(pts, pts + 4);
    end_
}

// RotatedRects (vector)

error_t cv_rotated_rects_new(RotatedRects * out_new_rr) {
    try_
        *out_new_rr = new std::vector<cv::RotatedRect>();
    end_
}

error_t cv_rotated_rects_new_with_data(int count, const RotatedRect * data, RotatedRects * out_new_rr) {
    try_
        auto vec = new std::vector<cv::RotatedRect>();
        for (int i = 0; i < count; i++) {
            vec->emplace_back(*(data[i]));
        }
        *out_new_rr = vec;
    end_
}

error_t cv_rotated_rects_add(RotatedRects self, RotatedRect rect) {
    try_
        self->emplace_back(*rect);
    end_
}

error_t cv_rotated_rects_free(RotatedRects self) {
    try_
        delete self;
    end_
}

error_t cv_rotated_rects_count(RotatedRects self, size_t * out_count) {
    try_
        *out_count = self->size();
    end_
}

error_t cv_rotated_rects_get(RotatedRects self, int idx, RotatedRect * out_ref_rect) {
    try_
        *out_ref_rect = &(self->at((size_t) idx));
    end_
}

