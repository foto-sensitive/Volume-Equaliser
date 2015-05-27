#pragma once

#include "Equalizer.h"
#include "Volume.h"
#include "Sound.h"
#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		string toString(float i);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		Equalizer myEqua1;
		Equalizer myEqua2;
		Equalizer myEqua3;
		Volume myVol;

		Sound firstSound;

		bool volOn, getDistOnce;
		int dist, pmouseX, pmouseY, pVol;

};
