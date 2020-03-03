// Local(Adaptive) Thresholding

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> 
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;


int main() {
	Mat image, binary, adaptive_binary;
	image = imread("zx.png", 0);
	
	threshold(image, binary, 150, 255, THRESH_BINARY);
	adaptiveThreshold(image, adaptive_binary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 85, 15);
	
	imshow("Input image", image);
	imshow("binary", binary);
	imshow("adaptive binary", adaptive_binary);
	waitKey(0);
}