#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char** argv){
    Mat src, dst;
    Mat kernel;
    Point anchor;
    double delta;
    int ddepth;
    int kernel_size;

    const char* window_name = "Filter2d Demo";
    const char* imageName = argc > 1 ? argv[1] : "lena.jpg";

    src = imread(samples::findFile(imageName), IMREAD_COLOR);
    if(src.empty()){
        printf(" Error opening image\n");
        printf(" Program Arguments: [image_name -- default lena.jpg] \n");
        return EXIT_FAILURE;
    }

    anchor = Point(-1, -1);
    ddepth = -1;
    delta = 0;

    int ind = 0;

    for(;;){
        kernel_size = 3 + 2* (ind%5);

        kernel = Mat::ones(kernel_size, kernel_size, CV_32F)/(float) (kernel_size * kernel_size);

        filter2D(src, dst, ddepth, kernel, anchor, delta, BORDER_DEFAULT);

        imshow(window_name, dst);

        char c = (char)waitKey(500);
        // Press 'ESC' to exit the program
        if( c == 27 )
        { break; }
        ind++;

    }

    return 0;
}