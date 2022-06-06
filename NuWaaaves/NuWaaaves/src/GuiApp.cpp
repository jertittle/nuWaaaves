//
//  GuiApp.cpp
//  NuWaaaves
//
//  Created by Mac User on 5/24/22.
//

#include "GuiApp.h"

int fbob = 30;

void GuiApp::setup(){
    
    ofBackground(0);
    
    gui.setup();
    
}
//----------------------------------
void GuiApp::update() {
    
}


//------------------------------
void GuiApp::draw() {
    
    
    
    auto mainSettings = ofxImGui::Settings();
    
    //list variables for ranges...not this time but probably at some point in the future
    //should normalize everything in the gui to -1 1 and then add coeffecients in ofApp.cpp
    float x_y_d=40;
    float lfom=10;
    
    
    int gui_hscaler=170;
    int gui_vscaler=80;
    ImGui::SetNextWindowPos(ImVec2(0*gui_hscaler, 0*gui_vscaler), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(gui_hscaler, gui_vscaler), ImGuiCond_FirstUseEver);
    
    
    gui.begin();
    //ofxGuiFloatSlider
    
    
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    
    mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 0*gui_vscaler));
    
    //channel 1 select folder
    if (ofxImGui::BeginWindow("channel1", mainSettings, false))
    {
        if (ImGui::CollapsingHeader("parameters"))
        {
            //ah ok so this is a const char not a string
            ImGui::Text("i'm in a collapsable folder");
            //so for dropdown menues set up a char array of items like so
            const char* items[] = { "none","cam1", "ndi" };
            static int item_current = 1;
            ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
            channel1 = (item_current);
            
            
            
            ImGui::SliderFloat("hue", &ch1_hue, -5.0f, 5.0f);
            ImGui::SliderFloat("saturation", &ch1_saturation, -5.0f, 5.0f);
            ImGui::SliderFloat("bright", &ch1_bright, -5.0f, 5.0f);
            
            ImGui::Checkbox("hue_alternate_invert", &ch1_hue_alt_invert_toggle);
            ImGui::Checkbox("saturation_alternate_invert", &ch1_saturation_alt_invert_toggle);
            ImGui::Checkbox("bright_alternate_invert", &ch1_bright_alt_invert_toggle);
            
            ImGui::Checkbox("saturation_wrap", &ch1_saturation_wrap);
            ImGui::Checkbox("bright_wrap", &ch1_bright_wrap);
            
            ImGui::SliderFloat("hue_powmap", &ch1_hue_powmap, -5.0f, 5.0f);
            ImGui::SliderFloat("saturation_powmap", &ch1_saturation_powmap, -5.0f, 5.0f);
            ImGui::SliderFloat("bright_powmap", &ch1_bright_powmap, -5.0f, 5.0f);
            
            
        }
        
        ImGui::Separator();
        
        if (ImGui::CollapsingHeader("pixelations")){
            if (ImGui::CollapsingHeader("cam pixelations")){
                ImGui::Checkbox("pixelate", &cam1_pixel_switch);
                ImGui::SliderInt("pixel scale_x", &cam1_pixel_scale_x, .0f, 256.0f);
                ImGui::SliderInt("pixel scale_y", &cam1_pixel_scale_y, .0f, 256.0f);
                ImGui::SliderFloat("pixel mix", &cam1_pixel_mix, -2.0f, 2.0f);
                ImGui::SliderFloat("bright_scale", &cam1_pixel_brightscale, -2.0f, 2.0f);
            }
            
            if (ImGui::CollapsingHeader("NDI pixelations")){
                
                
                ImGui::Checkbox("pixelate", &ndi_pixel_switch);
                ImGui::SliderInt("pixel scale_x", &ndi_pixel_scale_x, .0f, 256.0f);
                ImGui::SliderInt("pixel scale_y", &ndi_pixel_scale_y, .0f, 256.0f);
                ImGui::SliderFloat("pixel mix", &ndi_pixel_mix, -2.0f, 2.0f);
                ImGui::SliderFloat("bright_scale", &ndi_pixel_brightscale, -2.0f, 2.0f);
                
            }
        }
        
        
        
    }//endImguiWindow
    ofxImGui::EndWindow(mainSettings);
    
    
    
    mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 0*gui_vscaler));
    
    
    //fb0 folder
    if (ofxImGui::BeginWindow("fb0", mainSettings, false)){
        
        if (ImGui::CollapsingHeader("parameters")){
            //-------------------------------------------------------------------------------
            if (ImGui::CollapsingHeader("mix and delay amount")){
                ImGui::SliderFloat("fb0_mix", &fb0_mix, -2.0f, 2.0f);
                ImGui::SliderFloat("fb0_key_value", &fb0_key_value, .0f, 1.0f);
                ImGui::SliderFloat("fb0_key_threshold", &fb0_key_threshold, .0f, 1.0f);
                ImGui::SliderInt("fb0_delay_amount", &fb0_delay_amount, 0, fbob-1);
            }
            //-------------------------------------------------------------------------------
            if (ImGui::CollapsingHeader("misc switches")){
                
                const char* items2[] = { "clamp","toroid","mirror" };
                static int item_current2 = 0;
                ImGui::Combo("overflow select", &item_current2, items2, IM_ARRAYSIZE(items2));
                fb0_toroid_switch=item_current2;
                
                ImGui::Checkbox("fb0_h_mirror", &fb0_hflip_switch);
                ImGui::Checkbox("fb0_v_mirror", &fb0_vflip_switch);
                
                ImGui::Checkbox("fb0_hue_invert", &fb0_hue_invert);
                ImGui::Checkbox("fb0_saturation_invert", &fb0_saturation_invert);
                ImGui::Checkbox("fb0_bright_invert", &fb0_bright_invert);
            }
            //-------------------------------------------------------------------------------
            if (ImGui::CollapsingHeader("color space")){
                
                ImGui::SliderFloat("fb0_hue", &fb0_hue, 8.0f, 12.0f);
                ImGui::SliderFloat("fb0_saturation", &fb0_saturation, 8.0f, 12.0f);
                ImGui::SliderFloat("fb0_bright", &fb0_bright, 1.0f, 12.0f);
                ImGui::SliderFloat("fb0_huex_mod", &fb0_huex_mod, 0.0f, 10.0f);
                ImGui::SliderFloat("fb0_huex_offset", &fb0_huex_offset, -20.0f, 20.0f);
                ImGui::SliderFloat("fb0_huex_lfo", &fb0_huex_lfo, -20.0f, 20.0f);
                
            }
            //-------------------------------------------------------------------------------
            if (ImGui::CollapsingHeader("fb0 ranges")){
                ImGui::SliderFloat("fb0 x displace range", &fb0_x_displace_range, .0001f, 100.0f);
                ImGui::SliderFloat("fb0 y displace range", &fb0_y_displace_range, .0001f, 100.0f);
                ImGui::SliderFloat("fb0 z displace range", &fb0_z_displace_range, .0001f, 100.0f);
                ImGui::SliderFloat("fb0 rotate range", &fb0_rotate_range, .0001f, TWO_PI);
            }
            //-------------------------------------------------------------------------------
            if (ImGui::CollapsingHeader("geometry")){
                
                ImGui::SliderFloat("fb0_x", &fb0_x_displace, -fb0_x_displace_range, fb0_x_displace_range);
                ImGui::SliderFloat("fb0_y", &fb0_y_displace, -fb0_y_displace_range, fb0_y_displace_range);
                ImGui::SliderFloat("fb0_z", &fb0_z_displace,  100.0f-fb0_z_displace_range, 100.0f+fb0_z_displace_range);
                ImGui::SliderFloat("fb0_rotate", &fb0_rotate, -fb0_rotate_range, fb0_rotate_range);
            }
        }
        ImGui::Separator();
        
        if (ImGui::CollapsingHeader("fb0 pixelations")){
            
            ImGui::Checkbox("pixelate", &fb0_pixel_switch);
            
            ImGui::SliderInt("pixel scale x", &fb0_pixel_scale_x, .0f, 256.0f);
            ImGui::SliderInt("pixel scale y", &fb0_pixel_scale_y, .0f, 256.0f);
            ImGui::SliderFloat("pixel mix", &fb0_pixel_mix, -2.0f, 2.0f);
            ImGui::SliderFloat("bright_scale", &fb0_pixel_brightscale, -2.0f, 2.0f);
        }
    }
    ofxImGui::EndWindow(mainSettings);
    
    
    
    mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 1*gui_vscaler));
    
    
    //fb1 folder
    if (ofxImGui::BeginWindow("fb1", mainSettings, false)){
        
        if (ImGui::CollapsingHeader("parameters")){
            //-------------------------------------------------------------------------------
            if (ImGui::CollapsingHeader("mix and delay amount")){
                ImGui::SliderFloat("fb1_mix", &fb1_mix, -2.0f, 2.0f);
                ImGui::SliderFloat("fb1_key_value", &fb1_key_value, .0f, 1.0f);
                ImGui::SliderFloat("fb1_key_threshold", &fb1_key_threshold, .0f, 1.0f);
                ImGui::SliderInt("fb1_delay_amount", &fb1_delay_amount, 0, fbob-1);
            }
            //-------------------------------------------------------------------------------
            if (ImGui::CollapsingHeader("misc switches")){
                
                const char* items2[] = { "clamp","toroid","mirror" };
                static int item_current2 = 0;
                ImGui::Combo("overflow select", &item_current2, items2, IM_ARRAYSIZE(items2));
                fb1_toroid_switch=item_current2;
                
                ImGui::Checkbox("fb1_h_mirror", &fb1_hflip_switch);
                ImGui::Checkbox("fb1_v_mirror", &fb1_vflip_switch);
                
                ImGui::Checkbox("fb1_hue_invert", &fb1_hue_invert);
                ImGui::Checkbox("fb1_saturation_invert", &fb1_saturation_invert);
                ImGui::Checkbox("fb1_bright_invert", &fb1_bright_invert);
            }
            //-------------------------------------------------------------------------------
            if (ImGui::CollapsingHeader("color space")){
                
                ImGui::SliderFloat("fb1_hue", &fb1_hue, 8.0f, 12.0f);
                ImGui::SliderFloat("fb1_saturation", &fb1_saturation, 8.0f, 12.0f);
                ImGui::SliderFloat("fb1_bright", &fb1_bright, 1.0f, 12.0f);
                ImGui::SliderFloat("fb1_huex_mod", &fb1_huex_mod, 0.0f, 10.0f);
                ImGui::SliderFloat("fb1_huex_offset", &fb1_huex_offset, -20.0f, 20.0f);
                ImGui::SliderFloat("fb1_huex_lfo", &fb1_huex_lfo, -20.0f, 20.0f);
                
            }
            //-------------------------------------------------------------------------------
            if (ImGui::CollapsingHeader("fb1 ranges")){
                ImGui::SliderFloat("fb1 x displace range", &fb1_x_displace_range, .0001f, 100.0f);
                ImGui::SliderFloat("fb1 y displace range", &fb1_y_displace_range, .0001f, 100.0f);
                ImGui::SliderFloat("fb1 z displace range", &fb1_z_displace_range, .0001f, 100.0f);
                ImGui::SliderFloat("fb1 rotate range", &fb1_rotate_range, .0001f, TWO_PI);
            }
            //-------------------------------------------------------------------------------
            if (ImGui::CollapsingHeader("geometry")){
                
                ImGui::SliderFloat("fb1_x", &fb1_x_displace, -fb1_x_displace_range, fb1_x_displace_range);
                ImGui::SliderFloat("fb1_y", &fb1_y_displace, -fb1_y_displace_range, fb1_y_displace_range);
                ImGui::SliderFloat("fb1_z", &fb1_z_displace,  100.0f-fb1_z_displace_range, 100.0f+fb1_z_displace_range);
                ImGui::SliderFloat("fb1_rotate", &fb1_rotate, -fb1_rotate_range, fb1_rotate_range);
            }
        }
        
        ImGui::Separator();
        
        if (ImGui::CollapsingHeader("fb1 pixelations")){
            
            ImGui::Checkbox("pixelate", &fb1_pixel_switch);
            
            ImGui::SliderInt("pixel scale x", &fb1_pixel_scale_x, .0f, 256.0f);
            ImGui::SliderInt("pixel scale y", &fb1_pixel_scale_y, .0f, 256.0f);
            ImGui::SliderFloat("pixel mix", &fb1_pixel_mix, -2.0f, 2.0f);
            ImGui::SliderFloat("bright_scale", &fb1_pixel_brightscale, -2.0f, 2.0f);
        }
    }
    ofxImGui::EndWindow(mainSettings);
    
    
    
    mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 3*gui_vscaler));
    
    if (ofxImGui::BeginWindow("global", mainSettings, false))
    {
        if (ImGui::CollapsingHeader("global params"))
        {
            //blur
            ImGui::SliderFloat("blur amount", &blur_amount, -2.0f, 2.0f);
            ImGui::SliderFloat("blur radius", &blur_radius, .0f, 10.0f);
            //sharpen
            ImGui::SliderFloat("sharpen", &sharpen_amount, -.6f, .6f);
            ImGui::SliderFloat("sharpen_radius", &sharpen_radius, .0f, 10.f);
            
            ImGui::SliderFloat("sharpen_boost", &sharpen_boost, .0f, 1.0f);
            
            
            //camscale
            ImGui::SliderFloat("cam1_scale", &cam1_scale, .0f, 2.0f);
            
            ImGui::SliderFloat("ndi_scale", &ndi_scale, -1000.0f, 500.0f);
            //camflip
            ImGui::Checkbox("cam1_hflip", &cam1_hflip_switch);
            ImGui::Checkbox("cam1_vflip", &cam1_vflip_switch);
            
            
            //xskew
            ImGui::SliderFloat("x_skew", &x_skew, -3.14f, 3.14f);
            //yskew
            ImGui::SliderFloat("y_skew", &y_skew, -3.14f, 3.14f);
        }
        
        
    }
    
    ofxImGui::EndWindow(mainSettings);
    
    
    gui.end();
}

void GuiApp::keyPressed(int key) {
    
    
}


//---------------------------
