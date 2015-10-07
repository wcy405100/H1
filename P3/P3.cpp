#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat TM(3,3,CV_64F);
	Mat image1, image2;
	image1 = imread("image.jpg",1);

	TM.at<double>(0,0) = 0.3;
	TM.at<double>(0,1) = 0.1;
	TM.at<double>(1,0) = 0.5;
	TM.at<double>(1,1) = 1.9;
	TM.at<double>(1,2) = 1;
	TM.at<double>(2,2) = 1;

	cout<< "The transformation matrix is:"<< TM << endl;
	warpPerspective(image1, image2, TM , image2.size(),INTER_LINEAR);
	imshow("image after transform",image2);
	imwrite("P3_transformed1.jpg",image2);
	return 0;
}
