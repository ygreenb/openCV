#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main() {
	Mat image = imread("zx.png", 0); // grayscale
	Mat gamma_img;
	MatIterator_<uchar> it, end;
	float gamma = 0.5;
	unsigned char pix[256]; // LUT(룩업테이블) 방식 배열

	for (int i = 0; i < 256; i++) {
		pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma)*255.0f);
	}
	gamma_img = image.clone();

	for (it = gamma_img.begin<uchar>(), end = gamma_img.end<uchar>(); it != end; it++) {
		*it = pix[(*it)]; // 입력 영상의 값들을 다 엑세스하고, 엑세스한 값이 무엇인지에 따라 LUT을 활용함
	}
	
	imshow("Input image", image);
	imshow("Gamma transfomation", gamma_img);
	waitKey(0);
	return 0;
}