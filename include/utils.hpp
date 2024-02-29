//
// Created by Rodrigo Llanes on 29/02/2024.
//

#ifndef SOBEL_UTILS_HPP
#define SOBEL_UTILS_HPP

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <string>


cv::Mat loadImage(const std::string& path);

void plotImage(const cv::Mat& image, const std::string& title = "ImagePlot");


#endif //SOBEL_UTILS_HPP
