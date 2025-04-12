#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;

int main()
{
		std::string path = "Resourses/face.jpg";
		CascadeClassifier faceCascade;
		faceCascade.load("Resourses/haarcascade_frontalface_default.xml");
		if (faceCascade.empty())
		{
			std::cout << "XML file not loaded" << std::endl;
		}
		std::vector<Rect> faces;
		Mat img = imread(path);
		if (img.empty()) {
			std::cout << "Error: Could not open or find the image!" << std::endl;
			return -1;
		}

		faceCascade.detectMultiScale(img, faces, 1.1, 10);
		for (int i = 0; i < faces.size(); i++)
		{
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
		}

		imshow("Image", img);
		waitKey(0);
		return 0;

}