// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#ifndef CVC_DNN_H
#define CVC_DNN_H

#include <stdbool.h>
#include "core.h"

#ifdef __cplusplus

#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

typedef cv::dnn::Net * Net;
typedef cv::Ptr<cv::dnn::Layer> * Layer;

extern "C" {

#else

typedef void* Net;
typedef void* Layer;

#endif

extern CvEnum cv_dnn_backend_enum[];
extern CvEnum cv_dnn_target_enum[];

error_t cv_dnn_read_net(const char * model, const char * config, const char * framework, Net * out_net);
error_t cv_dnn_net_free(Net net);
error_t cv_dnn_net_empty(Net net, bool * out_value);
error_t cv_dnn_net_set_input(Net net, Mat blob, const char* name, double scale_factor, Scalar mean);
error_t cv_dnn_net_forward(Net net, const char * output_name, Mat out_result);
error_t cv_dnn_net_forward_layers(Net net, Strings layer_names, Mats out_result);
error_t cv_dnn_net_set_preferable_backend(Net net, int backend);
error_t cv_dnn_net_set_preferable_target(Net net, int target);
error_t cv_dnn_net_get_perf_profile(Net net, Doubles out_layers, int64_t * out_time);
error_t cv_dnn_blob_from_images(Mats images,
                                Mat out_blob,
                                double scale_factor,
                                Size size,
                                Scalar mean,
                                bool swap_rb,
                                bool crop,
                                int depth);
error_t cv_dnn_net_get_layer_names(Net net, Strings names);
error_t cv_dnn_net_get_layer_with_name(Net net, const char * layer_name, Layer * out_layer);
error_t cv_dnn_net_get_layer_with_id(Net net, int layer_id, Layer * out_layer);
error_t cv_dnn_layer_blobs(Layer layer, Mats out_mats);
error_t cv_dnn_layer_add_blob(Layer layer, Mat blob);
error_t cv_dnn_layer_free(Layer layer);
error_t cv_dnn_layer_input_name_to_index(Layer layer, const char* name, int * out_index);
error_t cv_dnn_layer_output_name_to_index(Layer layer, const char* name, int * out_index);
error_t cv_dnn_layer_name(Layer layer, const char ** out_name);
error_t cv_dnn_layer_type(Layer layer, const char ** out_type);
error_t cv_dnn_nms_boxes(RotatedRects bboxes,
                         Floats scores,
                         float score_threshold,
                         float nms_threshold,
                         float eta,
                         int top_k,
                         Ints out_indices);

#ifdef __cplusplus
}
#endif

#endif // CVC_DNN_H
