//
// Created by Rodrigo Llanes on 29/02/2024.
//


#include <stdexcept>
#include "kernel.hpp"


template<typename T>
Kernel<T>::Kernel(int w, int h): data(new T*[h]), width(w), height(h), hMargin(w/2), vMargin(h/2) {
    if (width < 1 || height < 1) {
        throw std::runtime_error("Kernel matrix must have a minimum size of 1x1.");
    }
    if (width % 2 == 0 || height  % 2 == 0) {
        throw std::runtime_error("The sides of a kernel matrix must be of odd size.");
    }

    for (int i = 0; i < height; i++) {
        data[i] = new T[width];
    }
}


template<typename T>
Kernel<T>::~Kernel() {
    for (int i = 0; i < height; i++) {
        delete[] data[i];
    }
    delete[] data;
}


template<typename T>
Kernel<T>::Kernel(const Kernel &other) : Kernel(other.width, other.height) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            data[row][col] = other.data[row][col];
        }
    }
}


template<typename T>
template<int H, int W>
Kernel<T> Kernel<T>::fromArray(T array[H][W]) {
    Kernel kernel(W, H);
    for (int row = 0; row < H; row++) {
        for (int col = 0; col < W; col++) {
            kernel.data[row][col] = array[row][col];
        }
    }
    return kernel;
}


template<typename T>
T& Kernel<T>::operator()(int row, int col) {
    // TODO: Check and throw error
    return data[row][col];
}


template<typename T>
T Kernel<T>::norma() const {
    T res = 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (data[row][col] > 0) {
                res += data[row][col];
            }
        }
    }
    return res;
}