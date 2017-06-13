#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
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

		//ofxOpenCvŠÖŒW
		ofVideoGrabber vidGrabber; //video“ü—Í
		ofxCvColorImage colorImg; //color image
		ofxCvGrayscaleImage grayImg; //gray scale image
		ofxCvGrayscaleImage grayBg; //background image
		ofxCvGrayscaleImage grayDiff; //difference image
		ofxCvContourFinder contourFinder;
		bool bLearnBakground;
		int threshold;

		//ofxBox2DŠÖŒW
		ofxBox2d box2d;
		vector <ofPtr<CustomCircle>> circles;
		vector <ofPtr<ofxBox2dRect>> rects;
		vector <ofPtr<ofxBox2dCircle>> contourCircles;

		
};
