//
//  Sound.cpp
//  emptyExample
//
//  Created by Tomas on 28/01/2015.
//
//

#include <stdio.h>
#include "Sound.h"

Sound::Sound(){


}

void Sound::setup(){


    // initialising values for variables
    counter = 0.0f;
    audioPan = 0.5f;

    //Color variables initialised
    background.set(85,36,57);
    interp.set(222,190,9);
    interpAmt = 0.0f;

    //hue settings for colours
    hue = interp.getHue();

    //music bit initialisation with FFT
    fftSmoothed = new float[8192];
    for (int i = 0; i< 8192; i++){
        fftSmoothed[i]=0;
    }
    nBandsToGet = 128; // bands to get initialisiation

    //loading music
    sound.loadSound("sounds/mix.mp3");
    sound.setVolume(1.0f);
    sound.setLoop(true);


}

void Sound::update(){

    //interpolation between two speaker directions
    audioPanMax = 0.5f;
    if (audioPan <= audioPanMax){
        audioPan += 0.001f;
    }
    sound.setPan(audioPan);

    // background colors
    if (interpAmt <= 1.0f){
        interpAmt += 0.01f;
    }
    background.lerp(interp,interpAmt);
    // update of sound playing
    ofSoundUpdate();


    avgSound = 0;

    //fft smooth calculate averageVolume
    float* val = ofSoundGetSpectrum(nBandsToGet);
    for (int i=0; i<nBandsToGet; i++){
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < val[i]){
            fftSmoothed[i] = val[i];
            avgSound += fftSmoothed[i];
        }
    }
    //average loudness of sound in other words volume
    avgSound /= nBandsToGet;

    //This is how we can use any variable to store something.
    counter +=fftSmoothed[7];
    //set count to 0 once it gets too big
    if(counter >=70){
        counter =0;
    }



    //THESE Two are the same
    if(fftSmoothed[7]){
        //something could happen once fftsmooth raches 7 element
        // like update position of GenObj in class

    }
    if(fftSmoothed[27]){
        //something could happen once fftsmooth raches 27 element do something
        //could be used with class GenObjs rather then cirle or rect
    }


    //If statements for color changes
    if (avgSound > 0.07)
        interp.set(194,42,67);
    else if (avgSound > 0.04)
        interp.set(218,92,68);
    else if (avgSound > 0.01)
        interp.set(236,209,120);
    else
        interp.set(0,100,79);

}





void Sound::draw(){

    //////////////DRAWING CIRCLES WITH FFT


    // first varaible
    ofSetColor(236,209,120);
    float one = (fftSmoothed[1]*70 > 3) ? fftSmoothed[1]*7 : 3;
    ofCircle(100, 150, one);

    // second variable extracted from sound
    ofSetColor(85,36,57);
    float two = (fftSmoothed[7]*75 > 3) ? fftSmoothed[7]*75 : 3;
    ofCircle(200, 150, two);

    // tird variable
    ofSetColor(0,144,180,80);
    float three = (fftSmoothed[27]*150 > 3) ? fftSmoothed[27]*150 : 3;
    ofCircle(300, 150, three);

    // using one of the global variables
    ofSetColor(0,200);
    ofCircle(400,150,counter);

    //another experiment extract them straightaway from fftSmoothend
    ofSetColor(0,hue);
    ofCircle(500,150,fftSmoothed[1]*25);

    //colour chaning examples using another variable called background
    ofSetColor(background, 255);
    ofRect(100,300,100,100);

    //Using hue extract
    ofSetColor(background,hue);
    ofRect(250,300,100,100);

    ofSetColor(interp);
    ofRect(400,300,100,100);


    // Drawing the whole fft in most basic way
    ofSetColor(0, 5, 0, 100);
    float width = (float)(5*128) / nBandsToGet;
    for (int i = 0;i < nBandsToGet; i++){
        ofRect(100+i*width,ofGetHeight()-200,width,-(fftSmoothed[i] * 100));

    }
}

void Sound::keyPressed(){
        //Any key to play music
        sound.play();

    }


