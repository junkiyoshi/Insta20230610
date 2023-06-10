#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);

	this->noise_param = ofRandom(1000);
}
//--------------------------------------------------------------
void ofApp::update() {

	this->noise_param += 0.01;
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	for (int deg = 0; deg < 360; deg += 6) {

		float  radius = 200;

		auto start = glm::vec2((radius - 75) * cos(deg * DEG_TO_RAD), (radius - 75) * sin(deg * DEG_TO_RAD));
		auto end = glm::vec2((radius + 75) * cos(deg * DEG_TO_RAD), (radius + 75) * sin(deg * DEG_TO_RAD));

		ofDrawLine(start, end);

		auto target_radius = ofMap(ofNoise(cos(deg * DEG_TO_RAD) * 3, sin(deg * DEG_TO_RAD) * 3, this->noise_param), 0, 1, radius - 60, radius + 60);
		auto target_location = glm::vec2(target_radius * cos(deg * DEG_TO_RAD), target_radius * sin(deg * DEG_TO_RAD));

		ofPushMatrix();
		ofTranslate(target_location);
		ofRotate(deg);

		ofDrawRectangle(glm::vec2(), 40, 10);
		
		ofPopMatrix();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}