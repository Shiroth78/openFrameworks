#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sampleRate = 44100;
	bufSize = 256;
	amp = 0.5;
	pan = 0.5;
	phase = 0;
	frequency = 440;
	waveShape = 1;
	ofSetFrameRate(30);
	ofBackground(32, 32, 32);
	ofSoundStreamSetup(2, 0);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	float audioHeight = ofGetHeight() / 2.0f;
	float phaseDiff = ofGetWidth() / float(bufSize);

	ofSetColor(0, 0, 255);
	ofNoFill();
	ofSetLineWidth(2);

	ofBeginShape();
	for (int i = 0;i < bufSize;i++) {
		ofVertex(i*phaseDiff, audioHeight / 2 + laudio[i] * audioHeight);
	}
	ofEndShape();

	ofBeginShape();
	for (int i = 0;i < bufSize;i++) {
		ofVertex(i*phaseDiff, audioHeight / 2 * 3 + raudio[i] * audioHeight);
	}
	ofEndShape();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case '-':
		amp -= 0.05;
		amp = MAX(amp, 0);
		break;
	case '+':
		amp += 0.05;
		amp = MIN(amp, 1);
		break;
	case '1':
		waveShape = 1;
		break;
	case '2':
		waveShape = 2;
		break;
	case '3':
		waveShape = 3;
		break;
	case '4':
		waveShape = 4;
		break;
	case '5':
		waveShape = 5;
		break;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	pan = (float)x / (float)ofGetWidth();
	float heightPct = (float(ofGetHeight() - y)) / float(ofGetHeight());
	frequency = 4000.0f*heightPct;
	if (frequency < 20) {
		frequency = 20;
	}

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

void ofApp::audioRequested(float * output, int bufferSize, int nChannels) {
	float sample;
	float phaseDiff;

	phaseDiff = TWO_PI * frequency / sampleRate;

	for (int i = 0;i < bufferSize;i++) {
		phase += phaseDiff;
		while (phase > TWO_PI) {
			phase -= TWO_PI;
		}

		switch (waveShape) {
		case 1: //sin
			sample = sin(phase);
			break;
		case 2: //ƒmƒRƒMƒŠ
			sample = -phase / PI + 1;
			break;
		case 3: //’ZŒ`”g
			sample = (phase < PI) ? -1 : 1;
			break;
		case 4: //ŽOŠp”g
			sample = (phase < PI) ? -2 / PI*phase + 1 : 2 / PI*phase - 3;
			break;
		case 5: //ƒzƒƒCƒgƒmƒCƒY
			sample = ofRandom(-1, 1);
			break;
		}

		laudio[i] = output[i + nChannels] = sample*pan*amp;
		raudio[i] = output[i + nChannels + 1] = sample*pan*amp;
	}
}
