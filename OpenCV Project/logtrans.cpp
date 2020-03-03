#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main() {
	Mat image = imread("zx.png", 0); // grayscale
	Mat f_img, log_img;
	double c = 0.5f; // 상수
	image.convertTo(f_img, CV_32F); // log함수 활용하기 위해 float형으로 변환
	f_img = abs(f_img) + 1; // 절대값 취해줌. 픽셀값이 0~255이기 때문에 큰 의미는x
	log(f_img, f_img);
	normalize(f_img, f_img, 0, 255, NORM_MINMAX); // 0~ 255값으로 정규화
	convertScaleAbs(f_img, log_img, c); // 픽셀 값에 c값을 곱해서 unsigned 8-bit 타입으로 형 변환시킴
	imshow("Input image", image);
	imshow("Log transfomation", log_img);

	waitKey(0);
	return 0;
}