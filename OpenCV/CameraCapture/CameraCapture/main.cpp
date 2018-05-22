#include <opencv2\opencv.hpp>
#include <opencv\highgui.h>
#include <cstdlib>
#include <iostream>

int main() {
	cv::Mat image;
	cv::VideoCapture capture(0);
	if (!capture.isOpened())
		return EXIT_FAILURE;
	cvNamedWindow("capture", CV_WINDOW_AUTOSIZE);
	const char *filename = "capture.avi";
	double fps = 15;
	CvSize size = cvSize(640, 480);
	cv::VideoWriter writer(filename, CV_FOURCC('D', 'I', 'V', 'X'), fps, size, 1);
	while (true) {
		capture >> image;
		if (writer.isOpened())
			writer.write(image);
		cv::imshow("capture", image);
		if (cvWaitKey(33) == 27)
			break;
	}
	cvDestroyWindow("capture");
	return EXIT_SUCCESS;
}
