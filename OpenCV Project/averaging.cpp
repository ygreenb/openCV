#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> 
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main() {
	Mat image, AvgImg, GaussianImg;
	image = imread("zx.png");

	// Blurs an image using the normalized box filter
	// image: input image, AvgImg: output image, Size(5, 5): blurring kernel size
	blur(image, AvgImg, Size(5, 5));

	// Blurs an image using a Gaussian filter
	// image: input image, GaussianImg: output image, Size(5, 5): Gaussian kernel size
	// 1.5: Gaussian kernel standard deviation in X direction
	GaussianBlur(image, GaussianImg, Size(5, 5), 1.5);

	imshow("Input image", image);
	imshow("Average image", AvgImg);
	imshow("Gaussian blurred image", GaussianImg);

	waitKey(0);
	return 0;
}