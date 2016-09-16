#pragma once

#include "ofMain.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include "ofxKinect.h"

class ofApp : public ofBaseApp{

public:
    void setup(); 
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    
    cv::VideoCapture    cap;
    cv::Mat             frame;
    cv::Mat             average;
    cv::Mat             scaled;
    cv::Mat             resized;
    cv::Mat             resized2;
    
    int     index = 0;
    int     buffer = 230;
    float   curWeight = 0;
    float   threshold = 30;
    float   alpha = 1.0/buffer;
    
    string  filename;
    
    

};
