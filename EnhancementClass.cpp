//
//  EnhancementClass.cpp
//  OpenCv
//
//  Created by Shokhina Badrieva on 5/4/21.
//  Copyright © 2021 Shokhina Badrieva. All rights reserved.
//

#include "EnhancementClass.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

bool negativeImg(Mat&src,Mat&dst){
    
    
    int imgRows,imgCols;
    
    if(src.empty())
    {
        cout<<"Input image is empty!";
        return false;
    }
    
    
    imgRows = src.size().height;
    imgCols = src.size().width;
    dst = Mat::zeros(imgRows, imgCols, CV_8UC1);
    
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            dst.at<uchar>(i,j)=255-src.at<uchar>(i,j);
        }
    }
    
    return true;
    
}

bool gammaCorrect(Mat&src,Mat&dst,double gamma){
    
    
    int imgRows,imgCols;
    
    if(src.empty())
    {
        cout<<"Input image is empty!";
        return false;
    }
    
    
    imgRows = src.size().height;
    imgCols = src.size().width;
    dst = Mat::zeros(imgRows, imgCols, CV_8UC1);
    
    for(int i=0;i<imgRows;i++){
        for(int j=0;j<imgCols;j++){
            
            double value=(src.at<uchar>(i,j))/255.0;
            dst.at<uchar>(i,j)=pow(value,gamma)*255;

        }
    }
    
    return true;
    
}


bool logTransform(Mat &src, Mat &dst){
    float c=255/log(256);
    if(src.empty())
    {
        cout<<"Input image is empty!";
        return false;
    }
    
    int imgRows = src.size().height;
    int imgCols = src.size().width;
    dst = Mat::zeros(imgRows, imgCols, CV_8UC1);
    
    double val = 0.0;
    for (int i = 0; i < imgRows; i++)
    {
        for (int j = 0; j < imgCols; j++)
        {

            val = c*log((1.0 + src.at<uchar>(i, j)));
            //cout<<val<<endl;
            /*
            if(val<0){
                val=0;
            }
            else if(val>255){
                val=255;
            }
            */
            dst.at<uchar>(i, j) = val;
        }
    }


    return true;
}

bool contrastStretching(Mat &src,Mat &dst){
    if(src.empty())
    {
        cout<<"Input image is empty!";
        return false;
    }
    
    int imgRows = src.size().height;
    int imgCols = src.size().width;
    dst = Mat::zeros(imgRows, imgCols, CV_8UC1);
    double min,max;
    minMaxLoc(src, &min, &max);
    
    dst=(src-min)*(255.0/(max-min));
    
    return true;
}
