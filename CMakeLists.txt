cmake_minimum_required(VERSION 3.22)
project(sobel)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenMP REQUIRED)
find_package(OpenCV REQUIRED)
include_directories(
        src
        include
        ${OpenCV_INCLUDE_DIRS}
)


add_executable(${PROJECT_NAME}
        src/main.cpp
        #src/kernel.cpp
        src/utils.cpp
        include/sobel.hpp
        src/sobel.cpp
)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_link_libraries(${PROJECT_NAME}
        ${OpenCV_LIBS}
        OpenMP::OpenMP_CXX
)
