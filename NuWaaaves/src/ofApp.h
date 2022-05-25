#pragma once

#include "ofMain.h"
//#include "ofxMidi.h"
#include "GuiApp.h"

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
