// Otsu's algorithm

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> 
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main() {
	Mat image, result;
	image = imread("zx.png", 0);
	threshold(image, result, 0, 255, THRESH_BINARY | THRESH_OTSU);
	
	imshow("Input image", image);
	imshow("result", result);
	waitKey(0);
}