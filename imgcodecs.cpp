#include "imgcodecs.h"

Mat cv_imread(const char * filename, int flags) {
    try {
        cv::Mat img = cv::imread(filename, flags);
        if (img.empty()) {
            cv_set_error("Can't read image.");
            return nullptr;
        } else {
            return new cv::Mat(img);
        }
    }
    catch_exceptions(nullptr);
}

Mat cv_imdecode(Buffer buf, int flags) {
    try {
        cv::Mat img = cv::imdecode(*buf, flags);
        if (img.empty()) {
            cv_set_error("Can't decode image.");
            return nullptr;
        } else {
            return new cv::Mat(img);
        }
    }
    catch_exceptions(nullptr);
}

bool cv_imwrite(const char* filename, Mat img, Ints params) {
    try {
        auto result = cv::imwrite(filename, *img, *params);
        if (!result) {
            cv_set_error("Can't write image.");
        }
        return result;
    }
    catch_exceptions(false);
}

Buffer cv_imencode(const char * file_ext, Mat img, Ints params) {
    try {
        std::vector<uchar> buffer;
        bool result = cv::imencode(file_ext, *img, buffer, *params);
        if (result) {
            return new std::vector<uchar>(buffer);
        } else {
            cv_set_error("Can't encode image.");
            return nullptr;
        }
    }
    catch_exceptions(nullptr);
}

