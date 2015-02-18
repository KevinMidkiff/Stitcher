/*
 *
 * Author: Kevin Midkiff
 * Version: 0.1
 * Description:
 *  Simple image stitching tool using OpenCV to be used for creating panorama images.
 *  This was written for my Visual Computer class at Portland State University (CS410).
 *
 */
#include <stdio.h>

// OpenCV Includes
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/stitching/stitcher.hpp"
#include "opencv2/stitching/detail/blenders.hpp"

using namespace std;
using namespace cv;
using namespace cv::detail;

vector<Mat> getImages(int argc, char *argv[]) {
    vector<Mat> images;
    
    for(int i = 3; i < argc; i++) {
        Mat img = imread(argv[i]);
        
        // Verifying the image opened correctly
        if (!img.data) {
            fprintf(stderr, "Failed to Read Image: %s\n", argv[i]);
            exit(-1);
        }

        images.push_back(img);
    }

    return images;
}

Blender *getBlender(char *bn) {
    Blender *b;

    if (strcmp(bn, "Feather") == 0) {
        b = new FeatherBlender();
    }
    else if(strcmp(bn, "MultiBand") == 0) {
        b = new MultiBandBlender();
    }
    else {
        fprintf(stderr, "Unknown Blender: %s\n", bn);
        exit(-1);
    }

    return b;
}

void showUsage() { 
    printf("Usage: stitch <blender> <output> <img1> <img2> ... <imgN>\n\n");
    printf("Version: 0.1\n");
    printf("Author: Kevin Midkiff\n");
    printf("Description: Simple image stitching command line tool using OpenCV\n\n");
    printf("WARNING: You must pass at least two images\n\n");
    printf("Argument Description:\n");
    printf("\tblender - Which blender to use: Default, Feather, MultiBand\n");
    printf("\toutput  - Output filename\n\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        showUsage();
        exit(-1);
    }
    
    vector<Mat> vImg;
    Mat rImg;
    char *outName = argv[2];

    Stitcher stitcher = Stitcher::createDefault();
    Blender *b;

    if (strcmp(argv[1], "Default") != 0) {
        b = getBlender(argv[1]);
        stitcher.setBlender(b);
    }

    vImg = getImages(argc, argv);
    
    printf("Stitching images together.... "); 
    stitcher.stitch(vImg, rImg);
    printf("Done.\n");
    imwrite(outName, rImg);
    
    return 0;
}
