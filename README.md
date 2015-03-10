# Stitcher
Simple command line tool using OpenCV to stitch images together as a panorama image.

# Compiling
To compile the code using g++ use pkg-config for the following:
```sh
$ g++ stitch.cpp -o stitch `pkg-config --cflags --libs opencv`
```

# Usage
Below is the command line usage of the tool.

```
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

The, "data", directory includes sets of images for show casing the results of the stitcher.  To run use one of these data sets execute the following command on the command line:

```sh
$ ./stitch <blender> <output filename> ./data/<data directory>/*.png
```

The different data sets included are:
<ul>
<li>carmel</li>
<li>diamondhead</li>
<li>goldengate</li>
<li>shanghai</li>
</ul>

The images are taken from the <a href="http://sourceforge.net/adobe/adobedatasets/home/Home/">Adobe Open Source Data Set</a>.

# License
This code is provided AS-IS with no support.
