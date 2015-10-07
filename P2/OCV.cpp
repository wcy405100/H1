#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void grayScale(Mat image, string nm){
		Mat gray;
		cvtColor(image, gray, CV_BGR2GRAY);
		namedWindow( "Result window", CV_WINDOW_AUTOSIZE );   
		imshow( "Result window", gray );
		std::string renm = nm+"_gray.jpg";
		imwrite(renm,gray);
		cout << "grayscale image stored."<<endl;
}

int main( int argc, char** argv )
{	
	std:: string nm;
	cout << "Please enter the image you want to open (without .jpg):";
	std::getline(std::cin, nm);
	nm = nm+".jpg";
	cout << nm << endl;

	Mat image;
	image = imread(nm, CV_LOAD_IMAGE_COLOR);   
	// Read the file Put the image into the exe folder.

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    namedWindow( "Display window", WINDOW_AUTOSIZE );	// Create a window for display.
    imshow( "Display window", image );                   // Show our image inside it.
	
	char ans1;
	cout << "Do you want to change the image into grayscale?[y]/[n]"<<endl;
	cin >> ans1;
	if ( ans1 == 'y')
	{
		 grayScale(image,nm);
	}
	else
	{
		cout << "Nothing to Do on grayscale"<<endl;
	}

	char ans2;
	cout << "Do you want to change the image size?[y]/[n]"<<endl;
	cin >> ans2;
		if ( ans2 == 'y')
	{
		int xx,yy;
		double x,y;
		Mat dst;
		cout << "Input the x-axis dimension:"<<endl;
		cin >> xx;
		x = (double)xx/image.cols;
		
		cout << "Input the y-axis dimension:"<<endl;
		cin >> yy;
		y = (double)yy/image.rows;
		

		resize(image,dst,dst.size(),x,y,INTER_AREA);
		imshow( "Image after resized", dst );
		imwrite("resize.jpg",dst);

	}
	else
	{
		cout << "Nothing to Do on resize"<<endl;
	}
	

	cout << "Jobs Done!! Closing"<<endl;

	
	waitKey(0);                                   // Wait for a keystroke in the window
    return 0;
}
