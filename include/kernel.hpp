//
// Created by Rodrigo Llanes on 29/02/2024.
//

#ifndef SOBEL_KERNEL_HPP
#define SOBEL_KERNEL_HPP

template<typename T>
class Kernel {
public:
    const int width, height;
    const int hMargin, vMargin;

    Kernel(int width, int height);
    Kernel(const Kernel& other);
    ~Kernel();
    [[nodiscard]] inline T& operator()(int row, int col);
    [[nodiscard]] T norma() const;

    template<int H, int W>
    [[nodiscard]] static Kernel<T> fromArray(T data[H][W]);

private:
    T** data;
};

#include "kernel.cpp"

#endif //SOBEL_KERNEL_HPP
