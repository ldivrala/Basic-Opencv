#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]){
    CommandLineParser parser(argc, argv, "{@input  |lena.jpg|input image}"
                                        "{ksize k|3|ksize (hit 'K' to increase its value at run time)}"
                                        "{scale s|1|scale (hit 'S' to increase its value at run time)}"
                                        "{delta d|0|delta (hit 'D' to increase its value at run time)}"
                                        "help h|false|show help message");
    
    cout << "Laplascian" << endl;
    parser.printMessage();
    cout << "press ESC to exit.\npress 'R' to reset values." << endl;

    Mat image, src, src_gray;
    Mat grad;
    const string window_name = "Laplace Simple Demo";
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

        Mat dst;
        Laplacian(src_gray, dst, ddepth, ksize, scale, delta, BORDER_DEFAULT);

        

        convertScaleAbs(dst, dst);
        imshow(window_name, dst);
        char key = (char)waitKey(0);
        if(key == 27)
        {
            return EXIT_SUCCESS;
        }
        if (key == 'k' || key == 'K')
        {
            ksize = ksize < 30 ? ksize+2 : 1;
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
            ksize = 1;
            delta =  0;
        }
    }
    return 0;
}