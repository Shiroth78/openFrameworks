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
	box2d.setGravity(0, 0);
	box2d.setFPS(30.0);
	//�摜�ǂݍ���
	particleImage.loadImage("flare.png");
	dacImage.loadImage("particle.png");
	//���S�̃p�[�e�B�N���ݒ�
	dac.fixture.filter.groupIndex = -1; //�Փ˔��肵�Ȃ�
	dac.setup(box2d.getWorld(), ofGetWidth() / 2, ofGetHeight() / 2, 1, 1);

}

//--------------------------------------------------------------
void ofApp::update(){
	box2d.update();
	//�p�[�e�B�N���X�V
	for (int i = 0;i < particles.size();i++) {
		particles[i].get()->update(); //���W�X�V
		particles[i].get()->addAttractionPoint(dac.getPosition().x,dac.getPosition().y, 0.1); //���͌v�Z
		//�p�[�e�B�N�����m�̈��͌v�Z
		for (int j = i + 1;j < particles.size();j++) {
			particles[j].get()->addAttractionPoint(particles[i].get()->getPosition(), 0.001);
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	//�p�[�e�B�N�����m�����Ԑ��`��
	for (int i = 0;i < particles.size();i++) {
		ofVec2f p1(particles[i].get()->getPosition());
		//�p�[�e�B�N���ԋ����v�Z
		for (int j = i + 1;j < particles.size();j++) {
			ofVec2f p2(particles[j].get()->getPosition());
			float dist = p2.distance(p1);
			//����300�ȉ��Ȃ��������
			if (dist < 300) {
				int col = (300 - dist);
				ofSetColor(255, 255, 255, col); //(�߂��قǔZ���j
				ofLine(p1.x, p1.y, p2.x, p2.y);
			}
		}
	}
	//�p�[�e�B�N���ʒu�։摜�`��
	ofSetColor(255, 255, 255);
	for (int i = 0;i < particles.size();i++) {
		float radius = particles[i].get()->radius;
		particleImage.draw(particles[i].get()->getPosition() - radius / 2.0, radius, radius); //�摜�z�u
	}
	//���ʍ��v�Z�o
	float allAmp = 0;
	for (int i = 0;i < particles.size();i++) {
		allAmp += particles[i].get()->amp;
	}
	//���ʍ��v���璆�S���a�v�Z
	float dacRadius = sin(ofGetElapsedTimef()*100.0)*allAmp*20.0 + allAmp*40.0 + 40.0;
	ofVec2f offset(dacRadius, dacRadius);
	dacImage.draw(dac.getPosition() - offset, dacRadius*2.0, dacRadius*2.0); //���S�`��

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 'f':
		ofToggleFullscreen(); //�t���X�N���[����
		break;
	case 'c':
		//�p�[�e�B�N������
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
