//
//  ofxImageNode.h
//  SimpleGameAPI
//
//  Created by hiz on 2015/06/28.
//
//

#ifndef __SimpleGameAPI__ofxImageNode__
#define __SimpleGameAPI__ofxImageNode__

#include <stdio.h>
#include "ofMain.h"


class ofxImageNode : public ofNode {
public:
    ofxImageNode(): image(NULL), anchorPercent(ofVec2f(0.5, 0.5)), imageWillDeleted(false) {}
    ~ofxImageNode() {
        // if this node loaded image and image wasn't cached, image is deleted.
        if(this->imageWillDeleted) delete image;
    }
    // set image pointer.
    void setImage(ofImage *image);
    
    // load image. if cache is true, images are cached.
    // caution : cached images won't be deleted automatically.
    //           please call clearImageCache() or clearAllImageCache() manually.
    void loadImage(const string &filename, bool cache = true);
    
    // clear image.
    void clearImage();
    
    // set image anchor by percent.(0.0-1.0)
    void setAnchorPercent(float x, float y);
    
    // get image anchor by percent.(0.0-1.0)
    ofVec2f getAnchorPercent();
    
    // custom draw.
    virtual void customDraw();
    
    // clear image cache.
    static void clearImageCache(const string &filename);
    
    // clear all image cache.
    static void clearAllImageCache();
private:
    ofImage *image;
    ofVec2f anchorPercent;
    bool    imageWillDeleted;
};

#endif /* defined(__SimpleGameAPI__ofxImageNode__) */
