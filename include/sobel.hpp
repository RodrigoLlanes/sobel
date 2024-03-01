//
// Created by Rodrigo Llanes on 29/02/2024.
//

#ifndef SOBEL_SOBEL_HPP
#define SOBEL_SOBEL_HPP

#include "kernel.hpp"
#include "utils.hpp"

template<typename T>
Image convolution(const Image& img, Kernel<T>& kernel);

Image sobel(const Image& img);

#endif //SOBEL_SOBEL_HPP
