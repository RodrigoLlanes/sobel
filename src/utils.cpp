//
// Created by Rodrigo Llanes on 29/02/2024.
//

#include <iostream>
#include <opencv2/core/utils/logger.hpp>
#include "utils.hpp"

using namespace cv;


Mat loadImage(const std::string& path) {
    Mat img = imread(path, IMREAD_COLOR);
    if(img.empty()) {
        throw std::runtime_error("Image not found " + path);
    }
    return img;
}


void saveImage(const cv::Mat& image, const std::string& path) {
    try {
        imwrite(path, image);
    } catch (std::exception& exception) {
        throw std::runtime_error(path + " is not a valid output file path.");
    }
}


void plotImage(const Mat& image, const std::string& title) {
    cv::namedWindow(title, cv::WINDOW_NORMAL);
    cv::imshow(title, image);
    cv::waitKey(0);
}


static int ignoreError(int status, const char* func_name, const char* err_msg,
                       const char* file_name, int line, void* userdata ) {
    // Used to silent OpenCV errors
    // These errors are being handled on their respective functions
    return 0;
}


void silentOpenCV() {
    cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);
    cv::redirectError(ignoreError);
}
