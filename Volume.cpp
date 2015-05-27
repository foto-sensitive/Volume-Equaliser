









#include "Volume.h"
#include "ofMain.h"

Volume::Volume(){

  w = ofGetWindowHeight()*0.2;
  h = ofGetWindowWidth()*0.006;
  equa.magFinal = 60;
  equa.spacing = ofGetWindowWidth()*0.012;
  equa.mouseX = 250;


}

void Volume::draw(int x, int y){


    ofSetColor(c);


    equa.draw(x, y, w, h,true);

    perc = ofMap(equa.mag, 0, equa.magFinal, 0, 100);
    ofDrawBitmapString(toString(perc)+"%", ofGetWindowWidth()*0.75, ofGetWindowHeight()*0.625);


}

//Converts integers to strings
string Volume::toString(float i){
    string Result;          // string which will contain the result
    ostringstream convert;   // stream used for the conversion
    convert << i;      // insert the textual representation of 'Number' in the characters in the stream
    Result = convert.str(); // set 'Result' to the contents of the stream
    return Result;
}



