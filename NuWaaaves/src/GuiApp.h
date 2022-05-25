//
//  GuiApp.h
//  NuWaaaves
//
//  Created by Mac User on 5/24/22.
//
#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class GuiApp : public ofBaseApp{
    
public:
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int);
    
    //each ofxPanel is a floating window
    ofxPanel inputs;
    ofxPanel buffers;
    ofxPanel globals;
    ofxPanel pixelations;
    
    //channel 1 settings
    //gui groups are colapseable folders
    ofxGuiGroup channel1Group;
    
    ofxIntSlider channel1;
    
    ofxFloatSlider channel1hue;
    ofxFloatSlider channel1saturation;
    ofxFloatSlider channel1bright;
    ofxToggle channel1satwrap;
    ofxToggle channel1brightwrap;
    ofxToggle ch1hue_powmaptoggle;
    ofxToggle ch1sat_powmaptoggle;
    ofxToggle ch1bright_powmaptoggle;
    ofxFloatSlider channel1brightpowmap;
    ofxFloatSlider channel1huepowmap;
    ofxFloatSlider channel1saturationpowmap;
    
    
    
    //frame buffer 0 settings
    ofxGuiGroup framebuffer0Group;
    
    ofxIntSlider FB0mix;
    ofxFloatSlider fb0blend;
    ofxFloatSlider fb0lumakeyvalue;
    ofxFloatSlider fb0lumakeythresh;
    ofxIntSlider fb0delayamnt;
    
    ofxFloatSlider fb0_hue;
    ofxFloatSlider fb0_saturation;
    ofxFloatSlider fb0_bright;
    ofxToggle fb0_hue_invert;
    ofxToggle fb0_saturation_invert;
    ofxToggle fb0_bright_invert;
    ofxToggle fb0_vflip_switch;
    ofxToggle fb0_hflip_switch;
    ofxToggle fb0_toroid_switch;
    ofxFloatSlider fb0_huex_mod;
    ofxFloatSlider fb0_huex_offset;
    ofxFloatSlider fb0_huex_lfo;
    ofxFloatSlider fb0_x_displace;
    ofxFloatSlider fb0_y_displace;
    ofxFloatSlider fb0_z_displace;
    ofxFloatSlider fb0_rotate;
    
    //framebuffer 1 settings
    ofxGuiGroup framebuffer1Group;
    ofxIntSlider FB1mix;
    ofxFloatSlider fb1blend;
    ofxFloatSlider fb1lumakeyvalue;
    ofxFloatSlider fb1lumakeythresh;
    
    ofxIntSlider fb1delayamnt;
    
    ofxFloatSlider fb1_hue;
    ofxFloatSlider fb1_saturation;
    ofxFloatSlider fb1_bright;
    ofxToggle fb1_hue_invert;
    ofxToggle fb1_saturation_invert;
    ofxToggle fb1_bright_invert;
    ofxToggle fb1_vflip_switch;
    ofxToggle fb1_hflip_switch;
    ofxToggle fb1_toroid_switch;
    ofxFloatSlider fb1_huex_mod;
    ofxFloatSlider fb1_huex_offset;
    ofxFloatSlider fb1_huex_lfo;
    ofxFloatSlider fb1_x_displace;
    ofxFloatSlider fb1_y_displace;
    ofxFloatSlider fb1_z_displace;
    ofxFloatSlider fb1_rotate;
    
    //pixelation settings
    ofxGuiGroup pixcamgroup;
    ofxToggle cam1_pixel_switch;
    ofxIntSlider cam1_pixel_scale;
    ofxFloatSlider cam1_pixel_mix;
    ofxFloatSlider cam1_pixel_brightscale;
    
    ofxGuiGroup pixbuffergroup;
    ofxToggle fb0_pixel_switch;
    ofxIntSlider fb0_pixel_scale;
    ofxFloatSlider fb0_pixel_mix;
    ofxFloatSlider fb0_pixel_brightscale;
    
    ofxToggle fb1_pixel_switch;
    ofxIntSlider fb1_pixel_scale;
    ofxFloatSlider fb1_pixel_mix;
    ofxFloatSlider fb1_pixel_brightscale;
    
    //global settings
    ofxGuiGroup globalgroup;
    ofxFloatSlider blur_amount;
    ofxFloatSlider sharpen_amount;
    ofxFloatSlider y_skew;
    ofxFloatSlider x_skew;
    ofxToggle cam1_vflip_switch;
    ofxToggle cam1_hflip_switch;
    ofxFloatSlider cam1_scale;
    
    
    
};
