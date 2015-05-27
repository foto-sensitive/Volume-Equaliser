

#ifndef emptyExample_Equalizer_h
#define emptyExample_Equalizer_h

#include "Equa.h"
#include "ofMain.h"

class Equalizer {
public:

    //Constructor
    Equalizer();

    void draw(int x, int y, bool verticle);

    float peak, thre, threF;

    int w, h;

    Equa equa;

};

#endif
