
#include "ofApp.h"

#include <iostream>


float aa=0.0;
float ss=0.0;
float dd=0.0;
float ff=0.0;
float xw=1.01;
float yw=1.01;
float jj=1;
float kk=1;
float ll=.05;

float qq=0;
float ee=0;

float oo=1.0;
int ii=1;

float gg=0;
float hh=0;

float theta=0;

float movex=0;

float frequency=0;


float amp=0;






float scale1=1;
float scale2=1;

//vidmixer variables
float scale=.5;

float tt=0;

//framebuffer buffer variables  fbob-->framebufferobjectbuffer

//int framecount=0;
//const int fbob=15;


//int compScale=2;


int framedelayoffset=0;  // this is used as an index to the circular framebuffers eeettt
unsigned int framecount=0; // framecounter used to calc offset eeettt


//i got this up to 240 frames with steady on my computer, is a bit skewed extreme for real time video
//executions tho
const int fbob=30; // number of "framedelay" buffers eeettt
//int dd=fbob;
//this buffers the framebuffers from the final screen draws

//this buffers the framebuffers from the final screen draws
ofFbo pastFrames[fbob];

ofFbo pastFrames_comp[fbob];
//ofFbo is the openframeworks framebuffer object
//this line is declaring an array of framebuffer objects
//many c++ afficionados prefer a c++ vector object instead of arrays every time
//because c++ vectors are like arrays but with some handier ways to access and add and delete contents
//but on the other hand vectors can have dynamic lengths and one can really end up in some
//trouble with dynamically working with framebuffers bc its generally best pratice to allocate
//memory on the gpu for all of yr framebuffers before yr code runs, trying to mess with that on
//the fly could have some interesting appeal to a glitch art style but is not going to please
//others

void incIndex()  // call this every frame to calc the offset eeettt
{
    
    framecount++;
    framedelayoffset=framecount % fbob;
}

//----
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    
    ofSetVerticalSync(true);
    ofBackground(0);
    //ofSetLogLevel(OF_LOG_VERBOSE);
    
    
    
    // string reciever_name="Cellular_automata";
    string reciever_name="";
    //string reciever_name="testing";
    //ndi setup
    NDI_reciever_setup(reciever_name);
    NDI_sender_setup("nu_Waaves");
    /**shaderobiz***/
    
    /**shaderobiz***/
    //  ofSetDataPathRoot("../Resources/data/");
#ifdef TARGET_OPENGLES
    
#else
    if(ofIsGLProgrammableRenderer()){
        
    }else{
        
        shader_mixer.load("shadersGL2/shader_mixer");
        shader_blur.load("shadersGL2/shader_blur");
        shader_sharpen.load("shadersGL2/shader_sharpen");
        
        //shader_displace.load("shadersGL2/shader_displace");
    }
#endif
    
    fbo_draw.allocate(ofGetWidth(), ofGetHeight());
    fbo_feedback.allocate(ofGetWidth(), ofGetHeight());
    ndi_fbo.allocate(ofGetWidth(), ofGetHeight());
    
    fbo_blur.allocate(ofGetWidth(), ofGetHeight());
    
    /*
     fbo_draw.allocate(ofGetScreenWidth(), ofGetScreenHeight());
     fbo_feedback.allocate(ofGetScreenWidth(), ofGetScreenHeight());
     syphonTexture.allocate(ofGetScreenWidth(), ofGetScreenHeight());
     fbo_blur.allocate(ofGetScreenWidth(), ofGetScreenHeight());
     */
    fbo_feedback.begin();
    
    ofClear(0,0,0,255);
    
    fbo_feedback.end();
    
    fbo_draw.begin();
    ofClear(0,0,0,255);
    fbo_draw.end();
    
    fbo_blur.begin();
    ofClear(0,0,0,255);
    fbo_blur.end();
    
    
    
    
    //allocate and clear the variable delay final draw buffers
    //full resolution version
    
    for(int i=0;i<fbob;i++){
        
        pastFrames[i].allocate(ofGetWidth(), ofGetHeight());
        
        //   pastFrames[i].allocate(ofGetScreenWidth(), ofGetScreenHeight());
        pastFrames[i].begin();
        ofClear(0,0,0,255);
        pastFrames[i].end();
        
        
    }//endifor
    
    cam1.listDevices();
    cam1.setVerbose(true);
    cam1.setDeviceID(0);
    cam1.initGrabber(1280, 720);
    
    //-------------------TITTLER
    //old OF default is 96 - but this results in fonts looking larger than in other programs.
    ofTrueTypeFont::setGlobalDpi(72);
    
    fbo_tittle.allocate(ofGetWidth(), ofGetHeight());
    
    fbo_tittle.begin();
    ofClear(0,0,0,255);
    fbo_tittle.end();
    
    franklinBook14.load("frabk.ttf", 14);
    franklinBook14.setLineHeight(18.0f);
    franklinBook14.setLetterSpacing(1.037);
    
    franklinBook14A.load("frabk.ttf", 14, false);
    franklinBook14A.setLineHeight(18.0f);
    franklinBook14A.setLetterSpacing(1.037);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    cam1.update();
    
    NDI_reciever_update();
    NDI_sender_update();
    
    
    
    tittle_update();
    
    if(gui->framebuffer_clear==true){
        for(int i=0;i<fbob;i++){
            pastFrames[i].begin();
            
            ofClear(0,0,0,255);
            
            pastFrames[i].end();
        }
        
        fbo_draw.begin();
        ofClear(0,0,0,255);
        fbo_draw.end();
        cout<<"lalalal"<<endl;
        gui->framebuffer_clear = 0;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    fbo_draw.begin();
    
    
    //try putting graphics up here instead and see if then we can key into opaqueness
    
    
    
    
    
    
    shader_mixer.begin();
    
    //--------------------------send the textures
    
    fbo_feedback.draw(0,0);
    
    
    
    shader_mixer.setUniformTexture("ndi",ndi_fbo.getTexture(),1); shader_mixer.setUniformTexture("cam1",cam1.getTexture(),2);
    shader_mixer.setUniformTexture("tittle", fbo_tittle.getTexture(),3);//so this last number in the call here is unrelated to the location in the Gui drop menu//
    shader_mixer.setUniform1f("tittle_scale", gui->tittle_scale);
    
    shader_mixer.setUniformTexture("fb0",pastFrames[(abs(framedelayoffset-fbob-gui->fb0_delay_amount)-1)%fbob].getTexture(),4);
    shader_mixer.setUniformTexture("fb1",pastFrames[(abs(framedelayoffset-fbob-gui->fb1_delay_amount)-1)%fbob].getTexture(),5);
    
    
    
    
    //global things
    shader_mixer.setUniform1f("width", ofGetWidth());
    shader_mixer.setUniform1f("height", ofGetHeight());
    
    shader_mixer.setUniform2f("cam1dimensions",ofVec2f(cam1.getWidth(),cam1.getHeight()));
    shader_mixer.setUniform2f("textdimensions",ofVec2f(fbo_tittle.getWidth(),fbo_tittle.getHeight()));
    
    //send variables from gui
    shader_mixer.setUniform1i("channel1", gui->channel1_select);
    
    shader_mixer.setUniform1f("fb0blend", gui->fb0_mix);
    shader_mixer.setUniform1f("fb0lumakeyvalue", gui->fb0_key_value);
    shader_mixer.setUniform1f("fb0lumakeythresh", gui->fb0_key_threshold);
    
    shader_mixer.setUniform1i("fb0_hflip_switch", gui->fb0_hflip_switch);
    shader_mixer.setUniform1i("fb0_vflip_switch", gui->fb0_vflip_switch);
    shader_mixer.setUniform1i("fb0_toroid_switch", gui->fb0_toroid_switch);
    
    shader_mixer.setUniform1f("fb1blend", gui->fb1_mix);
    shader_mixer.setUniform1f("fb1lumakeyvalue", gui->fb1_key_value);
    shader_mixer.setUniform1f("fb1lumakeythresh", gui->fb1_key_threshold);
    
    shader_mixer.setUniform1i("fb1_hflip_switch", gui->fb1_hflip_switch);
    shader_mixer.setUniform1i("fb1_vflip_switch", gui->fb1_vflip_switch);
    shader_mixer.setUniform1i("fb1_toroid_switch", gui->fb1_toroid_switch);
    
    shader_mixer.setUniform1i("cam1_hflip_switch", gui->cam1_hflip_switch);
    shader_mixer.setUniform1i("cam1_vflip_switch", gui->cam1_vflip_switch);
    
    
    shader_mixer.setUniform1f("cam1_scale", gui->cam1_scale);
    
    
    
    
    //operations folder
    
    //ch1
    
    shader_mixer.setUniform1f("channel1hue_x", gui->ch1_hue);
    shader_mixer.setUniform1f("channel1saturation_x", gui->ch1_saturation);
    shader_mixer.setUniform1f("channel1bright_x", gui->ch1_bright);
    
    shader_mixer.setUniform1i("ch1hue_inverttoggle", gui->ch1_hue_alt_invert_toggle);
    shader_mixer.setUniform1i("ch1sat_inverttoggle", gui->ch1_saturation_alt_invert_toggle);
    shader_mixer.setUniform1i("ch1bright_inverttoggle", gui->ch1_bright_alt_invert_toggle);
    
    shader_mixer.setUniform1i("channel1satwrap", gui->ch1_saturation_wrap);
    shader_mixer.setUniform1i("channel1brightwrap", gui->ch1_bright_wrap);
    
    
    shader_mixer.setUniform1i("ch1hue_powmaptoggle", gui->ch1hue_powmaptoggle);
    shader_mixer.setUniform1i("ch1sat_powmaptoggle", gui->ch1sat_powmaptoggle);
    shader_mixer.setUniform1i("ch1bright_powmaptoggle", gui->ch1bright_powmaptoggle);
    
    
    
    
    shader_mixer.setUniform1f("channel1hue_powmap", gui->ch1_hue_powmap);
    shader_mixer.setUniform1f("channel1sat_powmap", gui->ch1_saturation_powmap);
    shader_mixer.setUniform1f("channel1bright_powmap", gui->ch1_bright_powmap);
    
    
    
    //fb0
    
    shader_mixer.setUniform3f("fb0_hsb_x",ofVec3f(gui->fb0_hue/10,gui->fb0_saturation/10,gui->fb0_bright/10));
    shader_mixer.setUniform3f("fb0_hue_x",ofVec3f(gui->fb0_huex_mod/10,gui->fb0_huex_offset/10,gui->fb0_huex_lfo/10));
    shader_mixer.setUniform3f("fb0_rescale",ofVec3f(gui->fb0_x_displace,gui->fb0_y_displace,gui->fb0_z_displace/100));
    shader_mixer.setUniform3f("fb0_modswitch",ofVec3f(gui->fb0_hue_invert,gui->fb0_saturation_invert,gui->fb0_bright_invert));
    
    shader_mixer.setUniform1f("fb0_rotate",(gui->fb0_rotate)/100);
    
    //fb1
    shader_mixer.setUniform3f("fb1_hsb_x",ofVec3f(gui->fb1_hue/10,gui->fb1_saturation/10,gui->fb1_bright/10));
    shader_mixer.setUniform3f("fb1_hue_x",ofVec3f(gui->fb1_huex_mod/10,gui->fb1_huex_offset/10,gui->fb1_huex_lfo/10));
    shader_mixer.setUniform3f("fb1_rescale",ofVec3f(gui->fb1_x_displace,gui->fb1_y_displace,gui->fb1_z_displace/100));
    shader_mixer.setUniform3f("fb1_modswitch",ofVec3f(gui->fb1_hue_invert,gui->fb1_saturation_invert,gui->fb1_bright_invert));
    
    shader_mixer.setUniform1f("fb1_rotate",(gui->fb1_rotate)/100);
    
    
    
    //pixelations
    
    //cam1
    shader_mixer.setUniform1i("cam1_pixel_switch",gui->cam1_pixel_switch);
    shader_mixer.setUniform1i("cam1_pixel_scale_x",gui->cam1_pixel_scale_x);
    shader_mixer.setUniform1i("cam1_pixel_scale_y",gui->cam1_pixel_scale_y);
    shader_mixer.setUniform1f("cam1_pixel_mix",gui->cam1_pixel_mix);
    shader_mixer.setUniform1f("cam1_pixel_brightscale",gui->cam1_pixel_brightscale);
    
    
    
    //fb0
    shader_mixer.setUniform1i("fb0_pixel_switch",gui->fb0_pixel_switch);
    shader_mixer.setUniform1i("fb0_pixel_scale_x",gui->fb0_pixel_scale_x);
    shader_mixer.setUniform1i("fb0_pixel_scale_y",gui->fb0_pixel_scale_y);
    shader_mixer.setUniform1f("fb0_pixel_mix",gui->fb0_pixel_mix);
    shader_mixer.setUniform1f("fb0_pixel_brightscale",gui->fb0_pixel_brightscale);
    //fb1
    shader_mixer.setUniform1i("fb1_pixel_switch",gui->fb1_pixel_switch);
    shader_mixer.setUniform1i("fb1_pixel_scale_x",gui->fb1_pixel_scale_x);
    shader_mixer.setUniform1i("fb1_pixel_scale_y",gui->fb1_pixel_scale_y);
    
    shader_mixer.setUniform1f("fb1_pixel_mix",gui->fb1_pixel_mix);
    shader_mixer.setUniform1f("fb1_pixel_brightscale",gui->fb1_pixel_brightscale);
    
    //ndi
    shader_mixer.setUniform1i("ndi_pixel_switch",gui->ndi_pixel_switch);
    shader_mixer.setUniform1i("ndi_pixel_scale_x",gui->ndi_pixel_scale_x);
    shader_mixer.setUniform1i("ndi_pixel_scale_y",gui->ndi_pixel_scale_y);
    shader_mixer.setUniform1f("ndi_pixel_mix",gui->ndi_pixel_mix);
    shader_mixer.setUniform1f("ndi_pixel_brightscale",gui->ndi_pixel_brightscale);
    
    
    
    
    
    
    
    
    //just a couple of tester variables for debugging
    //shader_mixer.setUniform1f("ee",ee);
    //shader_mixer.setUniform1f("qq",qq);
    
    shader_mixer.end();
    
    
    fbo_draw.end();
    
    //----------------------------------------------------------
    
    
    
    //sharpen and blur the composited image before it is drawn to screens and buffers
    
    fbo_blur.begin();
    
    
    
    
    
    shader_blur.begin();
    
    fbo_draw.draw(0,0);
    shader_blur.setUniform1f("blur_amount",gui->blur_amount);
    shader_blur.setUniform1f("blur_radius",gui->blur_radius);
    shader_blur.end();
    
    
    fbo_blur.end();
    
    
    
    fbo_draw.begin();
    
    
    
    
    //so add a radius and chi variable to this
    //then figure out how to switch on and off and route properly
    
    shader_sharpen.begin();
    fbo_blur.draw(0,0);
    shader_sharpen.setUniform1f("sharpen_amount",gui->sharpen_amount);
    shader_sharpen.setUniform1f("sharpen_radius",gui->sharpen_radius);
    shader_sharpen.setUniform1f("sharpen_boost",gui->sharpen_boost);
    shader_sharpen.end();
    
    
    //fbo_blur.draw(0,0);
    
    fbo_draw.end();
    
    
    //___--_------___-_-_______-----___-
    
    /*this part gets drawn to screen*/
    ofSetColor(ofColor::white);
    
    ofPushMatrix();
    //add seperate switchs for this and fbo
    ofTranslate(ofGetWidth()/2.0,ofGetHeight()/2.0);
    
    // ofRotateZRad(oo*TWO_PI/ii);
    //looks like there needds to be seperate rotations for camera stuff and framebuffer stuffs
    ofTranslate(0,0,0);
    fbo_draw.draw(-ofGetWidth()/2.0,-ofGetHeight()/2.0);
    ofPopMatrix();
    
    //feed the previous frame into position 0 (index0)
    
    pastFrames[abs(fbob-framedelayoffset)-1].begin(); //eeettt
    
    
    ofPushMatrix();
    
    //recenter the coordinates so 0,0 is at the center of the screen
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2,0);
    
    //  ofRotateZRad(.01);
    ofTranslate(ff,gg,hh);
    ofRotateYRad(ss+gui->y_skew);
    ofRotateXRad(aa+gui->x_skew);
    ofRotateZRad(dd);
    ofRotateZRad(oo*TWO_PI/ii);
    
    
    fbo_draw.draw(-ofGetWidth()/2,-ofGetHeight()/2);
    
    ofPopMatrix();
    
    
    pastFrames[abs(fbob-framedelayoffset)-1].end(); //eeettt
    //-----____---____---__-__---____-----_--_-
    
    
    incIndex(); // increment framecount and framedelayoffset eeettt
    
    //cout << "fps: " << ofToString((int)ofGetFrameRate()) << endl;
    
}
//--------------------------------------- ---

float ofApp::widthOffset(string strr ){
    
    ofRectangle bounds = franklinBook14.getStringBoundingBox(strr, 0, 0 );
    return -bounds.width/2;
}

//--------------------------------------- ---
void ofApp:: tittle_update() {
    
    
    fbo_tittle.begin();
    ofClear(0,0,0,255);
    //---------------------------------------------------------------------------------------------------------Titler
    
    ofPushMatrix();
    
    ofTranslate(ofGetWidth()/3, ofGetHeight()*.7);//this could be set by sliders or look into 2D gui element. joystick?
    
    ofScale(gui->textScale);//should I look into setHeight/Width
    ofSetColor(gui->textColor);
    
    if(gui->setAa) {//start anti-aliasing
        
        franklinBook14.drawString(gui->str, widthOffset(ofToString(gui->str)),0);
        
    } else {
        
        franklinBook14A.drawString(gui->str, widthOffset(ofToString(gui->str)),0);
    }//end anti-aliasing
    
    /// fbo_tittle.draw(0,0);
    
    ofPopMatrix();
    //  fbo_tittle.draw(0,0);
    fbo_tittle.end();
    
    
    
}


//_____----_-_-_-______---__---_--_----____--_-__-_-
void ofApp::NDI_reciever_setup(string reciever_name){
    auto findSource = [](const string &name_or_url) {
        auto sources = ofxNDI::listSources();
        if(name_or_url == "") {
            return make_pair(ofxNDI::Source(), false);
        }
        auto found = find_if(begin(sources), end(sources), [name_or_url](const ofxNDI::Source &s) {
            return ofIsStringInString(s.p_ndi_name, name_or_url) || ofIsStringInString(s.p_url_address, name_or_url);
        });
        if(found == end(sources)) {
            ofLogWarning("ofxNDI") << "no NDI source found by string:" << name_or_url;
            return make_pair(ofxNDI::Source(), false);
        }
        return make_pair(*found, true);
    };
    string name_or_url = reciever_name;    // Specify name or address of expected NDI source. In case of blank or not found, receiver will grab default(which is found first) source.
    cout<<"name of ndi "<<name_or_url<<endl;
    auto result = findSource(name_or_url);
    if(result.second ? ndi_receiver_.setup(result.first) : ndi_receiver_.setup()) {
        ndi_video_.setup(ndi_receiver_);
    }
    
}
//-------------------------

void ofApp::NDI_reciever_update(){
    if(ndi_receiver_.isConnected()) {
        ndi_video_.update();
        if(ndi_video_.isFrameNew()) {
            ndi_video_.decodeTo(ndi_pixels);
        }
    }
    ndi_fbo.begin();
    if(ndi_pixels.isAllocated()) {
        //ofImage ndi_image;
        ofPushMatrix();
        ofTranslate(ndi_fbo.getWidth()/2,ndi_fbo.getHeight()/2);
        ofTranslate(0,0,gui->ndi_scale);
        ofImage(ndi_pixels).draw(-ofImage(ndi_pixels).getWidth()/2,-ofImage(ndi_pixels).getHeight()/2);
        //ofImage(ndi_pixels).draw(0,0);
        ofPopMatrix();
    }
    ndi_fbo.end();
    
    
    
}

//------------------------------------------------

void ofApp::NDI_sender_setup(string app_name){
    
    if(sender_.setup(app_name)) {
        ndi_send_video_.setup(sender_);
        ndi_send_video_.setAsync(true);
    }
    
}

//----

void ofApp:: NDI_sender_update(){
    ofPixels fbo_pixels;
    fbo_draw.readToPixels(fbo_pixels);
    ndi_send_video_.send(fbo_pixels);//getPixels());
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    
    if(key=='3'){
        aa=ss=dd=ff=gg=hh=0;
    }
    
    if(key=='1'){
        for(int i=0;i<fbob;i++){
            pastFrames[i].begin();
            
            ofClear(0,0,0,255);
            
            pastFrames[i].end();
        }
        
        fbo_draw.begin();
        ofClear(0,0,0,255);
        fbo_draw.end();
    }
    //if(key=='q'){sw1==0;}
    
    if(key=='a'){aa+=0.0001;}
    if(key=='z'){aa-=0.0001;}
    if(key=='s'){ss+=0.0001;}
    if(key=='x'){ss-=0.0001;}
    
    if(key=='d'){dd+=0.0001;}
    if(key=='c'){dd-=0.0001;}
    
    if(key=='f'){ff+=0.0001;}
    if(key=='v'){ff-=0.0001;}
    
    if(key=='g'){gg+=0.0001;}
    if(key=='b'){gg-=0.0001;}
    if(key=='h'){hh+=0.01;}
    if(key=='n'){hh-=0.01;}
    
    
    if(key=='j'){jj+=0.1;}
    if(key=='m'){jj-=0.1;}
    if(key=='k'){kk+=0.1;}
    if(key==','){kk-=0.1;}
    
    
    
    if(key==';'){scale1+=0.01;}
    if(key=='/'){scale1-=0.01;}
    
    if(key=='['){scale2+=0.01;}
    if(key==']'){scale2-=0.01;}
    
    if(key=='q'){qq+=0.001;cout << "qq"<<qq<< endl;}
    if(key=='w'){qq-=0.001;cout << "qq"<<qq<< endl;}
    if(key=='e'){ee+=.1;cout << "ee"<<ee<< endl;}
    if(key=='r'){ee-=.1;cout << "ee"<<ee<< endl;}
    
    
    if(key=='u'){ii+=1;}
    if(key=='i'){ii-=1;}
    if(key=='o'){oo+=.1;}
    if(key=='p'){oo-=.1;}
    
    if(key=='t'){tt+=.01;}
    if(key=='y'){tt-=.01;}
    
    
    if(key=='2'){amp+=.001;}
    if(key=='3'){amp-=.001;}
    
}
//--------------------------------------------------------------
void ofApp::exit() {
    
    
}//--------------------------------------------------------------
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
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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
