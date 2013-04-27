//
//  core.h
//  HeadTrackingApiMacPort
//
//  Created by 김밀한 on 13. 4. 26..
//  Copyright (c) 2013년 TLJ. All rights reserved.
//

#ifndef HeadTrackingApiMacPort_core_h
#define HeadTrackingApiMacPort_core_h
#include <opencv2/opencv.hpp>
//#include <opencv2/opencv_modules.hpp>
//#include <opencv2/highgui/highgui.hpp>

class core{
public:
    core(bool debugMode); // in case of Debugging Mode
    core(); // in case of Normal mode
    
    
    void getSources(); // get Streaming source (cam, or files(Debugging))
    void grabFrame(); // grab a frame from sources
private:
    void setFacialDetecting(); // Grab a memory for Facial Detecting
    bool debugMode; // tell whether in debugging mode or not
    
public:
    CvRect* getLeftFaceRegion();
    CvRect* getRightFaceRegion();
    
    
    
    
    CvCapture * source1, * source2; // Image Source
    IplImage * leftImage, * rightImage; // Streaming image
    IplImage * getLeftImage();
    IplImage * getRightImage();
    
    const char *faceClassifierLocation = "/Users/Mill/Downloads/Face Detector Lib.zip Folder/faces.xml";
    const char *eyeClassifierLocation = "/opt/local/share/OpenCV/haarcascades/haarcascade_eye.xml";

    CvHaarClassifierCascade* cascadeLeftFace = 0; // for the face in Left cam
    CvHaarClassifierCascade* cascadeRightFace = 0; // in Right one

	CvHaarClassifierCascade* cascadeLeftEye = 0; // Left eye
    CvHaarClassifierCascade* cascadeRightEye = 0; // Right eye
    
    CvMemStorage* storageLeftFace = 0;  // Storage for detected eyes and faces
    CvMemStorage* storageRightFace = 0;
    CvMemStorage* storageLeftEye = 0;
    CvMemStorage* storageRightEye = 0;
    CvSeq *leftFaces = 0;
    CvSeq *rightFaces = 0;

    
};

#endif
