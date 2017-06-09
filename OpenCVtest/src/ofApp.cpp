#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);

	vidGrabber.initGrabber(320, 240); //ビデオ取り込み初期化
	colorImg.allocate(320, 240); //OpenCV解析用カラー画像領域確保
	grayImg.allocate(320, 240); //グレースケール用
	grayBg.allocate(320, 240);
	grayDiff.allocate(320, 240);
	
	bLearnBakground = true;
	threshold = 100;

}

//--------------------------------------------------------------
void ofApp::update(){
	bool bNewFrame = false;
	vidGrabber.update();
	bNewFrame = vidGrabber.isFrameNew();
	if (bNewFrame) {
		//colorImg.setFromPixels(vidGrabber.getPixels(), 320, 240);
		colorImg.setFromPixels(vidGrabber.getPixels());
		grayImg = colorImg;
		//新規に背景記録
		if (bLearnBakground == true) {
			grayBg = grayImg;
			bLearnBakground = false;
		}
		grayDiff.absDiff(grayBg, grayImg); //差分絶対値取得
		grayDiff.threshold(threshold); //閾値で二値化
		contourFinder.findContours(grayDiff, 20, (340 * 260) / 3, 10, true); //輪郭抽出finderContours(画像、最小エリア、最大エリア、物体数、穴を検出するか）
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	colorImg.draw(10, 10);
	grayImg.draw(340, 10);
	grayBg.draw(10, 260);
	grayDiff.draw(340, 260);
	contourFinder.draw(340, 500);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case ' ':
		bLearnBakground = true;
		break;
	case '+':
		threshold++;
		if (threshold > 255) threshold = 255;
		break;
	case '-':
		threshold--;
		if (threshold < 0) threshold = 0;
		break;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
