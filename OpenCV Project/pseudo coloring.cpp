#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> 
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main() {
	Mat gray = imread("zx.png", 0);
	Mat color;
	// Applies a colormap on a given image
	// gray: src, color: dst, COLORMAP_JET: the color map to apply
	applyColorMap(gray, color, COLORMAP_COOL);
	imshow("gray", gray);
	imshow("image", color);
	waitKey(0);
	return 0;
}