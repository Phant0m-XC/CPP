#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <cstdlib>
#include <iostream>

CvCapture *capture{ nullptr };

void myTrackbarCallback(int pos) {
	cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, pos);
}

int main(int argc, char **argv) {
	IplImage *frame{ nullptr };
	char const *filename{ argc == 2 ? argv[1] : "test.avi" };
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	capture = cvCreateFileCapture(filename);
	double framesCount{ cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT) };
	std::cout << "[i] count: " << framesCount << std::endl;
	int frames = static_cast<int>(framesCount);
	int currentPosition{ 0 };
	if (frames != 0)
		cvCreateTrackbar("Position", "original", &currentPosition, frames, myTrackbarCallback);
	while (true) {
		frame = cvQueryFrame(capture);
		if (!frame) break;
		cvShowImage("original", frame);
		if (cvWaitKey(33) == 27) break;
	}

	cvReleaseCapture(&capture);
	cvDestroyWindow("original");
	return EXIT_SUCCESS;
}