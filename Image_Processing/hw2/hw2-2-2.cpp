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
	Mat Gaussian;
	GaussianBlur(src, Gaussian, Size(5, 5), 0, 0);
	imshow("原圖", src);
	imshow("高斯平滑", Gaussian);

	//視窗等待按鈕
	waitKey(0);

	return 0;
}