#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main() {
	Mat image = imread("lena.png", 0);
	Mat negative_img = image.clone();
	for (int i = 0; i < image.rows; i++)
		for (int j = 0; j < image.cols; j++)
			negative_img.at<uchar>(i, j) = 255 - image.at<uchar>(i, j); // negativer ±¸Çö
	imshow("Input image", image);
	imshow("Negative transformation", negative_img);
	
	waitKey(0);
	return 0;
}