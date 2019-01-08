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
	Mat dst1, dst2;
	threshold(src, dst1, 150, 255, THRESH_BINARY | THRESH_OTSU);
	threshold(src, dst2, 150, 255, THRESH_BINARY_INV | THRESH_OTSU);
	imshow("原圖", src);
	imshow("otsu1", dst1);
	imshow("otsu2", dst2);
	
	//視窗等待按鈕
	waitKey(0);

	return 0;
}