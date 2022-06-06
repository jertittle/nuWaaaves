//
//  GuiApp.h
//  NuWaaaves
//
//  Created by Mac User on 5/24/22.
//
#pragma once

#include "ofMain.h"
#include "ofxImGui.h"

class GuiApp : public ofBaseApp{
    
public:
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int);
    
    ofxImGui::Gui gui;
    
    
    
    //channel 1 settings
    
    
    int channel1 = 1;
    
    float ch1_hue=1.0;
    float ch1_saturation=1.0;
    float ch1_bright=1.0;
    bool ch1_hue_alt_invert_toggle=0;
    bool ch1_saturation_alt_invert_toggle=0;
    bool ch1_bright_alt_invert_toggle=0;
    bool ch1_saturation_wrap=0;
    bool ch1_bright_wrap=0;
    bool ch1hue_powmaptoggle=0;
    bool ch1sat_powmaptoggle=0;
    bool ch1bright_powmaptoggle=0;
    float ch1_hue_powmap=1.0;
    float ch1_saturation_powmap=1.0;
    float ch1_bright_powmap=1.0;
    
    
    
    
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
    
    
    
};
