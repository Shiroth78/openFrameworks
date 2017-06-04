#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);
	ofEnableAlphaBlending();

	box2d.init();
	box2d.setGravity(0, 5); //重力設定（ｘに０、ｙに５）
	box2d.createBounds(0, 0, ofGetWidth(), ofGetHeight());
	box2d.setFPS(30);

	//障害物追加
	for (int i = 0;i < rectnum;i++) {
		ofPtr<ofxBox2dRect> r = ofPtr<ofxBox2dRect>(new ofxBox2dRect);
		float w = 2;
		float h = 2;
		float x = ofRandom(50, ofGetWidth() - 50);
		float y = ofRandom(50, ofGetHeight() - 50);
		r.get()->setup(box2d.getWorld(), x, y, w, h);
		rects.push_back(r);
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	box2d.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0;i < circles.size();i++) {
		ofFill(); //塗りつぶしあり
		ofSetColor(0, 127, 255);
		circles[i].get()->draw();
		//circles[i].draw();

	}

	for (int i = 0;i < rects.size();i++) {
		ofFill();
		ofSetColor(255, 63, 63);
		rects[i].get()->draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'c') {
		float r = ofRandom(5, 20);
		ofPtr<CustomCircle> c = ofPtr<CustomCircle>(new CustomCircle);
		c.get()->setPhysics(1.0, 0.8, 0.5); //物理パラメータ（重さ、反発力、摩擦力）
		c.get()->setup(box2d.getWorld(), mouseX, mouseY, r); //マウス位置に円設置
		circles.push_back(c);
	}

	if (key == 'r') {
		for (int i = 0;i < circles.size();i++) {
			circles[i].get()->destroy();
		}
		circles.clear();
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
	/*
	float r = ofRandom(10, 40);
	//auto circle = std::make_shared<ofxBox2dCircle>();
	//circle.get()->setPhysics(1.0, 0.8, 0.5); //物理パラメータ（重さ、反発力、摩擦力）
	//circle.get()->setup(box2d.getWorld(), mouseX, mouseY, r); //マウス位置に円設置
	ofPtr<ofxBox2dCircle> circle = ofPtr<ofxBox2dCircle>(new ofxBox2dCircle);
	circle.get()->setPhysics(1.0, 0.8, 0.5); //物理パラメータ（重さ、反発力、摩擦力）
	circle.get()->setup(box2d.getWorld(), mouseX, mouseY, r); //マウス位置に円設置
	//ofxBox2dCircle circle;
	//circle.setPhysics(1.0, 0.8, 0.5); 
	//circle.setup(box2d.getWorld(), mouseX, mouseY, r); 
	circles.push_back(circle);
	*/

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
