//
//  GuiApp.h
//  NuWaaaves
//
//  Created by Mac User on 5/24/22.
//
#pragma once

#include "ofMain.h"
#include "ofxGuiExtended.h"

class GuiApp : public ofBaseApp{
    
public:
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int);
    
    ofxGui gui;
    
    //each ofxPanel is a floating window
    ofxGuiPanel *inputs;
    ofxGuiPanel *buffers;
    ofxGuiPanel *globals;
    ofxGuiPanel *pixelations;
    
    //channel 1 settings
    //gui groups are colapseable folders
    ofxGuiGroup *channel1Group;
    
    ofParameter<int> channel1;
    
    ofParameter<float> channel1hue;
    ofParameter<float> channel1saturation;
    ofParameter<float> channel1bright;
    ofParameter<bool> channel1satwrap;
    ofParameter<bool> channel1brightwrap;
    ofParameter<bool> ch1hue_powmaptoggle;
    ofParameter<bool> ch1sat_powmaptoggle;
    ofParameter<bool> ch1bright_powmaptoggle;
    ofParameter<float> channel1brightpowmap;
    ofParameter<float> channel1huepowmap;
    ofParameter<float> channel1saturationpowmap;
    
    
    
    //frame buffer 0 settings
    ofxGuiGroup *framebuffer0Group;
    
    ofParameter<int> FB0mix;
    ofParameter<float> fb0blend;
    ofParameter<float> fb0lumakeyvalue;
    ofParameter<float> fb0lumakeythresh;
    ofParameter<int> fb0delayamnt;
    
    ofParameter<float> fb0_hue;
    ofParameter<float> fb0_saturation;
    ofParameter<float> fb0_bright;
    ofParameter<bool> fb0_hue_invert;
    ofParameter<bool> fb0_saturation_invert;
    ofParameter<bool> fb0_bright_invert;
    ofParameter<bool> fb0_vflip_switch;
    ofParameter<bool> fb0_hflip_switch;
    ofParameter<bool> fb0_toroid_switch;
    ofParameter<float> fb0_huex_mod;
    ofParameter<float> fb0_huex_offset;
    ofParameter<float> fb0_huex_lfo;
    ofParameter<float> fb0_x_displace;
    ofParameter<float> fb0_y_displace;
    ofParameter<float> fb0_z_displace;
    ofParameter<float> fb0_rotate;
    
    //framebuffer 1 settings
    ofxGuiGroup *framebuffer1Group;
    ofParameter<int> FB1mix;
    ofParameter<float> fb1blend;
    ofParameter<float> fb1lumakeyvalue;
    ofParameter<float> fb1lumakeythresh;
    
    ofParameter<int> fb1delayamnt;
    
    ofParameter<float> fb1_hue;
    ofParameter<float> fb1_saturation;
    ofParameter<float> fb1_bright;
    ofParameter<bool> fb1_hue_invert;
    ofParameter<bool> fb1_saturation_invert;
    ofParameter<bool> fb1_bright_invert;
    ofParameter<bool> fb1_vflip_switch;
    ofParameter<bool> fb1_hflip_switch;
    ofParameter<bool> fb1_toroid_switch;
    ofParameter<float> fb1_huex_mod;
    ofParameter<float> fb1_huex_offset;
    ofParameter<float> fb1_huex_lfo;
    ofParameter<float> fb1_x_displace;
    ofParameter<float> fb1_y_displace;
    ofParameter<float> fb1_z_displace;
    ofParameter<float> fb1_rotate;
    
    //pixelation settings
    ofxGuiGroup *pixcamgroup;
    ofParameter<bool> cam1_pixel_switch;
    ofParameter<int> cam1_pixel_scale;
    ofParameter<float> cam1_pixel_mix;
    ofParameter<float> cam1_pixel_brightscale;
    
    ofxGuiGroup *pixbuffergroup;
    ofParameter<bool> fb0_pixel_switch;
    ofParameter<int> fb0_pixel_scale;
    ofParameter<float> fb0_pixel_mix;
    ofParameter<float> fb0_pixel_brightscale;
    
    ofParameter<bool> fb1_pixel_switch;
    ofParameter<int> fb1_pixel_scale;
    ofParameter<float> fb1_pixel_mix;
    ofParameter<float> fb1_pixel_brightscale;
    
    //global settings
    ofxGuiGroup *globalgroup;
    ofParameter<float> blur_amount;
    ofParameter<float> sharpen_amount;
    ofParameter<float> y_skew;
    ofParameter<float> x_skew;
    ofParameter<bool> cam1_vflip_switch;
    ofParameter<bool> cam1_hflip_switch;
    ofParameter<float> cam1_scale;
    
    
    
};
