
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


//using namespace cv;


/// <summary>
/// ====================Images================
/// </summary>
/// <returns></returns>
//int main() {
//	std::string path = "Resources/test.png";
//	cv::Mat img = cv::imread(path);
//	cv::imshow("Image", img);
//	cv::waitKey(0);
//}

/// <summary>
/// ==============================Video========================
/// </summary>
/// <returns></returns>
//
//int main() {
//	std::string path = "Resources/test_video.mp4";
//	cv::VideoCapture cap(path);
//	cv::Mat img;
//
//	while (true) {
//
//		cap.read(img);
//
//	cv::imshow("Image", img);
//	cv::waitKey(30);
//	
//	}
//}


// ================ WebCam ================

int main() {

	cv::VideoCapture cap(0);
	cv::Mat img;

	while (true) {

		cap.read(img);

		cv::imshow("Image", img);
		cv::waitKey(1);

	}
}