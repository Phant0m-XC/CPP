#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <cstdlib>

int main(int argv, char** argc) {
	int height = 620;
	int width = 440;

	CvPoint pt = cvPoint(height / 4, width / 4);
	IplImage *hw = cvCreateImage(cvSize(height, width), 8, 3);
	cvSet(hw, cvScalar(0, 0, 0));
	CvFont font;
	cvInitFont(&font, CV_FONT_HERSHEY_COMPLEX, 1.0, 1.0, 0, 1, CV_AA);
	cvPutText(hw, "OpenCV Hello World!!!", pt, &font, CV_RGB(150, 0, 150));
	cvNamedWindow("Hello OpenCV", 0);
	cvShowImage("Hello OpenCV", hw);
	cvWaitKey(0);
	cvReleaseImage(&hw);
	cvDestroyWindow("Hello OpenCV");
	return EXIT_SUCCESS;
}