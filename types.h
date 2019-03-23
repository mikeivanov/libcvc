// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#ifndef CVC_TYPES_H
#define CVC_TYPES_H

#include <stdint.h>
#include <stdbool.h>

enum CvError {
    NO_ERROR = 0,
    CV_ERROR = -1,
    STD_ERROR = -2,
    UNKNOWN_ERROR = -3,
    OTHER_ERROR = 1
};

#ifdef __cplusplus
#include <opencv2/opencv.hpp>

#define catch_exceptions(x) \
    catch(cv::Exception &ex) { cv_set_error(CV_ERROR, ex.msg.c_str()); return x; } \
    catch(std::exception &ex) { cv_set_error(STD_ERROR, ex.what()); return x; } \
    catch(...) { cv_set_error(UNKNOWN_ERROR, "Unknown exception"); return x; }

#define OK NO_ERROR
#define try_ try {
#define end_ return OK; } \
    catch(cv::Exception &ex) { return cv_set_error(CV_ERROR, ex.msg.c_str()); } \
    catch(std::exception &ex) { return cv_set_error(OTHER_ERROR, ex.what()); } \
    catch(...) { return cv_set_error(UNKNOWN_ERROR, "Unknown exception"); }

extern "C" {
typedef std::vector<uchar> * Buffer;
typedef std::vector<int> * Ints;
typedef std::vector<float> * Floats;
typedef std::vector<double> * Doubles;
typedef std::vector<cv::String> * Strings;
typedef cv::Scalar * Scalar;
typedef cv::Size2f * Size;
typedef cv::Point2f * Point;
typedef std::vector<cv::Point2f> * Points;
typedef cv::Rect2f * Rect;
typedef cv::RotatedRect * RotatedRect;
typedef std::vector<cv::RotatedRect> * RotatedRects;
#else
typedef void * Buffer;
typedef void * Ints;
typedef void * Floats;
typedef void * Doubles;
typedef void * Strings;
typedef void * Scalar;
typedef void * Size;
typedef void * Point;
typedef void * Points;
typedef void * Rect;
typedef void * RotatedRect;
typedef void * RotatedRects;
#endif

const char * cv_get_error_message();
const error_t cv_get_error_code();
error_t cv_set_error(error_t code, const char * msg);
void cv_clear_error();

// Strings ---------------------

error_t cv_strings_new(Strings * out_new_strings);
error_t cv_strings_new_with_data(int count, const char ** data, Strings * out_new_strings);
error_t cv_strings_add(Strings self, char * string);
error_t cv_strings_free(Strings self);
error_t cv_strings_count(Strings self, size_t * out_count);
error_t cv_strings_get(Strings self, int idx, const char ** out_string );

// Buffer ----------------------------------

error_t cv_buffer_new(Buffer * out_new_buffer);
error_t cv_buffer_new_with_data(int size, uchar * data, Buffer * out_new_buffer);
error_t cv_buffer_free(Buffer self);
error_t cv_buffer_size(Buffer self, size_t * out_size);
error_t cv_buffer_data(Buffer self, const uchar ** data);

// Floats ------------------------------------

error_t cv_floats_new(Floats * out_new_floats);
error_t cv_float_new_with_data(int size, float * data, Floats * out_new_floats);
error_t cv_floats_free(Floats self);
error_t cv_floats_count(Floats self, size_t * out_count);
error_t cv_floats_add(Floats self, float val);
error_t cv_floats_get(Floats self, int idx, float * out_value);
error_t cv_floats_data(Floats self, float ** out_data);

// Doubles -----------------------------------

error_t cv_doubles_new(Doubles * out_new_doubles);
error_t cv_doubles_new_with_data(int size, const double * data, Doubles * out_new_doubles);
error_t cv_doubles_free(Doubles self);
error_t cv_doubles_count(Doubles self, size_t * out_size);
error_t cv_doubles_add(Doubles self, double val);
error_t cv_doubles_get(Doubles self, int idx, double * out_value);
error_t cv_doubles_data(Doubles self, double ** out_data);

// Ints ----------------------

error_t cv_ints_new(Ints * out_new_ints);
error_t cv_ints_new_with_data(int count, const int * data, Ints * out_new_ints);
error_t cv_ints_free(Ints self);
error_t cv_ints_count(Ints self, size_t * out_size);
error_t cv_ints_add(Ints self, int val);
error_t cv_ints_get(Ints self, int idx, int * out_value);
error_t cv_ints_data(Ints self, int ** out_data);

// Scalar ---------------------

error_t cv_scalar_new(double a, double b, double c, double d, Scalar * out_scalar);
error_t cv_scalar_copy(Scalar self, Scalar * out_scalar);
error_t cv_scalar_free(Scalar self);
error_t cv_scalar_data(Scalar self, double ** out_data);

// ------------------------------

error_t cv_size_new(float w, float h, Size * out_new_size);
error_t cv_size_copy(Size self, Size * out_new_size);
error_t cv_size_free(Size self);
error_t cv_size_width(Size self, float * out_width);
error_t cv_size_height(Size self, float * out_height);

// Point ------------------------------

error_t cv_point_new(float x, float y, Point * out_new_point);
error_t cv_point_copy(Point self, Point * out_new_point);
error_t cv_point_free(Point self);
error_t cv_point_x(Point self, float * out_x);
error_t cv_point_y(Point self, float * out_y);
error_t cv_points_new(Points * out_new_points);
error_t cv_points_new_with_data(int count, Point * data, Points * out_new_points);
error_t cv_points_add(Points self, Point point);
error_t cv_points_free(Points self);
error_t cv_points_count(Points self, size_t * out_count);
error_t cv_points_get(Points self, int idx, Point * out_point);

// Rect ------------------------------

error_t cv_rect_new(float x, float y, float w, float h, Rect * out_new_rect);
error_t cv_rect_copy(Rect self, Rect * out_new_rect);
error_t cv_rect_free(Rect self);
error_t cv_rect_x(Rect self, float * out_x);
error_t cv_rect_y(Rect self, float * out_y);
error_t cv_rect_width(Rect self, float * out_width);
error_t cv_rect_height(Rect self, float * out_height);

// RotatedRect ----------------

error_t cv_rotated_rect_new(float x, float y, float width, float height, float angle, RotatedRect * out_new_rr);
error_t cv_rotated_rect_copy(RotatedRect self, RotatedRect * out_new_rr);
error_t cv_rotated_rect_free(RotatedRect self);
error_t cv_rotated_rect_x(RotatedRect self, float * out_x);
error_t cv_rotated_rect_y(RotatedRect self, float * out_y);
error_t cv_rotated_rect_width(RotatedRect self, float * out_width);
error_t cv_rotated_rect_height(RotatedRect self, float * out_height);
error_t cv_rotated_rect_angle(RotatedRect self, float * out_angle);
error_t cv_rotated_rect_points(RotatedRect self, Points * out_new_points);
error_t cv_rotated_rects_new(RotatedRects * out_new_rr);
error_t cv_rotated_rects_new_with_data(int count, const RotatedRect * data, RotatedRects * out_new_rr);
error_t cv_rotated_rects_add(RotatedRects self, RotatedRect rect);
error_t cv_rotated_rects_free(RotatedRects self);
error_t cv_rotated_rects_count(RotatedRects self, size_t * out_count);
error_t cv_rotated_rects_get(RotatedRects self, int idx, RotatedRect * out_ref_rect);

#ifdef __cplusplus
}
#endif

#endif //CVC_TYPES_H
