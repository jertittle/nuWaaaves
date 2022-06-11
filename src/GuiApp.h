//
//  GuiApp.h
//  NuWaaaves
//
//  Created by Jer on 5/24/22.
//
#pragma once

#include "ofMain.h"
#include "ofxImGui.h"
#include "ofxMidi.h"


class GuiApp : public ofBaseApp, public ofxMidiListener {
    
public:
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int);
    void exit();
    
    ofxImGui::Gui gui;
    
    //------------------- MIDI Biz
    void newMidiMessage(ofxMidiMessage& eventArgs);
    void getMidi();//midi bizzzzz
    
float addMidi(int,float);
   
    
    float cc[128] = {0};//dummys
    
    
    ofxMidiIn midiIn;
    std::vector<ofxMidiMessage> midiMessages;
    std::size_t maxMessages = 10; //< max number of messages to keep track of. okay So I think this is redundant right now.
    //it could be required for keeping sync I guess.
    //it's filling an array of values but we only ever need the last value the controller sends.
    //We can think of it like a "shift register" for polyphony.
    //could use this vector to introduce particles to the system tho.
    //could also introduce custom interpolation between values here.
    
    //channel 1 settings    
    int channel1_select = 1;
    
    float ch1_hue=1.0;
    float ch1_saturation=1.0;
    float ch1_bright=1.0;
    bool ch1_hue_alt_invert_toggle=0;
    bool ch1_saturation_alt_invert_toggle=0;
    bool ch1_bright_alt_invert_toggle=0;
    bool ch1_saturation_wrap=0;
    bool ch1_bright_wrap=0;
   
    float ch1_hue_powmap=1.0;
    float ch1_saturation_powmap=1.0;
    float ch1_bright_powmap=1.0;
    
    //channel 2 settings
    int channel2_select = 1;
    float ch2_mix=0;
    float ch2_key_value=0;
    float ch2_key_thresh=0;
    float ch2_bright=1.0;
    float ch2_hue=1.0;
    float ch2_saturation=1.0;
    bool ch2_hue_alt_invert_toggle=0;
    bool ch2_saturation_alt_invert_toggle=0;
    bool ch2_bright_alt_invert_toggle=0;
    bool ch2_saturation_wrap=0;
    bool ch2_bright_wrap=0;
    float ch2_bright_powmap=1.0;
    float ch2_hue_powmap=1.0;
    float ch2_saturation_powmap=1.0;
    
    
    
    //frame buffer 0 settings
    float fb0_mix=0;
    float fb0_key_value=0;
    float fb0_key_threshold=0;
    int fb0_delay_amount=0;
    
    bool fb0_hue_invert=0;
    bool fb0_saturation_invert=0;
    bool fb0_bright_invert=0;
    bool fb0_vflip_switch=0;
    bool fb0_hflip_switch=0;
    int fb0_toroid_switch=0;
    
    float fb0_hue=10.0;
    float fb0_saturation=10.0;
    float fb0_bright=10.0;
    float fb0_huex_mod=10.0;
    float fb0_huex_offset=0;
    float fb0_huex_lfo=0;
    
    
    //fb0 rangemods
    float fb0_x_displace_range=40;
    float fb0_y_displace_range=40;
    float fb0_z_displace_range=10;
    float fb0_rotate_range= PI;
    
    float fb0_x_displace=0;
    float fb0_y_displace=0;
    float fb0_z_displace=100;
    float fb0_rotate=0;
    
    //framebuffer 1 settings
    
    float fb1_mix=0;
    float fb1_key_value=0;
    float fb1_key_threshold=0;
    int fb1_delay_amount=0;
    
    bool fb1_hue_invert=0;
    bool fb1_saturation_invert=0;
    bool fb1_bright_invert=0;
    bool fb1_vflip_switch=0;
    bool fb1_hflip_switch=0;
    int fb1_toroid_switch=0;
    
    float fb1_hue=10.0;
    float fb1_saturation=10.0;
    float fb1_bright=10.0;
    float fb1_huex_mod=10.0;
    float fb1_huex_offset=0;
    float fb1_huex_lfo=0;
    
    
    //fb1 rangemods
    float fb1_x_displace_range=40;
    float fb1_y_displace_range=40;
    float fb1_z_displace_range=10;
    float fb1_rotate_range= PI;
    
    float fb1_x_displace=0;
    float fb1_y_displace=0;
    float fb1_z_displace=100;
    float fb1_rotate=0;
    
    //pixelation settings
    bool cam1_pixel_switch=0;
    int cam1_pixel_scale_x=64;
    int cam1_pixel_scale_y=64;
    float cam1_pixel_mix=1.0;
    float cam1_pixel_brightscale=0;
    
    bool fb0_pixel_switch=0;
    int fb0_pixel_scale_x=64;
    int fb0_pixel_scale_y=64;
    float fb0_pixel_mix=1.0;
    float fb0_pixel_brightscale=0;
    
    bool fb1_pixel_switch=0;
    int fb1_pixel_scale_x=64;
    int fb1_pixel_scale_y=64;
    float fb1_pixel_mix=1.0;
    float fb1_pixel_brightscale=0;
    
    bool ndi_pixel_switch=0;
    int ndi_pixel_scale_x=64;//=64;
    int ndi_pixel_scale_y=64;//=64;
    float ndi_pixel_mix=1.0;//=1;
    float ndi_pixel_brightscale=0;//=0;
    
    
    //global settings
    bool framebuffer_clear = 0;
    float blur_amount=0;
    float blur_radius=1.0;
    float sharpen_amount=0;
    float sharpen_radius=1.0;//=1.0;
    float sharpen_boost=0;//=0.0;
    float y_skew=0;
    float x_skew=0;
    bool cam1_vflip_switch=0;
    bool cam1_hflip_switch=0;
    float cam1_scale=1.0;
    float ndi_scale=0;//=0;
    
    float tittle_scale=1;
    
    //----------------- keyboard vars
    bool enableKeys = 0;
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

    
    //--------- TITTLER
       char str[64] = {0};//current max char length
       float textScale = 1.0;
       bool setAa = false;
       ImVec4 textColor;
    
    
};
