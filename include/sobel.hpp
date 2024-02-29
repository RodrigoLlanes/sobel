//
// Created by Rodrigo Llanes on 29/02/2024.
//

#ifndef SOBEL_SOBEL_HPP
#define SOBEL_SOBEL_HPP

#include <iostream>
#include <omp.h>
#include "kernel.hpp"
#include "utils.hpp"

template<typename T>
cv::Mat sobel(const cv::Mat& img, Kernel<T>& kernel);

cv::Mat sobel(const cv::Mat& img);

#endif //SOBEL_SOBEL_HPP
