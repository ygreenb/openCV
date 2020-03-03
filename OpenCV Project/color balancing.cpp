#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> 
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main() {
	Mat image = imread("zx.png");
	Mat result;
	vector<Mat> ch(3);
	int b_sum = 0, g_sum = 0, r_sum = 0;
	int b_avg, g_avg, r_avg, b_tmp, g_tmp, r_tmp;
	if (image.empty()) {
		cerr << "read fail" << endl;
		exit(-1);
	}
	int rows = image.rows;
	int cols = image.cols;
	int pixno = rows * cols;

	// split by B, G, R channel
	split(image, ch);
	uchar* b;
	uchar* g;
	uchar* r;

	// calculate each channel's average 각 컬러채널에 대해서 평균 취해줌
	for (int i = 0; i < rows; i++) {
		b = ch[0].ptr<uchar>(i);
		g = ch[1].ptr<uchar>(i);
		r = ch[2].ptr<uchar>(i);
		for (int j = 0; j < cols; j++) {
			b_sum += b[j];
			g_sum += g[j];
			r_sum += r[j];
		}
	}
	b_avg = b_sum / pixno;
	g_avg = g_sum / pixno;
	r_avg = r_sum / pixno;
	
	// color balancing using gray world assumsption
	for (int i = 0; i < rows; i++) {
		b = ch[0].ptr<uchar>(i);
		g = ch[1].ptr<uchar>(i);
		r = ch[2].ptr<uchar>(i);
		for (int j = 0; j < cols; j++) {
			// to prevent overflow
			b_tmp = (128 * b[j]) / b_avg; // 특정한 픽셀 값(b[j])이 b_avg일 때, 그 값을 128이 되도록
			if (b_tmp > 255) {
				b[j] = 255;
			}
			else {
				b[j] = b_tmp;
			}
		
			g_tmp = (128 * g[j]) / g_avg;
			if (g_tmp > 255) {
				g[j] = 255;
			}
			else {
				g[j] = g_tmp;
			}
			r_tmp = (128 * r[j]) / r_avg;
			if (r_tmp > 255) {
				r[j] = 255;
			}
			else {
				r[j] = r_tmp;
			}
		}
	}

	// merge 3 channel's image
	merge(ch, result);

	imshow("image", image);
	imshow("result", result);
	waitKey(0);
	return 0;
}