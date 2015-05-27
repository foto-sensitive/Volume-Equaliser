









#include "Equalizer.h"
#include "ofMain.h"

Equalizer::Equalizer(){

  w = 20;
  h = 2;
  equa.mouseX = 0;


}

void Equalizer::draw(int x, int y){


    ofSetColor(255);



    equa.magFinal = 30;
    equa.spacing = 4;
    equa.draw(x, y, w, h,false);

    ofColor c;

    if(equa.mag > peak){
      peak = equa.mag;
      c = ofRandom(255);
    }
    //Decreasing Threshold
    thre-=0.001;
    if(equa.mag > thre){
      thre = equa.mag;
      c = ofRandom(255);
    }
        //Decreasing Threshold
    threF-=0.005;
    if(equa.mag > threF){
      threF = equa.mag;
      c = ofRandom(255);
    }
    //Peak
    ofSetColor(255,0,0);
    ofRect(x-w/2,(y)-peak*4,w,h);

    //Threshold
    ofSetColor(0,0,255);
    ofRect(x-w/2,(y)-thre*4,w,h);


    //Threshold Faster
    ofSetColor(0,255,0);
    ofRect(x-w/2,(y)-threF*4,w,h);


    ofSetColor(c);
    ofRect(0,0,50,50);



}



