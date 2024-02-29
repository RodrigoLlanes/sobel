#include <iostream>
#include <omp.h>
#include "kernel.hpp"
#include "utils.hpp"


using namespace cv;


template<typename T>
uint8_t applyKernel(const Mat& img, Kernel<T>& kernel, int x, int y, int norma) {
    T hc[3] = {0, 0, 0}, vc[3] = {0, 0, 0};
    for (int dy = -kernel.vMargin; dy <= kernel.vMargin; dy++) {
        for (int dx = -kernel.hMargin; dx <= kernel.hMargin; dx++) {
            for (int dim = 0; dim < 3; dim++) {
                vc[dim] += kernel(dy+1, dx+1) * img.at<cv::Vec3b>(y+dy,x+dx)[dim];
                hc[dim] += kernel(dx+1, dy+1) * img.at<cv::Vec3b>(y+dy,x+dx)[dim];
            }
        }
    }


    T h = (abs(hc[0]) + abs(hc[1]) + abs(hc[2])) / norma;
    T v = (abs(vc[0]) + abs(vc[1]) + abs(vc[2])) / norma;

    return (uint8_t) sqrt(h * h + v * v);
}


template<typename T>
Mat sobel(const Mat& img, Kernel<T>& kernel) {
    Mat res(img.rows, img.cols, CV_8UC1, Scalar(0));

    T norma = kernel.norma() * 3;

    #pragma omp parallel for// collapse(2)
    for(int y = kernel.vMargin; y < img.rows-kernel.vMargin; y++) {
        for(int x = kernel.hMargin; x < img.cols-kernel.hMargin; x++) {
            res.at<cv::uint8_t>(y, x) = applyKernel(img, kernel, x, y, norma);
        }
    }

    return res;
}


int main() {
    try {
        Mat img = loadImage("../resources/test.jpg");

        int data[3][3] = {{1, 0, -1},
                          {2, 0, -2},
                          {1, 0, -1}};
        Kernel<int> kernel = Kernel<int>::fromArray<3,3>(data);

        Mat res = sobel(img, kernel);

        plotImage(res);
    } catch (std::exception& exception) {
        printf("%s", exception.what());
        return 1;
    }
}
