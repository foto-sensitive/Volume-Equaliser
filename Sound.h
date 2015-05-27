//
//  Sound.h
//  emptyExample
//
//  Created by Tomas on 28/01/2015.
//
//
#include "ofMain.h"
#ifndef emptyExample_Sound_h
#define emptyExample_Sound_h

class Sound{

public:
    
    Sound();
    
void setup();
void draw();
void update();
void keyPressed();


/*----------------AUDIO STUFF--------------------*/
ofSoundPlayer sound;
float audioPan, audioPanMax;
float avgSound;
float *fftSmoothed;
int nBandsToGet;

//------------------------------------------------//

/*-------------MULTI-USE VARIABLES---------------*/
float counter;
float roll;
ofColor background;
ofColor rainbow;
float hue;
ofColor interp;
float interpAmt;

//------------------------------------------------//

/*-----------DRAWING VARIABLES FROM TOMAS--------*/
ofImage texture, noise;
ofShader shader, texturizer, blur;


ofFbo bgFbo, scene, final;

//------------------------------------------------//




};
#endif
