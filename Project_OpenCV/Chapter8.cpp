
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>


//using namespace cv;


/// <summary>
/// ====================Images================
/// </summary>
/// <returns></returns>
int main() {
	/*std::string path = "Resources/profile.png";
	cv::Mat img = cv::imread(path);*/

	cv::VideoCapture cap(0);
	cv::Mat img;


	while (true)
	{
		cap.read(img);


		cv::CascadeClassifier faceCascade;
		faceCascade.load("Resources/haarcascade_frontalface_default.xml");

		if (faceCascade.empty()) {
			std::cout << "XML file is not loaded \n";
		}

		std::vector<cv::Rect> faces;
		faceCascade.detectMultiScale(img, faces, 1.1, 10);

		for (int i = 0; i < faces.size(); i++)
		{
			cv::rectangle(img, faces[i].tl(), faces[i].br(), cv::Scalar(255, 0, 255), 3);
		}



		cv::imshow("Image", img);
		cv::waitKey(1);
	}
}