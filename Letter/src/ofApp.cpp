#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//��{�ݒ�
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackgroundHex(0x000000);
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	//box2d������
	box2d.init();
	box2d.setGravity(0, 5);
	box2d.createBounds(0, 0, ofGetWidth(), ofGetHeight());
	box2d.setFPS(30.0);
	//font�ݒ�
	//font.loadFont("georgia.ttf", 60); //font�ǂݍ���
	
}

//--------------------------------------------------------------
void ofApp::update(){
	box2d.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0;i < letters.size();i++) {
		//ofFill(); //�h��Ԃ�����
		//ofSetColor(0, 127, 255);
		letters[i].get()->draw();
		
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		//�p�[�e�B�N������
		for (int i = 0;i < letters.size();i++) {
			letters[i].get()->destroy();
		}
		letters.clear();
	}
	else {
		ofPtr<CustomLetter> letter = ofPtr<CustomLetter>(new CustomLetter);
		letter.get()->setPhysics(10.0, 0.1, 0.5);
		letter.get()->scale = ofRandom(0.5, 2.0);
		letter.get()->font.loadFont(FONT, 60*letter.get()->scale);
		letter.get()->letter = char(key);
		ofRectangle rect = letter.get()->font.getStringBoundingBox(&letter.get()->letter, 0, 0);
		letter.get()->w = rect.width;
		letter.get()->h = rect.height;
		letter.get()->setup(box2d.getWorld(), ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()),
			letter.get()->w, letter.get()->h);
		letters.push_back(letter);
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
