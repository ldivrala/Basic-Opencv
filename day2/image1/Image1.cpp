#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>

#include <iostream>

using namespace cv;

int main(){
    std::string image_path = "lena.jpg";
    Mat img = imread(image_path, IMREAD_COLOR);

    if (img.empty()){
        std::cout << "Could not read the image:" << image_path << std::endl;
        return 1;
    }

    imshow("Display Image:", img);

    int k = waitKey(0);

    if (k == 's'){
        imwrite("starry_night.png", img);
    }
    
    return 0;
}