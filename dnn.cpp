// This file is a part of the LibCVC project.
// It is subject to the license terms in the LICENSE file found
// in the top-level directory of this distribution.

#include "dnn.h"

error_t cv_dnn_read_net(const char * model, const char * config, const char * framework, Net * out_net) {
    try_
        auto net = cv::dnn::readNet(model, config, framework);
        if (net.empty()) return cv_set_error(OTHER_ERROR, "Cannot read net");
        *out_net = new cv::dnn::Net(net);
    end_
}

error_t cv_dnn_net_free(Net net) {
    try_
        delete net;
    end_
}

error_t cv_dnn_net_empty(Net net, bool * out_value) {
    try_
        *out_value = net->empty();
    end_
}

error_t cv_dnn_net_set_input(Net net, Mat blob, const char* name, double scale_factor, Scalar mean) {
    try_
        net->setInput(*blob, name, scale_factor, *mean);
    end_
}

error_t cv_dnn_net_forward(Net net, const char * output_name, Mat out_result) {
    try_
        out_result->operator=(net->forward());
    end_
}

error_t cv_dnn_net_forward_layers(Net net, Strings layer_names, Mats out_result) {
    try_
        net->forward(*out_result, *layer_names);
    end_
}

error_t cv_dnn_net_set_preferable_backend(Net net, int backend) {
    try_
        net->setPreferableBackend(backend);
    end_
}

error_t cv_dnn_net_set_preferable_target(Net net, int target) {
    try_
        net->setPreferableTarget(target);
    end_
}

error_t cv_dnn_net_get_perf_profile(Net net, Doubles out_layers, int64_t * out_time) {
    try_
        *out_time = net->getPerfProfile(*out_layers);
    end_
}

error_t cv_dnn_blob_from_images(Mats images,
                                Mat out_blob,
                                double scale_factor,
                                Size size,
                                Scalar mean,
                                bool swap_rb,
                                bool crop,
                                int depth)
{
    try_
        cv::dnn::blobFromImages(*images, *out_blob, scale_factor, *size,
                                *mean, swap_rb, crop, depth);
    end_
}

error_t cv_dnn_net_get_layer_names(Net net, Strings names) {
    try_
        names->operator=(net->getLayerNames());
    end_
}

error_t cv_dnn_net_get_layer_with_name(Net net, const char * layer_name, Layer * out_layer) {
    try_
        *out_layer = new cv::Ptr<cv::dnn::Layer>(net->getLayer(layer_name));
    end_
}

error_t cv_dnn_net_get_layer_with_id(Net net, int layer_id, Layer * out_layer) {
    try_
        *out_layer = new cv::Ptr<cv::dnn::Layer>(net->getLayer(layer_id));
    end_
}

error_t cv_dnn_layer_blobs(Layer layer, Mats out_mats) {
    try_
        out_mats->operator=((*layer)->blobs);
    end_
}

error_t cv_dnn_layer_add_blob(Layer layer, Mat blob) {
    try_
        (*layer)->blobs.push_back(*blob);
    end_
}

error_t cv_dnn_layer_free(Layer layer) {
    try_
        delete layer;
    end_
}

error_t cv_dnn_layer_input_name_to_index(Layer layer, const char* name, int * out_index) {
    try_
        *out_index = (*layer)->inputNameToIndex(name);
    end_
}

error_t cv_dnn_layer_output_name_to_index(Layer layer, const char* name, int * out_index) {
    try_
        *out_index = (*layer)->outputNameToIndex(name);
    end_
}

error_t cv_dnn_layer_name(Layer layer, const char ** out_name) {
    try_
        *out_name = (*layer)->name.c_str();
    end_
}

error_t cv_dnn_layer_type(Layer layer, const char ** out_type) {
    try_
        *out_type = (*layer)->type.c_str();
    end_
}

error_t cv_dnn_nms_boxes(RotatedRects bboxes,
                         Floats scores,
                         float score_threshold,
                         float nms_threshold,
                         float eta,
                         int top_k,
                         Ints out_indices)
{
    try_
        std::vector<cv::RotatedRect> rboxes(*bboxes);
        cv::dnn::NMSBoxes(rboxes, *scores, score_threshold, nms_threshold, *out_indices, eta, top_k);
    end_
}

