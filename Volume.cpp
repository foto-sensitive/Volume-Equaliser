









#include "Equa.h"
#include "ofMain.h"

Equa::Equa(){
 w = 20;
 mag = 30;



}

void Equa::draw(int x, int y, bool verticle){

    ofColor(255);

    mag = ofMap(ofGetMouseX(), 0, ofGetWindowWidth(), 0, 30);

    if(verticle){
    for(int i = 0; i < mag; i++){
    ofRect((x)+i*4,y-w/2,2,w);
    }
    }else{
    for(int i = 0; i < mag; i++){
    ofRect(x-w/2,(y)-i*4,w,2);
    }
    }


}



