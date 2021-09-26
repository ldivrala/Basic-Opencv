#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]){
    CommandLineParser parser(argc, argv, "{@input  |lena.jpg|input image}"
                                        "{ksize k|1|ksize (hit 'K' to increase its value at run time)}"
                                        "{scale s|1|scale (hit 'S' to increase its value at run time)}"
                                        "{delta d|0|delta (hit 'D' to increase its value at run time)}"
                                        "help h|false|show help message");
    
    cout << "Sobel & Scharr" << endl;
    parser.printMessage();
    cout << "press ESC to exit.\npress 'R' to reset values." << endl;

    Mat image, src, src_gray;
    Mat grad;
    const string window_name = "Sobel Simple Demo";
    int ksize = parser.get<int>("ksize");
    int scale = parser.get<int>("scale");
    int delta = parser.get<int>("delta");
    int ddepth = CV_16S;

    String imageName = parser.get<String>("@input");
    image = imread( samples::findFile( imageName ), IMREAD_COLOR ); // Load an image
    // Check if image is loaded fine
    if( image.empty() )
    {
        printf("Error opening image: %s\n", imageName.c_str());
        return EXIT_FAILURE;
    }

    for(;;){
        GaussianBlur(image, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
        
        cvtColor(src, src_gray, COLOR_BGR2GRAY);

        Mat grad_x, grad_y;
        Mat abs_grad_x, abs_grad_y;

        Sobel(src_gray, grad_x, ddepth, 1, 0, ksize, scale, delta, BORDER_DEFAULT);

        Sobel(src_gray, grad_y, ddepth, 0, 1, ksize, scale, delta, BORDER_DEFAULT);

        convertScaleAbs(grad_x, abs_grad_x);
        convertScaleAbs(grad_y, abs_grad_y);

        addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
        imshow(window_name, grad);
        char key = (char)waitKey(0);
        if(key == 27)
        {
            return EXIT_SUCCESS;
        }
        if (key == 'k' || key == 'K')
        {
            ksize = ksize < 30 ? ksize+2 : -1;
        }
        if (key == 's' || key == 'S')
        {
            scale++;
        }
        if (key == 'd' || key == 'D')
        {
            delta++;
        }
        if (key == 'r' || key == 'R')
        {
            scale =  1;
            ksize = -1;
            delta =  0;
        }
    }
    return 0;
}