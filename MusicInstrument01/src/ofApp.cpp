#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//基本設定
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackgroundHex(0x000000);
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	//box2d初期化
	box2d.init();
	box2d.setGravity(0, 0);
	box2d.setFPS(30.0);
	//画像読み込み
	particleImage.loadImage("flare.png");
	dacImage.loadImage("particle.png");
	//中心のパーティクル設定
	dac.fixture.filter.groupIndex = -1; //衝突判定しない
	dac.setup(box2d.getWorld(), ofGetWidth() / 2, ofGetHeight() / 2, 1, 1);

}

//--------------------------------------------------------------
void ofApp::update(){
	box2d.update();
	//パーティクル更新
	for (int i = 0;i < particles.size();i++) {
		particles[i].get()->update(); //座標更新
		particles[i].get()->addAttractionPoint(dac.getPosition().x,dac.getPosition().y, 0.1); //引力計算
		//パーティクル同士の引力計算
		for (int j = i + 1;j < particles.size();j++) {
			particles[j].get()->addAttractionPoint(particles[i].get()->getPosition(), 0.001);
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	//パーティクル同士を結ぶ線描画
	for (int i = 0;i < particles.size();i++) {
		ofVec2f p1(particles[i].get()->getPosition());
		//パーティクル間距離計算
		for (int j = i + 1;j < particles.size();j++) {
			ofVec2f p2(particles[j].get()->getPosition());
			float dist = p2.distance(p1);
			//距離300以下なら線を引く
			if (dist < 300) {
				int col = (300 - dist);
				ofSetColor(255, 255, 255, col); //(近いほど濃く）
				ofLine(p1.x, p1.y, p2.x, p2.y);
			}
		}
	}
	//パーティクル位置へ画像描画
	ofSetColor(255, 255, 255);
	for (int i = 0;i < particles.size();i++) {
		float radius = particles[i].get()->radius;
		particleImage.draw(particles[i].get()->getPosition() - radius / 2.0, radius, radius); //画像配置
	}
	//音量合計算出
	float allAmp = 0;
	for (int i = 0;i < particles.size();i++) {
		allAmp += particles[i].get()->amp;
	}
	//音量合計から中心半径計算
	float dacRadius = sin(ofGetElapsedTimef()*100.0)*allAmp*20.0 + allAmp*40.0 + 40.0;
	ofVec2f offset(dacRadius, dacRadius);
	dacImage.draw(dac.getPosition() - offset, dacRadius*2.0, dacRadius*2.0); //中心描画

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 'f':
		ofToggleFullscreen(); //フルスクリーン化
		break;
	case 'c':
		//パーティクル消去
		for (int i = 0;i < particles.size();i++) {
			particles[i].get()->destroy();
		}
		particles.clear();
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
	//CustomRect rect(particles.size());
	ofPtr<CustomRect> rect = ofPtr<CustomRect>(new CustomRect(particles.size()));
	rect.get()->setPhysics(10.0, 0.1, 0.5);
	rect.get()->fixture.filter.groupIndex = -1;
	rect.get()->setup(box2d.getWorld(), mouseX, mouseY, 10, 10);
	particles.push_back(rect);

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	dac.setPosition(ofGetWidth() / 2, ofGetHeight() / 2);

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
