//
//  ofxSpriteNode.cpp
//  example
//
//  Created by hiz on 2015/07/02.
//
//

#include "ofxSpriteNode.h"

// custom draw.
void ofxSpriteNode::customDraw() {
    ofImage *image = this->getImage();
    if(image != NULL) {
        float w = image->getWidth()/grid.first;
        float h = image->getHeight()/grid.second;
        image->drawSubsection(0, 0, w * pattern.first, h * pattern.second, w, h);
    }
}