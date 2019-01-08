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
	//���J����
	src = imread(argv[1], cv::IMREAD_GRAYSCALE);
	//�ˬdŪ�ɬO�_���\
	if (!src.data) {
		cout << "�L�k�}�ҩΧ䤣�����" << std::endl;
		return -1;
	}
	Mat Canny1, Canny2;
	Canny(src, Canny1, 50, 150, 3);
	threshold(Canny1, Canny2, 128, 255, THRESH_BINARY_INV);

	imshow("���", src);
	imshow("�©�", Canny1);
	imshow("�թ�", Canny2);
	//�������ݫ��s
	waitKey(0);

	return 0;
}