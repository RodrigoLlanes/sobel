#include <iostream>
#include "utils.hpp"
#include "sobel.hpp"


int main(int argc, char *argv[]) {
    if (2 > argc || argc > 3) {
        printf("Expected 1 or 2 arguments, but %d received.\n", argc);
        printf("Usage: convolution input [output]\n");
        return 1;
    }

    silentOpenCV();

    try {
        Image img = loadImage(argv[1]);
        Image res = sobel(img);

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
