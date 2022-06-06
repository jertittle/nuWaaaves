#pragma once

#include "ofMain.h"
//#include "ofxMidi.h"
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
    
    void NDI_sender_setup(string app_name);
    void NDI_sender_update();
    
    ofxNDISender sender_;
    ofxNDISendVideo ndi_send_video_;
    
    //-----------guibiz
    shared_ptr<GuiApp> gui;
    
    
    
    
    ofShader shader_mixer;
    ofShader shader_blur;
    ofShader shader_sharpen;
    
    
    
    
    
    ofFbo fbo_draw;
    ofFbo fbo_feedback;
    ofFbo fbo_blur;
    
    
    
    ofVideoGrabber cam1;
    
};
