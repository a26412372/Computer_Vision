#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

void drawHistImg(const Mat &src, Mat &dst) {
	int histSize = 256;
	float histMaxValue = 0;
	for (int i = 0; i < histSize; i++) {
		float tempValue = src.at<float>(i);
		if (histMaxValue < tempValue) {
			histMaxValue = tempValue;
		}
	}

	float scale = (0.9 * 256) / histMaxValue;
	for (int i = 0; i < histSize; i++) {
		int intensity = static_cast<int>(src.at<float>(i)*scale);
		line(dst, Point(i, 255), Point(i, 255 - intensity), Scalar(0));
	}
}

int main(int argc, char** argv) {

	argv[1] = (char*)"C:\\images\\moon_683x1000.jpg";
	//argv[1] = (char*)"C:\\images\\113044_green.jpg"; 
	//argv[1] = (char*)"C:\\images\\jai.jpg"; 

	Mat src,gray;
	//載入圖檔
	src = imread(argv[1], cv::IMREAD_GRAYSCALE);
	//檢查讀檔是否成功
	if (!src.data) {
		cout << "無法開啟或找不到圖檔" << std::endl;
		return -1;
	}

	int histSize = 256;
	float range[] = { 0, 255 };
	const float* histRange = { range };
	Mat histImg;
	calcHist(&src, 1, 0, Mat(), histImg, 1, &histSize, &histRange);

	Mat showHistImg(256, 256, CV_8UC1, Scalar(255));  
	drawHistImg(histImg, showHistImg);
	resizeWindow("等化前", 640, 480);
	resizeWindow("等化前直方圖", 640, 480);
	imshow("等化前", src);
	imshow("等化前直方圖", showHistImg);

	Mat equmat;
	equalizeHist(src, equmat);
	Mat outmat;
	calcHist(&equmat, 1, 0, Mat(), outmat, 1, &histSize, &histRange);

	Mat showHistImg2(256, 256, CV_8UC1, Scalar(255));  
	drawHistImg(outmat, showHistImg2);
	resizeWindow("等化後", 640 , 480);
	resizeWindow("等化後直方圖", 640, 480);
	imshow("等化後", equmat);
	imshow("等化後直方圖", showHistImg2);

	


	//視窗等待按鈕
	waitKey(0);

	return 0;
}