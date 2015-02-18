# Stitcher
Simple command line tool using OpenCV to stitch images together as a panorama image.

# Compiling
To compile the code using g++ use pkg-config for the following:
```sh
$ g++ stitch.cpp -o stitch `pkg-config --cflags --libs opencv`
```

# License
This code is provided AS-IS with no support.
