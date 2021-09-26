#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat dst, cdst, cdstP;

    const char* default_file = "smarties.png";
    const char* filename = argc > 1 ? argv[1] : default_file;

    Mat src = imread(samples::findFile(filename), IMREAD_COLOR);
    // Check if image is loaded fine
    if(src.empty()){
        printf(" Error opening image\n");
        printf(" Program Arguments: [image_name -- default %s] \n", default_file);
        return -1;
    }

    Mat gray;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    medianBlur(gray, gray, 5);

    vector<Vec3f> circles;
    HoughCircles(gray, circles, HOUGH_GRADIENT, 1, gray.rows/16, 100, 22, 1, 100);

    for(size_t i=0;i<circles.size(); i++){
        Vec3i c = circles[i];
        Point center(c[0], c[1]);
        circle(src, center, 1, Scalar(0, 255, 0), 3, LINE_AA);
        circle(src, center, c[2], Scalar(0, 0, 255), 3, LINE_AA);
    }

    imshow("Source", src);

    waitKey();
    return 0;
}