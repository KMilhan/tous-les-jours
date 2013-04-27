//
//  core.cpp
//  HeadTrackingApiMacPort
//
//  Created by 김밀한 on 13. 4. 26..
//  Copyright (c) 2013년 TLJ. All rights reserved.
//

#include "core.h"

core::core(bool debug){
    if(debug==true){
        (*this).debugMode = debug; // set to debugging mode
        std::cout<<"Debug mode set";
    }
    else{
        (*this).debugMode = debug;
        std::cout<<"Debug Mode unset";
    }
    std::cout<<this->debugMode;
    getSources(); // get source
    setFacialDetecting(); // set Face and Eye detecting service
}
void core::getSources(){
    std::cout<<this->debugMode;
    if(debugMode){
        this->source1 = cvCreateFileCapture("/Users/Mill/Pictures/Photo Booth Library/Pictures/left1.mov");
        this->source2 = cvCreateFileCapture("/Users/Mill/Pictures/Photo Booth Library/Pictures/right1.mov");
    }
    else{
        this->source1 = cvCreateCameraCapture(0);//
        this->source2 = cvCreateCameraCapture(0);//
    }
     
    
//    this->leftImage = cvRetrieveFrame(source1); // grab a frame from source one by one
//    this->rightImage = cvRetrieveFrame(source2);
   
        //TODO:: NORMAL CAMERA CAPTURE
}

void core::grabFrame(){
    std::cout<<"Grabiing Frame"<<std::endl;
    cvGrabFrame(this->source1);
    cvGrabFrame(this->source2);
    this->leftImage = cvRetrieveFrame(this->source1); // grab a frame from source one by one
    this->rightImage = cvRetrieveFrame(this->source2);
    
    //Face Detection/*
    this->leftFaces = cvHaarDetectObjects(this->leftImage, this->cascadeLeftFace, this->storageLeftFace, 1.2, 25, CV_HAAR_DO_CANNY_PRUNING, cvSize(100, 100));
    this->rightFaces = cvHaarDetectObjects(this->rightImage, this->cascadeRightFace, this->storageRightFace, 1.2, 25, CV_HAAR_DO_CANNY_PRUNING, cvSize(100, 100));
}

IplImage * core::getLeftImage(){
    cvGrabFrame(source1);
    return cvRetrieveFrame(source1);
}

IplImage * core::getRightImage(){
    cvGrabFrame(source2);
    return cvRetrieveFrame(source2);
}

CvRect * core::getLeftFaceRegion(){
    return (CvRect*) cvGetSeqElem(this->leftFaces,0);
}

CvRect * core::getRightFaceRegion(){
    return (CvRect*) cvGetSeqElem(this->rightFaces, 0);
}

void core::setFacialDetecting(){
    this->cascadeLeftFace = (CvHaarClassifierCascade*) cvLoad(core::faceClassifierLocation, 0, 0, 0 ); //Xml file input
    this->cascadeRightFace = (CvHaarClassifierCascade*) cvLoad(core::faceClassifierLocation, 0, 0, 0 );
    this->cascadeLeftEye = (CvHaarClassifierCascade*) cvLoad(core::eyeClassifierLocation, 0, 0, 0 );
    this->cascadeRightEye =(CvHaarClassifierCascade*) cvLoad(core::eyeClassifierLocation, 0, 0, 0 ); // Xml file input
 
    
         //Set memory
    this->storageLeftFace = cvCreateMemStorage(0);
    this->storageRightFace = cvCreateMemStorage(0);
    
//TODO::for Eye
}