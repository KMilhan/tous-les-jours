//
//  main.cpp
//  HeadTrackingApiMacPort
//
//  Created by 김밀한 on 13. 4. 10..
//  Copyright (c) 2013년 TLJ. All rights reserved.
//

#include "core.h"
#include  <iostream>

#define DEBUG_MODE true

int main(int argc, const char * argv[])
{   
  
     
    core headTrackingCore(DEBUG_MODE);

    
//    cvNamedWindow("Left Image");
//    cvNamedWindow("Right Image");
    
    CvRect * leftFace = 0;
    CvRect * rightFace = 0;
//    
//    IplImage* image1 = 0;
//    IplImage* image2 = 0;
    
    while(true){
        headTrackingCore.grabFrame();
        
//        image1 = headTrackingCore.getLeftImage();
//        image2 = headTrackingCore.getRightImage();
        
        leftFace = headTrackingCore.getLeftFaceRegion();
        rightFace = headTrackingCore.getRightFaceRegion();
        if((bool)leftFace)
            std::cout<<"left : "<<leftFace->x<<","<<leftFace->y<<std::endl;
        if((bool)rightFace)
            std::cout<<"right : "<<rightFace->x<<","<<rightFace->y<<std::endl;

//        if((bool)leftFace){
//        cvRectangle(image1, cvPoint(leftFace->x,leftFace->y), cvPoint(leftFace->x + leftFace->width, leftFace->y + leftFace->height), cvScalar(0,255,0),3,CV_AA,0);
//        }
//        if((bool)rightFace){
//        cvRectangle(image2, cvPoint(rightFace->x,rightFace->y), cvPoint(rightFace->x + rightFace->width, rightFace->y + rightFace->height), cvScalar(0,255,0),3,CV_AA,0);
//        }
//        cvShowImage("Left Image", headTrackingCore.leftImage);
//        cvShowImage("Right Image", headTrackingCore.rightImage);
    }
	
    return 0;
}

