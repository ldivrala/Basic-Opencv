#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat dst, cdst, cdstP;

    const char* default_file = "sudoku.png";
    const char* filename = argc > 1 ? argv[1] : default_file;

    Mat src = imread(samples::findFile(filename), IMREAD_COLOR);
    // Check if image is loaded fine
    if(src.empty()){
        printf(" Error opening image\n");
        printf(" Program Arguments: [image_name -- default %s] \n", default_file);
        return -1;
    }

    Canny(src, dst, 50, 200, 3);

    cvtColor(dst, cdst, COLOR_GRAY2BGR);
    cdstP = cdst.clone();

    vector<Vec2f> lines;
    HoughLines(dst, lines, 1, CV_PI/180, 150, 0, 0);

    for(size_t i=0;i<lines.size(); i++){
        float rho = lines[i][0];
        float theta = lines[i][1];

        double a = cos(theta), b = sin(theta);
        Point pt1, pt2;
        double x0 = rho * a, y0 = rho * b;
        pt1.x = x0 + 1000 * (-b);
        pt1.y = y0 + 1000 * (a);
        pt2.x = x0 - 1000 * (-b);
        pt2.y = y0 - 1000 * (a);

        line(cdst, pt1, pt2, Scalar(0, 0, 255), 1, LINE_AA);
    }

    vector<Vec4i> linesP;
    HoughLinesP(dst, linesP, 1, CV_PI/180, 50, 50, 10);

    for(size_t i=0;i<linesP.size(); i++){
        Vec4i l = linesP[i];
        line(cdstP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, LINE_AA);
    }

    imshow("Source", src);
    imshow("Standard Hough Transform", cdst);
    imshow("Probabilistic Hough Transform", cdstP);

    waitKey();
    return 0;
}