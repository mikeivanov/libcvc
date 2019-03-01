#include "dnn.h"

Net cv_dnn_read_net(const char * model, const char * config, const char * framework) {
    try {
        auto net = cv::dnn::readNet(model, config, framework);
        if (net.empty()) {
            cv_set_error("Can't read file");
            return nullptr;
        }
        return new cv::dnn::Net(net);
    }
    catch_exceptions(nullptr);
}

void cv_dnn_net_free(Net net) {
    delete net;
}

bool cv_dnn_net_empty(Net net) {
    return net->empty();
}

bool cv_dnn_net_set_input(Net net, Mat blob, const char* name, double scale_factor, Scalar mean) {
    try {
        net->setInput(*blob, name, scale_factor, *mean);
        return true;
    }
    catch_exceptions(false);
}

bool cv_dnn_net_forward(Net net, const char * output_name, Mat output_blob) {
    try {
        auto blob = net->forward(output_name);
        output_blob->operator=(blob);
        return true;
    }
    catch_exceptions(false);
}

bool cv_dnn_net_forward_layers(Net net, Strings layer_names, Mats out_blobs) {
    try {
        net->forward(*out_blobs, *layer_names);
        return true;
    }
    catch_exceptions(false);
}

void cv_dnn_net_set_preferable_backend(Net net, int backend) {
    net->setPreferableBackend(backend);
}

void cv_dnn_net_set_preferable_target(Net net, int target) {
    net->setPreferableTarget(target);
}

int64_t cv_dnn_net_get_perf_profile(Net net, Doubles out_layers) {
    auto times = new std::vector<double>();
    return net->getPerfProfile(*times);
}

bool cv_dnn_blob_from_images(Mats images,
                             Mat out_blob,
                             double scale_factor,
                             Size size,
                             Scalar mean,
                             bool swap_rb,
                             bool crop,
                             int depth)
{
    try {
        cv::dnn::blobFromImages(*images, *out_blob, scale_factor, *size,
                                *mean, swap_rb, crop, depth);
        return true;
    }
    catch_exceptions(false);
}

Strings cv_dnn_net_get_layer_names(Net net) {
    return new std::vector<cv::String>(net->getLayerNames());
}

Layer cv_dnn_net_get_layer(Net net, int layer_id) {
    try {
        return new cv::Ptr<cv::dnn::Layer>(net->getLayer(layer_id));
    }
    catch_exceptions(nullptr);
}

void cv_dnn_layer_free(Layer layer) {
    delete layer;
}

int cv_dnn_layer_input_name_to_index(Layer layer, const char* name) {
    try {
        return (*layer)->inputNameToIndex(name);
    }
    catch_exceptions(-1);
}

int cv_dnn_layer_output_name_to_index(Layer layer, const char* name) {
    try {
        return (*layer)->outputNameToIndex(name);
    }
    catch_exceptions(-1);
}

const char * cv_dnn_layer_name(Layer layer) {
    return (*layer)->name.c_str();
}

const char * cv_dnn_layer_type(Layer layer) {
    return (*layer)->type.c_str();
}

Ints cv_dnn_nms_boxes(RotatedRects bboxes,
                      Floats scores,
                      float score_threshold,
                      float nms_threshold,
                      float eta,
                      int top_k)
{
    try {
        std::vector<cv::RotatedRect> rboxes(*bboxes);
        std::vector<int> indices;
        cv::dnn::NMSBoxes(rboxes, *scores, score_threshold, nms_threshold, indices, eta, top_k);
        return new std::vector<int>(indices);
    }
    catch_exceptions(nullptr);
}

