#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    node.loadImage("chara.png");
    node.setGrid(6,4);
    node.setPattern(0,0);
    node.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    int ci = (ofGetFrameNum() / 10) % 3;
    int ri = (ofGetFrameNum() / 10) / 3 / 5 % 4;
    node.setPattern(ci, ri);
}

//--------------------------------------------------------------
void ofApp::draw(){
    node.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
