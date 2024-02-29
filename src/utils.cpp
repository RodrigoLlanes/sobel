//
// Created by Rodrigo Llanes on 29/02/2024.
//

#include "utils.hpp"

using namespace cv;


Mat loadImage(const std::string& path) {
    Mat img = imread(path, IMREAD_COLOR);
    if(img.empty()) {
        throw std::runtime_error("Image not found " + path);
    }
    return img;
}


void plotImage(const Mat& image, const std::string& title) {
    cv::namedWindow(title, cv::WINDOW_NORMAL);
    cv::imshow(title, image);
    cv::waitKey(0);
}
