#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> 
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main() {
	Mat image, laplacian, abs_laplacian, sharpening;
	image = imread("zx.png", 0);
	
	GaussianBlur(image, image, Size(3, 3), 0, 0, BORDER_DEFAULT);
	// calculates the Laplacian of an image
	// image: src, laplacian: dst, CV_16S: desire depth of dst,
	// 1: aperture size used to compute second-derivative (optional) 마스크의 크기
	// 1: optional scale factor for the computed Laplacian values 라플라시안? 부분에 특정한 값을해주고 싶을때
	// 0: optional delta value that is added to the result 특정한 값을 더해주고 싶을때, 0이면 그대로의 값을 가지고가겠다.
	//Laplacian(image, laplacian, CV_16S, 1,1,0);
	Laplacian(image, laplacian, CV_16S, 5,5,5); // 2차미분수행
	convertScaleAbs(laplacian, abs_laplacian); // 8비트영상으로 바꿔줌
	sharpening = abs_laplacian + image;
	
	imshow("Input image", image);
	imshow("Laplacian", laplacian);
	imshow("abs_Laplacian", abs_laplacian);
	imshow("Sharpening", sharpening);
	
	waitKey(0);
}