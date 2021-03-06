#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void show_wait_destroy(const char* winname, Mat img);

int main(int argc,char** argv){
    CommandLineParser parser(argc, argv, "{@input | notes.jpg | input image}");
    Mat src = imread(samples::findFile(parser.get<String>("@input")), IMREAD_COLOR);

    if (src.empty()){
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }

    imshow("src", src);

    Mat gray;
    if (src.channels() == 3){
        cvtColor(src, gray, COLOR_BGR2GRAY);
    } else {
        gray = src;
    }

    show_wait_destroy("gray", gray);

    Mat bw;
    adaptiveThreshold(~gray, bw, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);
    show_wait_destroy("binary", bw);

    Mat horizontal = bw.clone();
    Mat vertical = bw.clone();

    int horizontal_size = horizontal.cols/30;

    Mat horizontalStructure = getStructuringElement(MORPH_RECT, Size(horizontal_size, 1));
    erode(horizontal, horizontal, horizontalStructure, Point(-1, -1));
    dilate(horizontal, horizontal, horizontalStructure, Point(-1, -1)); 

    show_wait_destroy("horizontal", horizontal);

    int vertical_size = vertical.rows/30;

    Mat verticalStructure = getStructuringElement(MORPH_RECT, Size(1, vertical_size));
    erode(vertical, vertical, verticalStructure, Point(-1, -1));
    dilate(vertical, vertical, verticalStructure, Point(-1, -1)); 

    show_wait_destroy("vertical", vertical);

    bitwise_not(vertical, vertical);
    show_wait_destroy("vertical bit", vertical);

    Mat edges;
    adaptiveThreshold(vertical, edges, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 3, -2);
    show_wait_destroy("edges", edges);

    Mat kernel = Mat::ones(2, 2, CV_8UC1);
    dilate(edges, edges, kernel);
    show_wait_destroy("dilate", edges);

    Mat smooth;
    vertical.copyTo(smooth);

    blur(smooth, smooth, Size(2, 2));
    smooth.copyTo(vertical, edges);

    show_wait_destroy("smooth - final", vertical);
    return 0;

}


void show_wait_destroy(const char* winname, Mat img){
    imshow(winname, img);
    moveWindow(winname, 500, 0);
    waitKey(0);
    destroyWindow(winname);
}
