









#include "Equa.h"
#include "ofMain.h"

Equa::Equa() {

  mag = 30;
}

void Equa::draw(int x, int y, int w, int h, bool verticle) {

  ofColor(255);

  mag = ofMap(mouseX, 0, ofGetWindowWidth(), 0, magFinal);
  mag = ofConstrain(mag, 0, magFinal);

  if (verticle) {
    for (int i = 0; i < mag; i++) {
      ofRect((x)+i*spacing, y-w/2, h, w);
    }
  } else {
    for (int i = 0; i < mag; i++) {
      ofRect(x-w/2, (y)-i*spacing, w, h);
    }
  }

}

float Equa::ofConstrain(float amt, float low, float high) {
	return (amt < low) ? low : ((amt > high) ? high : amt);
}


