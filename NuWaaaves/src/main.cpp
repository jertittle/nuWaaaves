#include "ofMain.h"
#include "ofApp.h"

#include "GuiApp.h"
#include "ofAppGLFWWindow.h"
int main(){
    
    //--------------oldsinglewindowsetup
    /*
     ofSetupOpenGL(1024, 1024, OF_WINDOW);
     ofRunApp(new ofApp());
     */
    
    
    
    //---------------------------------
    //dualwindowsetup
    ofGLFWWindowSettings settings;
    
   // settings.setSize(1024, 1024);
    
     settings.setSize(1280,720);

    //settings.setSize(640, 480);
    settings.setPosition(ofVec2f(550,0));
    settings.resizable = true;
    //settings.decorated = false;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    settings.setSize(550, 960);
    settings.setPosition(ofVec2f(0,0));
    settings.resizable = true;
   // settings.doubleBuffering=false;
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    shared_ptr<GuiApp> guiApp(new GuiApp);
    mainApp->gui = guiApp;
    
    ofRunApp(guiWindow, guiApp);
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
    
    
    
    
}
