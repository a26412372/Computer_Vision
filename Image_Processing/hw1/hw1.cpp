#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

/*Mat ellipse_detect(Mat& src) {
	Mat img = src.clone();
	Mat skinCrCbHist = Mat::zeros(Size(256, 256), CV_8UC1);//返回指定的大小和類型的零矩陣
	//使用opencv自帶的椭圓生成函数生成一個膚色椭圓模型
	ellipse(skinCrCbHist, Point(113, 155.6), Size(23.4, 15.2), 43.0, 0.0, 360.0, Scalar(255, 255, 255), -1);
	Mat YCrCb_image;
	Mat output_mask = Mat::zeros(img.size(), CV_8UC1);//返回指定的大小和類型的零矩陣
	cvtColor(img, YCrCb_image, COLOR_BGR2YCrCb);//色彩空間轉換
	for (int i = 0; i < img.cols; i++) {
		for (int j = 0; j < img.rows; j++) {
			Vec3d YCrCb = YCrCb_image.at<Vec3b>(j, i);
			if (skinCrCbHist.at<uchar>(YCrCb[1], YCrCb[2]) > 0)//如果落在橢圓皮膚區域內
				output_mask.at<uchar>(j, i) = 255;
		}
	}

	Mat detect;
	img.copyTo(detect, output_mask);
	return detect;
};*/

Mat HSV_detect(Mat& src) {
	Mat hsv;
	Mat r, r2, g, b;
	Mat output_mask = Mat::zeros(src.size(), CV_8U);
	cvtColor(src, hsv, COLOR_BGR2HSV);
	inRange(hsv, Scalar(30, 68, 30), Scalar(80, 255, 255), g);//選取範圍
	output_mask = g;
	Mat detect;
	src.copyTo(detect, output_mask);;
	return detect;
}

int main(int argc, char** argv) {

	argv[1] = (char*)"C:\\images\\101087.jpg";
	//argv[1] = (char*)"C:\\images\\113044_green.jpg"; 
	//argv[1] = (char*)"C:\\images\\jai.jpg"; 

	Mat image;
	//載入圖檔
	image = imread(argv[1], cv::IMREAD_COLOR);
	//檢查讀檔是否成功
	if (!image.data) {
		cout << "無法開啟或找不到圖檔" << std::endl;
		return -1;
	}
	//Mat skin = ellipse_detect(image);
	Mat plant = HSV_detect(image);
	//建立顯示圖檔視窗
	namedWindow("Display window", cv::WINDOW_NORMAL);

	//在視窗內顯示圖檔
	//imshow("Display window", skin);
	imshow("Display window", plant);

	//視窗等待按鈕
	waitKey(0);

	return 0;
}