#include "ofApp.h"

using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    
    namedWindow("bgmodel");
    //namedWindow("foreground");
    //namedWindow("input");
    
    createTrackbar("Buffer Size", "bgmodel", &buffer, 500);
    
    
    // Open webcam
    cap.open(0);
    
    // If webcam cannot be opened
    if (!cap.isOpened()) {
        std::cout << "Cannot open device" << std::endl;
        std::exit(1);
    }
    
    
    cap >> frame;
    average = Mat::zeros(frame.size(), CV_32FC3);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Read frame from video capture object
    cap >> frame;

    accumulateWeighted(frame, average, alpha);
    convertScaleAbs(average, scaled);
    
    // Deal with zero case
    if (buffer == 0) {
        buffer = 1;
    }
    
    alpha = 1.0/buffer;
    
    cout << "Buffer is at " << buffer << endl;
    //cout << "Alpha is at " << alpha << endl;
    //cout << "Weight is at " << 1.0 - index/200.0 << endl;
   
   

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    imshow("bgmodel", scaled);
    /*resize(frame, resized2, resized2.size(), 0.5, 0.5);
    imshow("input", resized2);
   
    resize(scaled, resized, resized.size(), 0.5, 0.5);
    imshow("bgmodel", resized);
    
    filename = "bgmovingavg.png";
    imwrite(filename, resized);*/
    
    waitKey(1);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
