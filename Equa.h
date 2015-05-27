

#ifndef emptyExample_Equa_h
#define emptyExample_Equa_h
#include "ofMain.h"

class Equa {
public:

    //Constructor
    Equa();

    void draw(int x, int y, int w, int h, bool verticle);

    float w, h;

    float mag, magFinal, spacing;

    float ofConstrain(float amt, float low, float high);

    int mouseX;





};

#endif
