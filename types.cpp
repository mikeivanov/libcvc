#include "types.h"
#include <string.h>

__thread char _cv_error[1024];

const char * cv_get_error() { return _cv_error; }

void cv_set_error(const char * msg) {
    strncpy(_cv_error, msg, 1024);
}

void cv_clear_error() {
    _cv_error[0] = 0;
}

Strings cv_strings_new() {
    return new std::vector<cv::String>();
}

Strings cv_strings_new_with_data(int count, const char ** data) {
    return new std::vector<cv::String>(data, data + count);
}

Strings cv_strings_add(Strings self, char * string) {
    self->emplace_back(string);
    return self;
}

void cv_strings_free(Strings self) {
    delete self;
}

int cv_strings_count(Strings self) {
    return (int) self->size();
}

const char * cv_strings_get(Strings self, int idx) {
    return (*self)[idx].c_str();
}

//

Buffer cv_buffer_new() {
    return new std::vector<uchar>();
}

Buffer cv_buffer_new_with_data(int size, uchar * data) {
    return new std::vector<uchar>(data, data + size);
}

void cv_buffer_free(Buffer self) {
    delete self;
}

int cv_buffer_size(Buffer self) {
    return (int) self->size();
}

const uchar * cv_buffer_data(Buffer self) {
    return self->data();
}

//

Floats cv_floats_new() {
    return new std::vector<float>();
}

Floats cv_float_new_with_data(int size, float * data) {
    return new std::vector<float>(data, data + size);
}

void cv_floats_free(Floats self) {
    delete self;
}

int cv_floats_count(Floats self) {
    return (int) self->size();
}

Floats cv_floats_add(Floats self, float val) {
    self->emplace_back(val);
    return self;
}

float cv_floats_get(Floats self, int idx) {
    return (*self)[idx];
}

float * cv_floats_data(Floats self) {
    return self->data();
}

//

Doubles cv_doubles_new() {
    return new std::vector<double>();
}

Doubles cv_doubles_new_with_data(int size, const double * data) {
    return new std::vector<double>(data, data + size);
}

void cv_doubles_free(Doubles self) {
    delete self;
}

int cv_doubles_count(Doubles self) {
    return (int) self->size();
}

Doubles cv_doubles_add(Doubles self, double val) {
    self->emplace_back(val);
    return self;
}

double cv_doubles_get(Doubles self, int idx) {
    return (*self)[idx];
}

double * cv_doubles_data(Doubles self) {
    return self->data();
}

//

Ints cv_ints_new() {
    return new std::vector<int>();
}

Ints cv_ints_new_with_data(int count, const int * data) {
    return new std::vector<int>(data, data + count);
}

void cv_ints_free(Ints self) {
    delete self;
}

int cv_ints_count(Ints self) {
    return (int) self->size();
}

Ints cv_ints_add(Ints self, int val) {
    self->emplace_back(val);
    return self;
}

int cv_ints_get(Ints self, int idx) {
    return (*self)[idx];
}

int * cv_ints_data(Ints self) {
    return self->data();
}

// ---------------------

Scalar cv_scalar_new(double a, double b, double c, double d) {
    return new cv::Scalar(a, b, c, d);
}

Scalar cv_scalar_copy(Scalar self) {
    return new cv::Scalar(*self);
}

void cv_scalar_free(Scalar self) {
    delete self;
}

double * cv_scalar_values(Scalar self) {
    return self->val;
}

// ------------------------------

Size cv_size_new(float w, float h) {
    return new cv::Size2f(w, h);
}

Size cv_size_copy(Size self) {
    return new cv::Size2f(*self);
}

void cv_size_free(Size self) {
    delete self;
}

float cv_size_width(Size self) {
    return self->width;
}

float cv_size_height(Size self) {
    return self->height;
}

// ------------------------------

Point cv_point_new(float x, float y) {
    return new cv::Point2f(x, y);
}

Point cv_point_copy(Point self) {
    return new cv::Point2f(*self);
}

void cv_point_free(Point self) {
    delete self;
}

float cv_point_x(Point self) {
    return self->x;
}

float cv_point_y(Point self) {
    return self->y;
}

Points cv_points_new() {
    return new std::vector<cv::Point2f>();
}

Points cv_points_new_with_data(int count, Point * data) {
    auto vec = new std::vector<cv::Point2f>();
    for (int i = 0; i < count; i++) {
        vec->emplace_back(*(data[i]));
    }
    return vec;
}

Points cv_points_add(Points self, Point point) {
    self->emplace_back(*point);
    return self;
}

void cv_points_free(Points self) {
    delete self;
}

int cv_points_count(Points self) {
    return (int) self->size();
}

Point cv_points_get(Points self, int idx) {
    return &(self->at((size_t) idx));
}


// ------------------------------

Rect cv_rect_new(float x, float y, float w, float h) {
    return new cv::Rect2f(x, y, w, h);
}

Rect cv_rect_copy(Rect self) {
    return new cv::Rect2f(*self);
}

void cv_rect_free(Rect self) {
    delete self;
}

float cv_rect_x(Rect self) {
    return self->x;
}

float cv_rect_y(Rect self) {
    return self->y;
}

float cv_rect_width(Rect self) {
    return self->width;
}

float cv_rect_height(Rect self) {
    return self->height;
}

// ----------------

RotatedRect cv_rotated_rect_new(float x, float y, float width, float height, float angle) {
    return new cv::RotatedRect(cv::Point2f(x, y), cv::Size2f(width, height), angle);
}

RotatedRect cv_rotated_rect_copy(RotatedRect self) {
    return new cv::RotatedRect(*self);
}

void cv_rotated_rect_free(RotatedRect self) {
    delete self;
}

float cv_rotated_rect_x(RotatedRect self) {
    return self->center.x;
}

float cv_rotated_rect_y(RotatedRect self) {
    return self->center.y;
}

float cv_rotated_rect_width(RotatedRect self) {
    return self->size.width;
}

float cv_rotated_rect_height(RotatedRect self) {
    return self->size.height;
}

float cv_rotated_rect_angle(RotatedRect self) {
    return self->angle;
}

Points cv_rotated_rect_points(RotatedRect self) {
    cv::Point2f pts[4];
    self->points(pts);
    return new std::vector<cv::Point2f>(pts, pts + 4);
}

// RotatedRects (vector)

RotatedRects cv_rotated_rects_new() {
    return new std::vector<cv::RotatedRect>();
}

RotatedRects cv_rotated_rects_new_with_data(int count, const RotatedRect * data) {
    auto vec = new std::vector<cv::RotatedRect>();
    for (int i = 0; i < count; i++) {
        vec->emplace_back(*(data[i]));
    }
    return vec;
}

RotatedRects cv_rotated_rects_add(RotatedRects self, RotatedRect rect) {
    self->emplace_back(*rect);
    return self;
}

void cv_rotated_rects_free(RotatedRects self) {
    delete self;
}

int cv_rotated_rects_count(RotatedRects self) {
    return (int) self->size();
}

RotatedRect cv_rotated_rects_get(RotatedRects self, int idx) {
    return &(self->at((size_t) idx));
}

