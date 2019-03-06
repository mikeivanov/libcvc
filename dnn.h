#ifndef CVC_DNN_H
#define CVC_DNN_H

#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
extern "C" {
#endif

#include "core.h"

#ifdef __cplusplus
typedef cv::dnn::Net * Net;
typedef cv::Ptr<cv::dnn::Layer> * Layer;
#else
typedef void* Net;
typedef void* Layer;
#endif

Net cv_dnn_read_net(const char * model, const char * config, const char * framework);
void cv_dnn_net_free(Net net);
bool cv_dnn_net_empty(Net net);
bool cv_dnn_net_set_input(Net net, Mat blob, const char* name, double scale_factor, Scalar mean);

bool cv_dnn_net_forward(Net net, const char * output_name, Mat output_blob);
bool cv_dnn_net_forward_layers(Net net, Strings layer_names, Mats out_blobs);

void cv_dnn_net_set_preferable_backend(Net net, int backend);
void cv_dnn_net_set_preferable_target(Net net, int target);
int64_t cv_dnn_net_get_perf_profile(Net net, Doubles out_layers);

bool cv_dnn_blob_from_images(Mats images,
                             Mat out_blob,
                             double scale_factor,
                             Size size,
                             Scalar mean,
                             bool swap_rb,
                             bool crop,
                             int depth);

Strings cv_dnn_net_get_layer_names(Net net);
Layer cv_dnn_net_get_layer(Net net, int layerId);
void cv_dnn_layer_free(Layer layer);

int cv_dnn_layer_input_name_to_index(Layer layer, const char * name);
int cv_dnn_layer_output_name_to_index(Layer layer, const char * name);
const char * cv_dnn_layer_name(Layer layer);
const char * cv_dnn_layer_type(Layer layer);

Ints cv_dnn_nms_boxes(RotatedRects bboxes,
                      Floats scores,
                      float score_threshold,
                      float nms_threshold,
                      float eta = 1.f,
                      int top_k = 0);

#ifdef __cplusplus
}
#endif

#endif // CVC_DNN_H
