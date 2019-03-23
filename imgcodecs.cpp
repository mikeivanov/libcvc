// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#include "imgcodecs.h"

error_t cv_imread(const char * filename, int flags, Mat out_img) {
    try_
        cv::Mat img = cv::imread(filename, flags);
        if (img.empty()) {
            return cv_set_error(OTHER_ERROR, "Cannot read image");
        }
        out_img->operator=(img);
    end_
}

error_t cv_imread_multi(const char * filename, Mats mats, int flags) {
    try_
        auto ok = imreadmulti(filename, *mats, flags);
        if (!ok) {
            return cv_set_error(OTHER_ERROR, "Cannot read image");
        }
    end_
}

error_t cv_imdecode(Buffer buf, int flags, Mat out_img) {
    try_
        cv::imdecode(*buf, flags, out_img);
        if (out_img->empty()) {
            return cv_set_error(OTHER_ERROR, "Cannot decode image");
        }
    end_
}

error_t cv_imwrite(const char* filename, Mat img, Ints params) {
    try_
        auto ok = cv::imwrite(filename, *img, *params);
        if (!ok) {
            return cv_set_error(OTHER_ERROR, "Cannot write image");
        }
    end_
}

error_t cv_imencode(const char * file_ext, Mat img, Ints params, Buffer out_buffer) {
    try_
        std::vector<uchar> buffer;
        auto ok = cv::imencode(file_ext, *img, buffer, *params);
        if (!ok) {
            return cv_set_error(OTHER_ERROR, "Cannot encode image");
        }
        out_buffer->operator=(buffer);
    end_
}

error_t cv_have_image_reader(const char * filename, bool * out_result) {
    try_
        *out_result = cv::haveImageReader(filename);
    end_
}

error_t cv_have_image_writer(const char * filename, bool * out_result) {
    try_
        *out_result = cv::haveImageWriter(filename);
    end_
}
