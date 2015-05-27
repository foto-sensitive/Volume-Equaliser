#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

     firstSound.setup();

}

//--------------------------------------------------------------
void ofApp::update(){

    firstSound.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(88);

    if(volOn){
            dist = (pmouseX - ofGetMouseX())*-1;
            myVol.equa.mouseX = pVol + (dist*1.5);
            myVol.c = ofColor(255);
    }else{
           myVol.c = ofColor(255, 50);
    }

    myVol.draw(ofGetWindowWidth()*0.15, ofGetWindowHeight()/2);


    myEqua1.equa.mouseX = ofMap(firstSound.fftSmoothed[6], 0, 1, 0, ofGetWindowWidth());
    myEqua2.equa.mouseX = ofMap(firstSound.fftSmoothed[7], 0, 1, 0, ofGetWindowWidth());
    myEqua3.equa.mouseX = ofMap(firstSound.fftSmoothed[8], 0, 1, 0, ofGetWindowWidth());

    myEqua1.draw(ofGetWindowWidth()*0.75, ofGetWindowHeight()*0.98);
    myEqua2.draw(ofGetWindowWidth()*0.7725, ofGetWindowHeight()*0.98);
    myEqua3.draw(ofGetWindowWidth()*0.795, ofGetWindowHeight()*0.98);




    ofSetColor(255);




    ofDrawBitmapString(toString(dist), ofGetWindowWidth()*0.85, ofGetWindowHeight()*0.1);

    ofRect(0, ofGetWindowHeight()*0.8, myVol.perc,myVol.perc);



}

//Converts integers to strings
string ofApp::toString(float i){
    string Result;          // string which will contain the result
    ostringstream convert;   // stream used for the conversion
    convert << i;      // insert the textual representation of 'Number' in the characters in the stream
    Result = convert.str(); // set 'Result' to the contents of the stream
    return Result;
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 'v'){
        volOn = true;
        dist = 0;
        if(!getDistOnce){
        pmouseX = ofGetMouseX();
        pmouseY = ofGetMouseY();
        pVol = myVol.equa.mouseX;
        }
        getDistOnce = true;
    }

    if(key == 'p'){
    firstSound.sound.play();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if(key == 'v'){
        volOn = false;
        pmouseX = 0;
        pmouseY = 0;
        dist = 0;
        getDistOnce = false;
    }

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
