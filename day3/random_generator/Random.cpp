#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <iostream>
using namespace cv;
using namespace std;
int Drawing_Random_Lines(Mat image, char* window_name, RNG rng);
int Display_Random_Text(Mat image, char* window_name, RNG rng);
int Display_Big_End(Mat image, char* window_name, RNG rng);

static Scalar randomColor( RNG& rng )
{
    int icolor = (unsigned) rng;
    return Scalar( icolor&255, (icolor>>8)&255, (icolor>>16)&255 );
}


int main(){
    RNG rng(0xFFFFFFFF);
    int window_height = 400;
    int window_width = 400;
    char window_name[] = "image: ";
    
    Mat image = Mat::zeros(window_height, window_width, CV_8UC3);
    imshow(window_name, image);

    int c = Drawing_Random_Lines(image, window_name, rng);
    if (c != 0) return 0;

    c = Display_Random_Text( image, window_name, rng );
    if( c != 0 ) return 0;
    c = Display_Big_End( image, window_name, rng );
    int k = waitKey(0);
    return 0;
}


int Drawing_Random_Lines(Mat image, char* window_name, RNG rng){

    int lineType = 8;
    Point pt1, pt2;

    for (int i = 0; i < 100; i++){
        pt1.x = rng.uniform(0, 400);
        pt1.y = rng.uniform(0, 400);
        pt2.x = rng.uniform(0, 400);
        pt2.y = rng.uniform(0, 400);

        line(image, pt1, pt2, randomColor(rng), rng.uniform(1, 10), 8);
        imshow(window_name, image);
        if(waitKey(0) == '0'){
            return -1;
        }
    }

    return 0;
}

int Display_Random_Text(Mat image, char* window_name, RNG rng){
    int lineType = 8;
    multiply(image,  Scalar::all(0.2), image);

    for (int i = 0; i < 100; i++){
        Point org;
        org.x = rng.uniform(-200, 200);
        org.y = rng.uniform(0, 400);

        putText(image, "Testing text Randering", org, rng.uniform(0, 8),
            rng.uniform(0, 100)*0.05+0.1, randomColor(rng), rng.uniform(1, 10), lineType);

        imshow(window_name, image);
        if(waitKey(0) == '0'){
            return -1;
        }
    }

    return 0;
}

int Display_Big_End(Mat image,  char * window_name, RNG rng){
    Size textsize = getTextSize("OpenCV forever!", FONT_HERSHEY_COMPLEX, 3, 5, 0);
    Point org((400 - textsize.width)/2, (400 - textsize.height)/2);
    int lineType = 8;
    multiply(image,  Scalar::all(0.2), image);

    Mat image2;

    for (int i = 0; i < 255; i+=2){
        image2 = image - Scalar::all(i);
        putText(image2, "Opencv Forever!", org, FONT_HERSHEY_COMPLEX, 3, Scalar(i, i, 255),
            5, lineType);
        
        imshow(window_name, image2);
        if (waitKey(0) == '0'){
            return -1;
        }
    }  
    return 0;
}