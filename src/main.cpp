#include <iostream>
#include "utils.hpp"
#include "sobel.hpp"


using namespace cv;


int main(int argc, char *argv[]) {
    if (2 > argc || argc > 3) {
        printf("Expected 1 or 2 arguments, but %d received.\n", argc);
        printf("Usage: sobel input [output]\n");
        return 1;
    }

    silentOpenCV();

    try {
        Mat img = loadImage(argv[1]);
        Mat res = sobel(img);

        if (argc == 3) {
            saveImage(res, argv[2]);
        } else {
            plotImage(res);
        }
    } catch (std::exception& exception) {
        printf("%s\n", exception.what());
        return 1;
    }
}
