//
//  EnhancementClass.hpp
//  OpenCv
//
//  Created by Shokhina Badrieva on 5/4/21.
//  Copyright © 2021 Shokhina Badrieva. All rights reserved.
//

#ifndef EnhancementClass_hpp
#define EnhancementClass_hpp

#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

bool negativeImg(Mat&src,Mat&dst);
bool logTransform(Mat &src, Mat &dst);
bool gammaCorrect(Mat&src,Mat&dst,double gamma);
bool contrastStretching(Mat &src,Mat &dst);


#endif /* EnhancementClass_hpp */
