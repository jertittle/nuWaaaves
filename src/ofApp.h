/*
* Copyright (c) 2013 Dan Wilcox <danomatika@gmail.com>
*
* BSD Simplified License.
* For information on usage and redistribution, and for a DISCLAIMER OF ALL
* WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*
* See https://github.com/danomatika/ofxMidi for documentation
*
*/
#pragma once

#include "ofMain.h"
#include "GuiApp.h"
#include "ofxNDISender.h"
#include "ofxNDISendStream.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    void NDI_reciever_setup(string reciever_name);
    void NDI_reciever_update();
    
    ofxNDIReceiver ndi_receiver_;
    ofxNDIRecvVideoFrameSync ndi_video_;
    ofPixels ndi_pixels;
    
    
    ofFbo ndi_fbo;
    
    
    //-----------guibiz
    shared_ptr<GuiApp> gui;
    
    
    
    
    ofShader shader_mixer;
    ofShader shader_blur;
    ofShader shader_sharpen;
    
    
    
    
    
    ofFbo fbo_draw;
    ofFbo fbo_feedback;
    ofFbo fbo_blur;
    
    ofPixels fbo_pixels;
    
    
    
    ofVideoGrabber cam1;
    ofVideoGrabber cam2;

    void tittle_update();
       
    float widthOffset(string strr);//auto center alignment
    ofFbo fbo_tittle;
    ofTrueTypeFont  franklinBook14, franklinBook14A;
    float x_tittle, y_tittle;
    
    
//private:
    
//    void NDI_sender_setup(string app_name);
//    void NDI_sender_update();
//
//    ofxNDISender sender_;
//    ofxNDISendVideo ndi_send_video_;
//
};
