//
//  ofxImageNode.cpp
//  SimpleGameAPI
//
//  Created by hiz on 2015/06/28.
//
//

#include "ofxImageNode.h"

map<string, ofImage *> imageCache;

// set image pointer.
void ofxImageNode::setImage(ofImage *image) {
    // delete old image
    if(this->image != NULL && this->imageWillDeleted) delete image;
    
    // set new image
    this->image = image;
    this->image->setAnchorPercent(this->anchorPercent.x, this->anchorPercent.y);
    this->imageWillDeleted = false;
}

// load image. if cache is true, images are cached.
void ofxImageNode::loadImage(const string &filename, bool cache) {
    // delete old image
    if(this->image != NULL && this->imageWillDeleted) delete image;
    
    // load new image
    if(cache) {
        // if cache is true, find image from cache.
        map<string, ofImage *>::iterator ite = imageCache.find(filename);
        if(ite != imageCache.end()) {
            // if succeeded, set image pointer.
            this->image = ite->second;
        } else {
            // if failed, load image file.
            this->image = new ofImage();
            this->image->loadImage(filename);
            imageCache[filename] = this->image;
        }
        this->imageWillDeleted = false;
    } else {
        // if cache is false, load image file.
        this->image = new ofImage();
        this->image->loadImage(filename);
        // if this node is deleted, image will be deleted.
        this->imageWillDeleted = true;
    }
    this->image->setAnchorPercent(this->anchorPercent.x, this->anchorPercent.y);
}

// clear image.
void ofxImageNode::clearImage() {
    if(this->image != NULL && this->imageWillDeleted) delete image;
    this->image = NULL;
}

// set image anchor by percent.(0.0-1.0)
void ofxImageNode::setAnchorPercent(float x, float y) {
    this->anchorPercent = ofVec2f(x, y);
    if(this->image != NULL) {
        this->image->setAnchorPercent(this->anchorPercent.x, this->anchorPercent.y);
    }
}

// get image anchor by percent.(0.0-1.0)
ofVec2f ofxImageNode::getAnchorPercent() {
    return this->anchorPercent;
}

// custom draw.
void ofxImageNode::customDraw() {
    if(this->image != NULL) {
        this->image->draw(0, 0);
    }
}

// clear image cache.
static void clearImageCache(const string &filename) {
    map<string, ofImage *>::iterator ite = imageCache.find(filename);
    if(ite != imageCache.end()) {
        delete ite->second;
        imageCache.erase(ite);
    }
}

// clear all image cache.
void ofxImageNode::clearAllImageCache() {
    for(map<string, ofImage *>::iterator ite=imageCache.begin();ite!=imageCache.end();ite++) {
        delete ite->second;
    }
    imageCache.clear();
}