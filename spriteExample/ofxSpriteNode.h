//
//  ofxSpriteNode.h
//  example
//
//  Created by hiz on 2015/07/02.
//
//

#ifndef __example__ofxSpriteNode__
#define __example__ofxSpriteNode__

#include <stdio.h>
#include "ofxImageNode.h"

class ofxSpriteNode : public ofxImageNode {
public:
    ofxSpriteNode():grid(1,1), pattern(0,0){}
    
    // set number of image partitions.
    void setGrid(int col, int row) {
        grid = pair<int, int>(col, row);
    }
    // get number of image partitions.
    pair<int, int> getGrid() {
        return grid;
    }
    // set current position of grid.
    void setPattern(int ci, int ri) {
        if(ci <  0          ) ci = 0;
        if(ci >= grid.first ) ci = grid.first-1;
        if(ri <  0          ) ri = 0;
        if(ri >= grid.second) ri = grid.second-1;
        pattern = pair<int, int>(ci, ri);
    }
    // get current position of grid.
    pair<int, int> getPattern() {
        return pattern;
    }
    // custom draw.
    virtual void customDraw();
    
private:
    pair<int, int> grid;
    pair<int, int> pattern;
};

#endif /* defined(__example__ofxSpriteNode__) */
