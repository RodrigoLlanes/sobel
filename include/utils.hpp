//
// Created by Rodrigo Llanes on 29/02/2024.
//

#ifndef SOBEL_UTILS_HPP
#define SOBEL_UTILS_HPP

#include <opencv2/core.hpp>
#include <string>

typedef cv::Mat Image;

Image loadImage(const std::string& path);

void saveImage(const Image& image, const std::string& path);

void plotImage(const Image& image, const std::string& title = "ImagePlot");

void silentOpenCV();


#endif //SOBEL_UTILS_HPP
