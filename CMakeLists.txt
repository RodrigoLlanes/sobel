cmake_minimum_required(VERSION 3.26)
project(sobel)

set(CMAKE_CXX_STANDARD 23)
set(ENV{OPENCV_DIR} "C:\\tools\\opencv\\build")
set(CMAKE_MODULE_PATH  ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenMP REQUIRED)
find_package(OpenCV REQUIRED)
include_directories(
        "include"
        ${OpenCV_INCLUDE_DIRS}
)


add_executable(${PROJECT_NAME}
        include/kernel.hpp

        src/main.cpp
        src/kernel.cpp
        include/utils.hpp
        src/utils.cpp)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_link_libraries(${PROJECT_NAME}
        ${OpenCV_LIBS}
        OpenMP::OpenMP_CXX
)
