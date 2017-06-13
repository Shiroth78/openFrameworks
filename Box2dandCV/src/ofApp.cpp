#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);
	ofSetFrameRate(60);
	//CV�֌W
	vidGrabber.initGrabber(320, 240);
	colorImg.allocate(320, 240);
	grayImg.allocate(320, 240);
	grayBg.allocate(320, 240);
	grayDiff.allocate(320, 240);
	bLearnBakground = true;
	threshold = 100;
	//Box2D�֌W
	box2d.init();
	box2d.setGravity(0, 1);
	box2d.createBounds(0, 0, colorImg.width, colorImg.height);
	box2d.checkBounds(true);

	//CustomCircle�z�u
	static const int NUM = 500;
	for (int i = 0;i < NUM;i++) {
		ofPtr<CustomCircle> c = ofPtr<CustomCircle>(new CustomCircle);
		c.get()->setPhysics(1.0, 0.8, 0.0);
		c.get()->setup(box2d.getWorld(), ofRandom(colorImg.width), ofRandom(colorImg.height), 3);
		circles.push_back(c);
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	box2d.update();

	bool bNewFrame = false; //�V�K�Ƀt���[�����擾�������ǂ���
	vidGrabber.update();
	bNewFrame = vidGrabber.isFrameNew();
	//�V�K�t���[���̎���荞��
	if (bNewFrame) {
		colorImg.setFromPixels(vidGrabber.getPixels());
		grayImg = colorImg;
		if (bLearnBakground == true) {
			grayBg = grayImg;
			bLearnBakground = false;
		}
		grayDiff.absDiff(grayBg, grayImg);
		grayDiff.threshold(threshold);
		contourFinder.findContours(grayDiff, 20, (320 * 240) / 3, 10, false);
		//���E���̉~���N���A
		for (int i = 0;i < contourCircles.size();i++) {
			contourCircles[i].get()->destroy();
		}
		contourCircles.clear();
		//���o���ꂽ���̂̐���������
		for (int i = 0;i < contourFinder.nBlobs;i++) {
			for (int j = 0;j < contourFinder.blobs[i].pts.size();j += 4) {
				//�֊s�ɉ����ē��Ԋu�ɍ��W���o
				ofPoint pos = contourFinder.blobs[i].pts[j];
				//�֊s���ɕ��ׂ�ofxBox2dCircle�ǉ�
				ofPtr<ofxBox2dCircle> c = ofPtr<ofxBox2dCircle>(new ofxBox2dCircle);
				c.get()->setup(box2d.getWorld(), pos.x, pos.y, 4);
				contourCircles.push_back(c);
			}
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	float ratioX = ofGetWidth() / 320;
	float ratioY = ofGetHeight() / 240;

	ofPushMatrix(); //���o���ʕ\��
	ofScale((float)ofGetWidth() / (float)grayDiff.width,
		(float)ofGetHeight() / (float)grayDiff.height);
	ofSetColor(255, 255, 255);
	colorImg.draw(0, 0);
	contourFinder.draw();
	//���E���̉~�`��
	ofNoFill();
	ofSetColor(255, 0, 0);
	for (int i = 0;i < contourCircles.size();i++) {
		contourCircles[i].get()->draw();
	}
	//CustomCircle�`��
	for (int i = 0;i < circles.size();i++) {
		circles[i].get()->draw();
	}
	ofPopMatrix();

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
		if (threshold < 0)threshold = 0;
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
