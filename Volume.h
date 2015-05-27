

#ifndef emptyExample_Volume_h
#define emptyExample_Volume_h

#include "Equa.h"
#include "ofMain.h"

class Volume {
public:

    //Constructor
    Volume();

    void draw(int x, int y);

    string toString(float i);

    int w, h;

    ofColor c;

    float perc;

    Equa equa;

};

#endif
