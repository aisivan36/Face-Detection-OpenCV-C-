
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>




//using namespace cv;

/// <summary>
/// ====================Images================
/// </summary>
/// <returns></returns>
int main() {
	/*std::string path = "Resources/profile.png";*/
	cv::VideoCapture cap(0);
	/*cv::Mat img = cv::imread(path);*/
	cv::Mat img;


	while (true) {
		cap.read(img);
		cv::Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

		cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
		cv::GaussianBlur(img, imgBlur, cv::Size(3, 3), 3, 0);
		cv::Canny(imgBlur, imgCanny, 25, 75);

		cv::Mat kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

		cv::dilate(imgCanny, imgDil, kernel);
		erode(imgDil, imgErode, kernel);

		//Show window

		cv::imshow("Image", img);
		cv::imshow("Image Gray", imgGray);
		cv::imshow("Image Blur", imgBlur);
		cv::imshow("Image Canny", imgCanny);
		cv::imshow("Image Dilation", imgDil);
		cv::imshow("Image Erode", imgErode);

		cv::waitKey(1);
	}
}


//
//int main() {
//
//	cv::VideoCapture cap(0);
//	cv::Mat img;
//
//	while (true) {
//
//		cap.read(img);
//
//		cv::imshow("Image", img);
//		cv::waitKey(1);
//
//	}
//}