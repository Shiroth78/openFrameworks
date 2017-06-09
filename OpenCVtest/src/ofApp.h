#pragma once

#include "ofMain.h"
#include "ofxOpenCV.h"

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

		ofVideoGrabber vidGrabber; //�r�f�I����
		ofxCvColorImage colorImg; //OpenCV�Ŏg���J���[�C���[�W
		ofxCvGrayscaleImage grayImg; //�O���[�X�P�[���C���[�W
		ofxCvGrayscaleImage grayBg; //�O���[�X�P�[���w�i
		ofxCvGrayscaleImage grayDiff; //�O���[�X�P�[���w�i����
		ofxCvContourFinder contourFinder; //�֊s���o

		bool bLearnBakground; //�w�i���L�^�������ǂ���
		int threshold; //臒l
		
};
