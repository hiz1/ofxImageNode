#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for(int x=0;x<ofGetWidth();x+=80) {
        for(int y=0;y<ofGetHeight();y+=80) {
            ofxImageNode node;
            node.loadImage("of.png");
            node.setScale(0.2);
            node.setAnchorPercent(0, 0);
            node.setPosition(x, y, 0);
            nodes.push_back(node);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(vector<ofxImageNode>::iterator ite = nodes.begin(); ite != nodes.end();ite++) {
        ite->rotate(1, ofVec3f(0,1,0));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(vector<ofxImageNode>::iterator ite = nodes.begin(); ite != nodes.end();ite++) {
        ite->draw();
    }
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
