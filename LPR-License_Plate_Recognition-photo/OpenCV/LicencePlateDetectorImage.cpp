#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;

int main()
{
	std::string path = "Resourses/carPlate2.jpg";
	CascadeClassifier plateCascade;
	plateCascade.load("Resourses/haarcascade_russian_plate_number.xml");
	if (plateCascade.empty())
	{
		std::cout << "XML file not loaded" << std::endl;
	}
	std::vector<Rect> plates;
	Mat img = imread(path);
	if (img.empty()) {
		std::cout << "Error: Could not open or find the image!" << std::endl;
		return -1;
	}

	plateCascade.detectMultiScale(img, plates, 1.1, 10);
	for (int i = 0; i < plates.size(); i++)
	{
		rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 3);
	}

	imshow("Image", img);
	waitKey(0);
	return 0;
}
