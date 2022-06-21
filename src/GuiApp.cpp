//
//  GuiApp.cpp
//  NuWaaaves
//
//  Created by Jer on 5/24/22.
//

#include "GuiApp.h"


int fbob = 30;

void GuiApp::setup(){
    
    ofBackground(0);
    //ofSetLogLevel(OF_LOG_VERBOSE);
    // print input ports to console
    midiIn.listInPorts();
    
    // open port by number (you may need to change this)
    midiIn.openPort(1);
    //midiIn.openPort("IAC Pure Data In");    // by name
    //midiIn.openVirtualPort("ofxMidiIn Input"); // open a virtual port
    
    // don't ignore sysex, timing, & active sense messages,
    // these are ignored by default
    midiIn.ignoreTypes(false, false, false);
    
    // add ofApp as a listener
    midiIn.addListener(this);
    
    // print received messages to the console
    // midiIn.setVerbose(true);
    
    gui.setup();
    
    textColor = ofColor(255,255,255,255);
    
    ofShowCursor();
    
}
//----------------------------------
void GuiApp::update() {
    
    //getMidi();
}


//------------------------------
void GuiApp::draw() {
    
    
    
    auto mainSettings = ofxImGui::Settings();
    
    //this is used to pass parameters to the tabing object
    //this is default, tabs are open one at a time
    ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
    
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
    
    //-------------------------------------- debugmenu
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    
    ImGui::Checkbox( "eanble keyboard controls", &enableKeys );
    
    ImGui::Checkbox( "hide mouse", &hide_mouse );
    
    if (ImGui::Button("CUSTOM THEME"))
    {
        gui.setTheme(new MyTheme());
        
    }ImGui::SameLine();
    
    if (ImGui::Button("DEFAULT THEME"))
    {
        gui.setTheme(new ofxImGui::DefaultTheme());
        
    }
    //---------------------------------------------
    
    mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 0*gui_vscaler));
    
    //channel 1 select folder
    if (ofxImGui::BeginWindow("channel1", mainSettings, false))
    {
        if (ImGui::CollapsingHeader("parameters"))
        {
            //so for dropdown menues set up a char array of items like so
            const char* items[] = { "cam1", "cam2", "ndi", "tittler" };
            static int item_current = 0;
            ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
            channel1_select=1 + item_current;
            
            
            //begin slider + toggles tabs
            
            //the string variable here needs to be unique to each tab group
            //the states of which tab is/was open last needs to be stored?
            if (ImGui::BeginTabBar("ch1_parameter_tabs", tab_bar_flags))
            {
                if (ImGui::BeginTabItem("Sliders"))
                {
                    ImGui::Text("This is the Silders tab!\nblah blah blah blah blah");
                    ImGui::SliderFloat("hue", &ch1_hue, -5.0f, 5.0f);
                    ImGui::SliderFloat("saturation", &ch1_saturation, -5.0f, 5.0f);
                    ImGui::SliderFloat("bright", &ch1_bright, -5.0f, 5.0f);
                    ImGui::SliderFloat("hue_powmap", &ch1_hue_powmap, -5.0f, 5.0f);
                    ImGui::SliderFloat("saturation_powmap", &ch1_saturation_powmap, -5.0f, 5.0f);
                    ImGui::SliderFloat("bright_powmap", &ch1_bright_powmap, -5.0f, 5.0f);
                    ImGui::EndTabItem();
                }
                
                if (ImGui::BeginTabItem("Toggles"))
                {
                    ImGui::Text("This is the Toggles tab!\nblah blah blah blah blah");
                    ImGui::Checkbox("hue_alternate_invert", &ch1_hue_alt_invert_toggle);
                    ImGui::Checkbox("saturation_alternate_invert", &ch1_saturation_alt_invert_toggle);
                    ImGui::Checkbox("bright_alternate_invert", &ch1_bright_alt_invert_toggle);
                    ImGui::Checkbox("saturation_wrap", &ch1_saturation_wrap);
                    ImGui::Checkbox("bright_wrap", &ch1_bright_wrap);
                    ImGui::EndTabItem();
                }
                
                
                ImGui::EndTabBar();
            }//end sliders+toggles tabs
            
            
            
            
            
            
            
            
        }
        
        ImGui::Separator();
        
        if (ImGui::CollapsingHeader("Input pixelations")){
            
            
            
            if (ImGui::BeginTabBar("ch1_pixel_tabs", tab_bar_flags))
            {
                if (ImGui::BeginTabItem("cam1"))
                {
                    ImGui::Checkbox("pixelate", &cam1_pixel_switch);
                    ImGui::SliderInt("pixel scale_x", &cam1_pixel_scale_x, .0f, 256.0f);
                    ImGui::SliderInt("pixel scale_y", &cam1_pixel_scale_y, .0f, 256.0f);
                    ImGui::SliderFloat("pixel mix", &cam1_pixel_mix, -2.0f, 2.0f);
                    ImGui::SliderFloat("bright_scale", &cam1_pixel_brightscale, -2.0f, 2.0f);
                    ImGui::EndTabItem();
                }
                if (ImGui::BeginTabItem("cam2"))
                {
                    ImGui::Checkbox("pixelate", &cam2_pixel_switch);
                    ImGui::SliderInt("pixel scale_x", &cam2_pixel_scale_x, .0f, 256.0f);
                    ImGui::SliderInt("pixel scale_y", &cam2_pixel_scale_y, .0f, 256.0f);
                    ImGui::SliderFloat("pixel mix", &cam2_pixel_mix, -2.0f, 2.0f);
                    ImGui::SliderFloat("bright_scale", &cam2_pixel_brightscale, -2.0f, 2.0f);
                    ImGui::EndTabItem();
                }
                if (ImGui::BeginTabItem("NDI"))
                {
                    ImGui::Checkbox("pixelate", &ndi_pixel_switch);
                    ImGui::SliderInt("pixel scale_x", &ndi_pixel_scale_x, .0f, 256.0f);
                    ImGui::SliderInt("pixel scale_y", &ndi_pixel_scale_y, .0f, 256.0f);
                    ImGui::SliderFloat("pixel mix", &ndi_pixel_mix, -2.0f, 2.0f);
                    ImGui::SliderFloat("bright_scale", &ndi_pixel_brightscale, -2.0f, 2.0f);
                    ImGui::EndTabItem();
                }
                
                ImGui::EndTabBar();
            }
            
            
            
        }
        
        
        
    }//endImguiWindow
    ofxImGui::EndWindow(mainSettings);
    
    mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 1*gui_vscaler));
    
    //channel 2 select folder
    if (ofxImGui::BeginWindow("channel2", mainSettings, false))
    {
        if (ImGui::CollapsingHeader("parameters"))
        {
            //so for dropdown menues set up a char array of items like so
            const char* items[] = { "cam1", "cam2", "ndi", "tittler" };
            static int item_current = 0;
            ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
            channel2_select= 1+ item_current;
            
            
            
            ImGui::SliderFloat("ch2_mix", &ch2_mix, -2.0f, 2.0f);
            ImGui::SliderFloat("ch2_key_value", &ch2_key_value, .0f, 1.0f);
            ImGui::SliderFloat("ch2_key_thresh", &ch2_key_thresh, .0f, 1.0f);
            
            ImGui::SliderFloat("hue", &ch2_hue, -5.0f, 5.0f);
            ImGui::SliderFloat("saturation", &ch2_saturation, -5.0f, 5.0f);
            ImGui::SliderFloat("bright", &ch2_bright, -5.0f, 5.0f);
            
            ImGui::Checkbox("hue_alternate_invert", &ch2_hue_alt_invert_toggle);
            ImGui::Checkbox("saturation_alternate_invert", &ch2_saturation_alt_invert_toggle);
            ImGui::Checkbox("bright_alternate_invert", &ch2_bright_alt_invert_toggle);
            
            ImGui::Checkbox("saturation_wrap", &ch2_saturation_wrap);
            ImGui::Checkbox("bright_wrap", &ch2_bright_wrap);
            
            ImGui::SliderFloat("hue_powmap", &ch2_hue_powmap, -5.0f, 5.0f);
            ImGui::SliderFloat("saturation_powmap", &ch2_saturation_powmap, -5.0f, 5.0f);
            ImGui::SliderFloat("bright_powmap", &ch2_bright_powmap, -5.0f, 5.0f);
            
            
        }
    }//endImguiWindow
    ofxImGui::EndWindow(mainSettings);
    
    
    mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 2*gui_vscaler));
    
    
    //fb0 folder
    if (ofxImGui::BeginWindow("fb0", mainSettings, false)){
        
        if (ImGui::CollapsingHeader("parameters")){
            //-------------------------------------------------------------------------------
            if (ImGui::CollapsingHeader("mix and delay amount")){
                
                if (ImGui::BeginTabBar("fb0_mix_tab", tab_bar_flags))
                {
                    if (ImGui::BeginTabItem("main"))
                    {
                        ImGui::SliderFloat("fb0_mix", &fb0_mix, -2.0f, 2.0f);
                        ImGui::SliderFloat("fb0_key_value", &fb0_key_value, .0f, 1.0f);
                        ImGui::SliderFloat("fb0_key_threshold", &fb0_key_threshold, .0f, 1.0f);
                       
                        ImGui::EndTabItem();
                    }
                    if (ImGui::BeginTabItem("texmod"))
                    {
                        // ImGui::Checkbox("tex_mod", &fb0_tex_mod);
                        const char* items[] = { "channel 1","channel 2" };
                        static int item_current = 0;
                        ImGui::Combo("texmod select", &item_current, items, IM_ARRAYSIZE(items));
                        if(item_current==0){fb0_texmod_select=1;}
                        if(item_current==1){fb0_texmod_select=2;}
                        
                        ImGui::SliderFloat("texmod fb0_mix", &tex_fb0_mix, -2.0f, 2.0f);
                        ImGui::SliderFloat("texmod fb0_key_value", &tex_fb0_key_value, .0f, 1.0f);
                        ImGui::SliderFloat("texmod fb0_key_threshold", &tex_fb0_key_threshold, .0f, 1.0f);
                        ImGui::EndTabItem();
                    }
                    
                    ImGui::EndTabBar();
                }
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
                
                if(ImGui::TreeNode("color1")) {//this label has creates a unique flag state for trees. meaning if a node shares a string it shares a state
                    
                    if (ImGui::BeginTabBar("fb0_color1", tab_bar_flags))
                    {
                        if (ImGui::BeginTabItem("color1"))
                        {
                            ImGui::SliderFloat("fb0_hue", &fb0_hue, 8.0f, 12.0f);
                            ImGui::SliderFloat("fb0_saturation", &fb0_saturation, 8.0f, 12.0f);
                            ImGui::SliderFloat("fb0_bright", &fb0_bright, 1.0f, 12.0f);
                            ImGui::SliderFloat("fb0_huex_mod", &fb0_huex_mod, 0.0f, 10.0f);
                            ImGui::SliderFloat("fb0_huex_offset", &fb0_huex_offset, -20.0f, 20.0f);
                            ImGui::SliderFloat("fb0_huex_lfo", &fb0_huex_lfo, -20.0f, 20.0f);
                            ImGui::EndTabItem();
                        }
                        
                        if (ImGui::BeginTabItem("color1_texMod"))
                        {
                            
                            ImGui::SliderFloat("texmod fb0_hue", &tex_fb0_hue, -.25f, .25f);
                            ImGui::SliderFloat("texmod fb0_saturation", &tex_fb0_saturation, -.25f, .25f);
                            ImGui::SliderFloat("texmod fb0_bright", &tex_fb0_bright, -.25f, .25f);
                            ImGui::SliderFloat("texmod fb0_huex_mod", &tex_fb0_huex_mod, -1.0f, 0.0f);
                            ImGui::SliderFloat("texmod fb0_huex_offset", &tex_fb0_huex_offset, -2.0f, 2.0f);
                            ImGui::SliderFloat("texmod fb0_huex_lfo", &tex_fb0_huex_lfo, -2.0f, 2.0f);
                            ImGui::EndTabItem();
                        }
                        ImGui::EndTabBar();
                    }
                    ImGui::TreePop();
                }
                
                if(ImGui::TreeNode("color2")) {
                    ImGui::Text("this is color2 tree WEeeeeeeeeeeee");
                    ImGui::Text("this is color2 tree WEeeeeeeeeeeee");
                    ImGui::Text("this is color2 tree WEeeeeeeeeeeee");
                    ImGui::Text("this is color2 tree WEeeeeeeeeeeee");
                    ImGui::Text("this is color2 tree WEeeeeeeeeeeee");
                    ImGui::TreePop();
                }
                
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
                
                if(ImGui::TreeNode("geo1")) {
                    
                    if (ImGui::BeginTabBar("fb0_displace1", tab_bar_flags))
                    {
                        if (ImGui::BeginTabItem("geo1"))
                        {
                            ImGui::SliderFloat("fb0_x", &fb0_x_displace, -fb0_x_displace_range, fb0_x_displace_range);
                            ImGui::SliderFloat("fb0_y", &fb0_y_displace, -fb0_y_displace_range, fb0_y_displace_range);
                            ImGui::SliderFloat("fb0_z", &fb0_z_displace,  100.0f-fb0_z_displace_range, 100.0f+fb0_z_displace_range);
                            ImGui::SliderFloat("fb0_rotate", &fb0_rotate, -fb0_rotate_range, fb0_rotate_range);
                            ImGui::EndTabItem();
                        }
                        
                        if (ImGui::BeginTabItem("geo1_texMod"))
                        {
                            ImGui::SliderFloat("texmod fb0_x", &tex_fb0_x_displace, -fb0_x_displace_range, fb0_x_displace_range);
                            ImGui::SliderFloat("texmod fb0_y", &tex_fb0_y_displace,  -fb0_y_displace_range, fb0_y_displace_range);
                            ImGui::SliderFloat("texmod fb0_z", &tex_fb0_z_displace,  -fb0_y_displace_range, fb0_y_displace_range);
                            ImGui::SliderFloat("texmod fb0_rotate", &tex_fb0_rotate, -fb0_rotate_range, fb0_rotate_range);
                            ImGui::EndTabItem();
                        }
                        ImGui::EndTabBar();
                    }
                    
                    ImGui::TreePop();
                }
                
                if(ImGui::TreeNode("geo2")) {
                    ImGui::Text("this is color2 tree WEeeeeeeeeeeee");
                    ImGui::Text("this is color2 tree WEeeeeeeeeeeee");
                    ImGui::Text("this is color2 tree WEeeeeeeeeeeee");
                    ImGui::Text("this is color2 tree WEeeeeeeeeeeee");
                    ImGui::Text("this is color2 tree WEeeeeeeeeeeee");
                    ImGui::TreePop();
                }
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
    
    
    
    mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 2*gui_vscaler));
    
    
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
            
            
            framebuffer_clear = ImGui::Button("Clear buffer") ? true : false;
            ndi_clear = ImGui::Button("Clear NDI") ? true : false;
            
            
            //blur
            ImGui::SliderFloat("blur amount", &blur_amount, -2.0f, 2.0f);
            ImGui::SliderFloat("blur radius", &blur_radius, .0f, 10.0f);
            //sharpen
            ImGui::SliderFloat("sharpen", &sharpen_amount, -.6f, .6f);
            ImGui::SliderFloat("sharpen_radius", &sharpen_radius, .0f, 10.f);
            
            ImGui::SliderFloat("sharpen_boost", &sharpen_boost, .0f, 1.0f);
            
            if (ImGui::BeginTabBar("cam_scale_tabs", tab_bar_flags))
            {
                if (ImGui::BeginTabItem("cam1"))
                {
                    //camscale
                    ImGui::SliderFloat("cam1_scale", &cam1_scale, .0f, 2.0f);
                    //camflip
                    ImGui::Checkbox("cam1_hflip", &cam1_hflip_switch);
                    ImGui::Checkbox("cam1_vflip", &cam1_vflip_switch);
                    ImGui::EndTabItem();
                }
                if (ImGui::BeginTabItem("cam2"))
                {
                    ImGui::SliderFloat("cam2_scale", &cam2_scale, .0f, 2.0f);
                    ImGui::Checkbox("cam2_hflip", &cam2_hflip_switch);
                    ImGui::Checkbox("cam2_vflip", &cam2_vflip_switch);
                    ImGui::EndTabItem();
                }
                
                ImGui::EndTabBar();
            }
            
            ImGui::SliderFloat("ndi_scale", &ndi_scale, -1000.0f, 500.0f);
            
            ImGui::SliderFloat("tittle_scale", &tittle_scale, .0f, 2.0f);
            
            //xskew
            ImGui::SliderFloat("x_skew", &x_skew, -3.14f, 3.14f);
            //yskew
            ImGui::SliderFloat("y_skew", &y_skew, -3.14f, 3.14f);
        }
        
        
    }
    
    ofxImGui::EndWindow(mainSettings);
    
    mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 3*gui_vscaler));
    
    //*************** TITTLER ******************
    if (ofxImGui::BeginWindow("Tittler", mainSettings, false))
    {
        ImGui::InputText("text here", str, IM_ARRAYSIZE(str));//this call is why im using a char array. Documentation was wack?
        ImGui::SliderFloat("scale", &textScale, .0f, 20.0f);
        ImGui::Checkbox("anti-Alias", &setAa);
        ImGui::ColorEdit3("Text Color", (float*)&textColor);
    }//endImguiWindow
    ofxImGui::EndWindow(mainSettings);
    
    gui.end();
    
    
}

void GuiApp::newMidiMessage(ofxMidiMessage& msg) {
    
    
    // add the latest message to the message queue
    midiMessages.push_back(msg);
    
    // remove any old messages if we have too many
    while(midiMessages.size() > maxMessages) {
        midiMessages.erase(midiMessages.begin());
    }
    
    getMidi();
    
}

void GuiApp::exit() {
    // clean up
    midiIn.closePort();
    midiIn.removeListener(this);
    
}

void GuiApp::keyPressed(int key) {
    
    
    
    if(key=='3'){
        aa=ss=dd=ff=gg=hh=0;
    }
    
    if(enableKeys) {
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
    
    
}


float GuiApp::addMidi(int m, float v) {
    
    return  cc[m] + v;
}

void GuiApp::getMidi(){
    
    for(unsigned int i = 0; i < midiMessages.size(); ++i) {
        
        ofxMidiMessage &message = midiMessages[i];
        
        // draw the last recieved message contents to the screen
        //        stringstream text;
        //        text << ofxMidiMessage::getStatusString(message.status);
        //        while(text.str().length() < 16) { // pad status width
        //            text << " ";
        //        }
        
        if(message.status < MIDI_SYSEX) {
            cout << "chan: " << message.channel<< endl;
            if(message.status == MIDI_CONTROL_CHANGE) {
                
                switch(message.control) {
                    case 16:
                        //set knob 1
                        cc[0] = (message.value)/127.0f;
                        //cout <<"value: " << cc[0] << endl;
                        break;
                    case 17:
                        //set knob 2
                        cc[1] = (message.value)/127.0f;
                        break;
                    case 18:
                        //set knob 3
                        cc[2] = (message.value)/127.0f;
                        break;
                    case 19:
                        //set knob 4
                        cc[3] = (message.value)/127.0f;
                        break;
                    case 20:
                        //set knob 5
                        cc[4] = (message.value)/127.0f;
                        break;
                    case 21:
                        //set knob 6
                        cc[5] = (message.value)/127.0f;
                        break;
                    case 22:
                        //set knob 7
                        cc[6] = (message.value)/127.0f;
                        break;
                    case 23:
                        //set knob 8
                        cc[7] = (message.value)/127.0f;
                        break;
                        
                        
                }
                
            }
        }
        
        
    }
    
}


//---------------------------
