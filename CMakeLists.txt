cmake_minimum_required(VERSION 3.2)
project(Stitcher)

# Find the OpenCV package
find_package(OpenCV REQUIRED)

# Add the stitcher executable and link the OpenCV libraries to it
add_executable(stitcher stitch.cpp)
target_link_libraries(stitcher ${OpenCV_LIBS})
