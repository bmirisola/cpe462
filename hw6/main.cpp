//
// Created by bmirisola on 11/17/21.
//

#include <opencv2/opencv.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
using namespace std;
using namespace cv;

void problem1(){
    Mat img = imread("/home/bmirisola/Pictures/Webcam/2021-11-04-184437.jpg");
    cvtColor(img,img,COLOR_BGR2GRAY);
    imwrite("/home/bmirisola/Pictures/gray.jpg", img);
    imshow("Gray Scale Image", img);

    waitKey(0);
    destroyAllWindows();
}

void problem2(){
    Mat img = imread("/home/bmirisola/Pictures/Webcam/2021-11-04-184437.jpg");
    cvtColor(img, img, COLOR_BGR2GRAY);
    Mat dst;
    equalizeHist(img, dst);
    imwrite("/home/bmirisola/Pictures/equalized.jpg", dst);
    imshow("Original", img);
    imshow("Equalized", dst);
    waitKey(0);
    destroyAllWindows();
}

void problem3(){
    Mat img = imread("/home/bmirisola/Pictures/Webcam/2021-11-04-184437.jpg");
    Mat blur;
    GaussianBlur( img, blur, Size(3, 3), 0, 0, BORDER_DEFAULT );
    Mat blurGray;
    cvtColor( blur, blurGray, COLOR_BGR2GRAY );
    Mat abs_dst;
    Laplacian( blurGray, abs_dst, CV_16S, 3, 1, 0, BORDER_DEFAULT );
    convertScaleAbs( abs_dst, abs_dst );
    imwrite("/home/bmirisola/Pictures/blurfilter.jpg", blur);
    imwrite("/home/bmirisola/Pictures/laplacian.jpg", abs_dst);

    imshow("Laplacian Operator (Edge Detection)", abs_dst);
    imshow("Filter", blur);
    waitKey(0);
    destroyAllWindows();
}

int main(){
    //problem1();
    //problem2();
    problem3();
    return 1;
}
