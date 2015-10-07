#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

Mat rotateImage(const Mat& source, double angle)
{
    Mat dst;    
    Point2f src_center(source.cols/2.0, source.rows/2.0); //find the center of the image
    Mat rot_mat = getRotationMatrix2D(src_center, angle, 1.0); // calculate the transformation matrix for rotating a certain angle on center point
    Rect bbox = RotatedRect(src_center,source.size(), angle).boundingRect();
    // make a bounding box which can fit the rotated source image 
    rot_mat.at<double>(0,2) += bbox.width/2.0 - src_center.x;
    rot_mat.at<double>(1,2) += bbox.height/2.0 - src_center.y;
    // modify transform matrix make the rotated image right in the center of the bounding box 
    warpAffine(source, dst, rot_mat, bbox.size(),INTER_CUBIC); //make the rotation and store the image into dst
    return dst;
}

int main(int argc, char** argv )
{
    
    Mat image, image1, image2, image3, image4, image5;
    image = imread( "image.jpg", 1 ); // Read file into mat image

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    
    imshow("Display Original Image", image);

    waitKey(0);
    // resize image
    cout << "resizing the image.."<<endl;
    resize(image, image1,image1.size(),1/1.4,2.4,INTER_CUBIC);
    
    imshow("resized image",image1);
    waitKey(0);
    // rotate image
    cout << "rotating image.." << endl;
    image2 = rotateImage(image1, -33.5); // negative angle means clockwise
    imshow("rotated image",image2);
    waitKey(0);

    imwrite("image_modified.jpg",image2);

    // inverse transformation of the image

    image3 = rotateImage(image2, 33.5);
    resize(image3, image4, image4.size(),1.4,1/2.4,INTER_CUBIC);
    // Because the rotated image still has its black boundary box we need to capture the center part of the image. 
    Rect myROI(image4.cols/2.0-1920/2.0, image4.rows/2.0- 1080/2.0, 1920, 1080); 
    // the first two figure decided the starting point and the last two decide width and height.
    image5 = image4(myROI);
    imshow("inversed image",image5);
    waitKey(0);

    imwrite("inversed_image.jpg",image5);
    cout <<"finished!!!"<<endl;

    return 0;
}
