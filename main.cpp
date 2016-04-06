#include <cv.h>	
#include <highgui.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <functional>
#include <vector>
#include "SSIM.h"
#include "Ostromoukhov01.h"
#include "SAHalftoner.h"

using namespace std;

int main(int argc, char** argv)
{
	if(argc!=3){
		cout<<"Usage: cvHalftone source_path output_path"<<endl;
		return -1;
	}
	cv::Mat im = cv::imread(argv[1], 0);
    SAHer saher(im);
    saher.ComputeSAH();
    cv::Mat resImg = saher.GetResult();
    //cv::imshow("result", resImg);
    resImg.convertTo(resImg, CV_8UC3, 255.0);
    cv::imwrite(argv[2], resImg);
    cv::waitKey();
	return 0;
}
