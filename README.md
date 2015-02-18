# Stitcher
Simple command line tool using OpenCV to stitch images together as a panorama image.

# Compiling
To compile the code using g++ use pkg-config for the following:
```sh
$ g++ stitch.cpp -o stitch `pkg-config --cflags --libs opencv`
```

# Usage

```sh
Usage: stitch [-GPU] <blender> <output> <img1> <img2> ... <imgN>

Version: 0.1
Author: Kevin Midkiff
Description: Simple image stitching command line tool using OpenCV

WARNING: You must pass at least two images

Argument Description:
        GPU     - Flag to use the GPU
        blender - Which blender to use: Default, Feather, MultiBand
        output  - Output filename
```

# License
This code is provided AS-IS with no support.
