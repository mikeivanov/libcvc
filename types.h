#ifndef CVC_TYPES_H
#define CVC_TYPES_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>

#define catch_exceptions(x) \
    catch(cv::Exception &ex) { cv_set_error(ex.msg.c_str()); return x; } \
    catch(std::exception &ex) { cv_set_error(ex.what()); return x; } \
    catch(...) { cv_set_error("Unknown exception"); return x; }

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
typedef void * Bytes;
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

const char * cv_get_error();
void cv_set_error(const char * msg);
void cv_clear_error();

Buffer cv_buffer_new();
Buffer cv_buffer_new_with_data(int size, const uchar * data);
void cv_buffer_free(Buffer self);
int cv_buffer_size(Buffer self);
const uchar * cv_buffer_data(Buffer self);

Strings cv_strings_new();
Strings cv_strings_new_with_data(int count, char const ** strings);
Strings cv_strings_add(Strings self, char * string);
void cv_strings_free(Strings self);
int cv_strings_count(Strings self);
const char * cv_strings_get(Strings self, int i);

Ints cv_ints_new();
Ints cv_ints_new_with_data(int count, const int * data);
void cv_ints_free(Ints self);
int cv_ints_count(Ints self);
Ints cv_ints_add(Ints self, int val);
int cv_ints_get(Ints self, int i);
int * cv_ints_data(Ints self);

Floats cv_floats_new();
Floats cv_floats_new_with_data(int size, const float * data);
void cv_floats_free(Floats self);
int cv_floats_count(Floats self);
Floats cv_floats_add(Floats self, float val);
float cv_floats_get(Floats self, int i);
float * cv_floats_data(Floats self);

Doubles cv_doubles_new();
Doubles cv_doubles_new_with_data(int size, const double * data);
void cv_doubles_free(Doubles self);
int cv_doubles_count(Doubles self);
Doubles cv_doubles_add(Doubles self, double val);
double cv_doubles_get(Doubles self, int i);
double * cv_doubles_data(Doubles self);

Size cv_size_new(float w, float h);
Size cv_size_copy(Size self);
void cv_size_free(Size self);
float cv_size_width(Size self);
float cv_size_height(Size self);

Scalar cv_scalar_new(double a, double b, double c, double d);
Scalar cv_scalar_copy(Scalar self);
void cv_scalar_free(Scalar self);
double * cv_scalar_values(Scalar self);

Point cv_point_new(float x, float y);
Point cv_point_copy(Point self);
void cv_point_free(Point self);
float cv_point_x(Point self);
float cv_point_y(Point self);

Points cv_points_new();
Points cv_points_new_with_data(int count, Point * data);
Points cv_points_add(Points self, Point point);
void cv_points_free(Points self);
int cv_points_count(Points self);
Point cv_points_get(Points self, int idx);

Rect cv_rect_new(float x, float y, float w, float h);
Rect cv_rect_copy(Rect self);
void cv_rect_free(Rect self);
float cv_rect_x(Rect self);
float cv_rect_y(Rect self);
float cv_rect_width(Rect self);
float cv_rect_height(Rect self);

RotatedRect cv_rotated_rect_new(float x, float y, float width, float height, float angle);
RotatedRect cv_rotated_rect_copy(RotatedRect self);
void cv_rotated_rect_free(RotatedRect self);
float cv_rotated_rect_x(RotatedRect self);
float cv_rotated_rect_y(RotatedRect self);
float cv_rotated_rect_width(RotatedRect self);
float cv_rotated_rect_height(RotatedRect self);
float cv_rotated_rect_angle(RotatedRect self);

RotatedRects cv_rotated_rects_new();
RotatedRects cv_rotated_rects_new_with_data(int count, const RotatedRect * data);
RotatedRects cv_rotated_rects_add(RotatedRects self, RotatedRect rect);
void cv_rotated_rects_free(RotatedRects self);
int cv_rotated_rects_count(RotatedRects self);
RotatedRect cv_rotated_rects_get(RotatedRects self, int idx);

#ifdef __cplusplus
}
#endif

#endif //CVC_TYPES_H
