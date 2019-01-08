#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

	argv[1] = (char*)"C:\\images\\jet_512x512.jpg";
	//argv[1] = (char*)"C:\\images\\113044_green.jpg"; 
	//argv[1] = (char*)"C:\\images\\jai.jpg"; 

	Mat src;
	//載入圖檔
	src = imread(argv[1], cv::IMREAD_GRAYSCALE);
	//檢查讀檔是否成功
	if (!src.data) {
		cout << "無法開啟或找不到圖檔" << std::endl;
		return -1;
	}

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;
	Sobel(src, grad_x, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
	Sobel(src, grad_y, CV_16S, 0, 1, 3, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);

	Mat dst1, dst2;
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst1);
	threshold(dst1, dst2, 80, 255, THRESH_BINARY | THRESH_OTSU);
	imshow("原圖", src);
	imshow("Sobel-1", dst1);
	imshow("Sobel-2", dst2);

	//視窗等待按鈕
	waitKey(0);

	return 0;
}