#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;

int main()
{
	
	VideoCapture cap;
	cap.open("Resourses/car_video.mp4");
	if (!cap.isOpened()) {
		std::cout << "Error: Could not open camera or video!" << std::endl;
		return -1;
	}

	Mat frame;
	CascadeClassifier plateCascade;

	if (!plateCascade.load("Resourses/haarcascade_russian_plate_number.xml")) {
		std::cout << "Error: Could not load XML file!" << std::endl;
		return -1;
	}

	while (true)
	{
		cap >> frame;
		if (frame.empty()) break;

		Mat gray;
		cvtColor(frame, gray, COLOR_BGR2GRAY);

		std::vector<Rect> plates;
		plateCascade.detectMultiScale(gray, plates, 1.2, 3, 0, Size(50, 20), Size(300, 100));

		for (size_t i = 0; i < plates.size(); i++) {
			rectangle(frame, plates[i], Scalar(0, 255, 0), 3);
			Mat plateROI = frame(plates[i]);
			resize(plateROI, plateROI, Size(200, 100));
			imshow("Detected Plate", plateROI);
		}
		static int frameCount = 0;
		frameCount++;
		if(frameCount%5 ==0)
			imshow("License Plate Detection", frame);
		
		if (waitKey(30) == 27) break;  // Press ESC to exit

	}
		cap.release();
		destroyAllWindows();
		return 0;

}




