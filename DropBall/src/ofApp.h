#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "CustomCircle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxBox2d box2d;
		//vector <shared_ptr<ofxBox2dCircle>> circles;
		//vector <ofPtr<ofxBox2dCircle>> circles;
		//vector <ofxBox2dCircle> circles;
		
		vector <ofPtr<CustomCircle>> circles;
		vector <ofPtr<ofxBox2dRect>> rects;
		int rectnum = 100;
};
