//
//  GuiApp.cpp
//  NuWaaaves
//
//  Created by Mac User on 5/24/22.
//

#include "GuiApp.h"

int fbob = 60;

void GuiApp::setup(){
    
   
   
   //ofxGuiFloatSlider
    
    ofBackground(0);
   //inputs = gui.addPanel( "input Channel", "inputSettings.json" );
    inputs = gui.addPanel( "input Channel");
                         
    inputs->setPosition(20, 20);
    channel1Group = inputs->addGroup("channel 1");
    channel1Group->add<ofxGuiIntSlider>( channel1.set("channel select",0,0,1));
    channel1Group->add<ofxGuiFloatSlider>( channel1hue.set("hue", 1.0,-5.0,5.0));
    channel1Group->add<ofxGuiFloatSlider>( channel1saturation.set("saturation", 1.0,-5.0,5.0));
    channel1Group->add<ofxGuiFloatSlider>( channel1bright.set("bright", 1.0,-5.0,5.0));
    channel1Group->add<ofxGuiToggle>( channel1satwrap.set("saturation wrapping", false));
    channel1Group->add<ofxGuiToggle>( channel1brightwrap.set("bright wrapping", false));
    channel1Group->add<ofxGuiToggle>( ch1hue_powmaptoggle.set("hue pow", false));
    channel1Group->add<ofxGuiToggle>( ch1sat_powmaptoggle.set("saturation pow", false));
    channel1Group->add<ofxGuiToggle>( ch1bright_powmaptoggle.set("bright pow", false));
    channel1Group->add<ofxGuiFloatSlider>( channel1brightpowmap.set("bright powmap", 1.0,-5.0,5.0));
    channel1Group->add<ofxGuiFloatSlider>( channel1huepowmap.set("hue powmap", 1.0,-5.0,5.0));
    channel1Group->add<ofxGuiFloatSlider>( channel1saturationpowmap.set("saturation powmap", 1.0,-5.0,5.0));
    
    
   // inputs.add( &channel1Group );
   // inputs.minimizeAll();
    
   // buffers = gui.addPanel(  "Buffers", "buffers.json" );
    buffers = gui.addPanel(  "Buffers");
    
    //fb0
    buffers->setPosition(300,20);
    
    framebuffer0Group = buffers->addGroup( "buffer 0" );
    framebuffer0Group->add<ofxGuiIntSlider>( FB0mix.set("blend mode(none-mix-key)",0,0,2));
    framebuffer0Group->add<ofxGuiFloatSlider>( fb0blend.set("blend amount", 0.0, -2.0, 2.0));
    framebuffer0Group->add<ofxGuiFloatSlider>( fb0lumakeyvalue.set("luma key value", 0.0, 0.0, 1.0));
    framebuffer0Group->add<ofxGuiFloatSlider>( fb0lumakeythresh.set("luma key thresh", 0.0, 0.0, 1.0));
    framebuffer0Group->add<ofxGuiIntSlider>( fb0delayamnt.set("delay amount", 0,0,fbob-1));
    framebuffer0Group->add<ofxGuiFloatSlider>( fb0_hue.set("hue", 10.0, -20.0, 20.0));
    framebuffer0Group->add<ofxGuiFloatSlider>( fb0_saturation.set("saturation", 10.0, -20.0, 20.0));
    framebuffer0Group->add<ofxGuiFloatSlider>( fb0_bright.set("bright", 10.0, -20.0, 20.0));
    framebuffer0Group->add<ofxGuiToggle>( fb0_hue_invert.set("hue invert",false));
    framebuffer0Group->add<ofxGuiToggle>( fb0_saturation_invert.set("saturation invert",false));
    framebuffer0Group->add<ofxGuiToggle>( fb0_bright_invert.set("bright invert",false));
    framebuffer0Group->add<ofxGuiToggle>( fb0_vflip_switch.set("V invert",false));
    framebuffer0Group->add<ofxGuiToggle>(fb0_hflip_switch.set("H invert",false));
    framebuffer0Group->add<ofxGuiToggle>( fb0_toroid_switch.set("toroid switch",false));
    framebuffer0Group->add<ofxGuiFloatSlider>( fb0_huex_mod.set("hueX mod",0.0,0.0,20.0));
    framebuffer0Group->add<ofxGuiFloatSlider>( fb0_huex_offset.set("hueX offset",0.0,-20.0,20.0));
    framebuffer0Group->add<ofxGuiFloatSlider>( fb0_huex_lfo.set("hueX lfo",0.0,-20.0,20.0));
    framebuffer0Group->add<ofxGuiFloatSlider>( fb0_x_displace.set("x displace", 0.0, -100.0, 100.0));
    framebuffer0Group->add<ofxGuiFloatSlider>( fb0_y_displace.set("y displace", 0.0, -100.0, 100.0));
    framebuffer0Group->add<ofxGuiFloatSlider>( fb0_z_displace.set("z displace", 100.0, 90.0, 110.0));
    framebuffer0Group->add<ofxGuiFloatSlider>( fb0_rotate.set("rotate",0.0, -157.0, 157.0));
    
   // buffers.add( &framebuffer0Group);
    //fb1
    framebuffer1Group = buffers->addGroup( "buffer 1" );
    framebuffer1Group->add<ofxGuiIntSlider>( FB1mix.set("blend mode(none-mix-key)",0,0,2));
    framebuffer1Group->add<ofxGuiFloatSlider>( fb1blend.set("blend amount", 0.0, -2.0, 2.0));
    framebuffer1Group->add<ofxGuiFloatSlider>( fb1lumakeyvalue.set("luma key value", 0.0, 0.0, 1.0));
    framebuffer1Group->add<ofxGuiFloatSlider>( fb1lumakeythresh.set("luma key thresh", 0.0, 0.0, 1.0));
    framebuffer1Group->add<ofxGuiIntSlider>( fb1delayamnt.set("delay amount", 0,0,fbob-1));
    framebuffer1Group->add<ofxGuiFloatSlider>( fb1_hue.set("hue", 10.0, -20.0, 20.0));
    framebuffer1Group->add<ofxGuiFloatSlider>( fb1_saturation.set("saturation", 10.0, -20.0, 20.0));
    framebuffer1Group->add<ofxGuiFloatSlider>( fb1_bright.set("bright", 10.0, -20.0, 20.0));
    framebuffer1Group->add<ofxGuiToggle>( fb1_hue_invert.set("hue invert",false));
    framebuffer1Group->add<ofxGuiToggle>( fb1_saturation_invert.set("saturation invert",false));
    framebuffer1Group->add<ofxGuiToggle>( fb1_bright_invert.set("bright invert",false));
    framebuffer1Group->add<ofxGuiToggle>( fb1_vflip_switch.set("V invert",false));
    framebuffer1Group->add<ofxGuiToggle>( fb1_hflip_switch.set("H invert",false));
    framebuffer1Group->add<ofxGuiToggle>( fb1_toroid_switch.set("toroid switch",false));
    framebuffer1Group->add<ofxGuiFloatSlider>( fb1_huex_mod.set("hueX mod",0.0,0.0,20.0));
    framebuffer1Group->add<ofxGuiFloatSlider>( fb1_huex_offset.set("hueX offset",0.0,-20.0,20.0));
    framebuffer1Group->add<ofxGuiFloatSlider>( fb1_huex_lfo.set("hueX lfo",0.0,-20.0,20.0));
    framebuffer1Group->add<ofxGuiFloatSlider>( fb1_x_displace.set("x displace", 0.0, -100.0, 100.0));
    framebuffer1Group->add<ofxGuiFloatSlider>( fb1_y_displace.set("y displace", 0.0, -100.0, 100.0));
    framebuffer1Group->add<ofxGuiFloatSlider>( fb1_z_displace.set("z displace", 100.0, 90.0, 110.0));
    framebuffer1Group->add<ofxGuiFloatSlider>( fb1_rotate.set("rotate",0.0, -157.0, 157.0));
    
    
   // buffers.add( &framebuffer1Group);
    
    //buffers.minimizeAll();
    //------------------------------------
   //pixelations = gui.addPanel("pixelations", "pixelizations.json" );
    pixelations = gui.addPanel("pixelations");
    pixelations->setPosition(20, 320);
    
    pixcamgroup = pixelations->addGroup("cam pix");
    pixcamgroup->add<ofxGuiToggle>( cam1_pixel_switch.set("pixelate", false));
    pixcamgroup->add<ofxGuiIntSlider>( cam1_pixel_scale.set("scale", 64, 0, 128));
    pixcamgroup->add<ofxGuiFloatSlider>( cam1_pixel_mix.set("mix", 1.0,-2.0,2.0));
    pixcamgroup->add<ofxGuiFloatSlider>( cam1_pixel_brightscale.set("bright scale", 0.0, 0.0, 5.0));
    
    //pixelations.add( &pixcamgroup);
    //------------------------------------
    pixbuffergroup = pixelations->addGroup("buffer pix");
    pixbuffergroup->add<ofxGuiToggle>( fb0_pixel_switch.set("pixelate", false));
    pixbuffergroup->add<ofxGuiIntSlider>( fb0_pixel_scale.set("scale", 64, 0, 128));
    pixbuffergroup->add<ofxGuiFloatSlider>( fb0_pixel_mix.set("mix", 1.0,-2.0,2.0));
    pixbuffergroup->add<ofxGuiFloatSlider>( fb0_pixel_brightscale.set("bright scale", 0.0, 0.0, 5.0));
    
    pixbuffergroup->add<ofxGuiToggle>( fb1_pixel_switch.set("pixelate", false));
    pixbuffergroup->add<ofxGuiIntSlider>( fb1_pixel_scale.set("scale", 64, 0, 128));
    pixbuffergroup->add<ofxGuiFloatSlider>( fb1_pixel_mix.set("mix", 1.0,-2.0,2.0));
    pixbuffergroup->add<ofxGuiFloatSlider>( fb1_pixel_brightscale.set("bright scale", 0.0, 0.0, 5.0));
    
    
    //pixelations.add( &pixbuffergroup);
    //pixelations.minimizeAll();
    
    //------------------------------------
   // globals = gui.addPanel("globals","globals.json" );
    globals = gui.addPanel("globals");
    
    globals->setPosition(20, 660);
    globalgroup = globals->addGroup("global settings");
    globalgroup->add<ofxGuiFloatSlider>( blur_amount.set("blur amp", 0.0, 0.0, 5.0));
    globalgroup->add<ofxGuiFloatSlider>( sharpen_amount.set("sharpen amp", 0.0, 0.0, .3));
    globalgroup->add<ofxGuiFloatSlider>( x_skew.set("skew x", 0.0, -3.14/8, 3.14/8));
    globalgroup->add<ofxGuiFloatSlider>( y_skew.set("skew y", 0.0, -3.14/8, 3.14/8));
    globalgroup->add<ofxGuiToggle>( cam1_vflip_switch.set("cam1 V flip", false));
    globalgroup->add<ofxGuiToggle>( cam1_hflip_switch.set("cam1 H flip", false));
    globalgroup->add<ofxGuiFloatSlider>( cam1_scale.set("cam1 scale", 1.0, 0.0, 2.0));
    
    
   // globals.add( &globalgroup);
    //globals.minimizeAll();
}
//----------------------------------
void GuiApp::update() {
    
}


//------------------------------
void GuiApp::draw() {
//    inputs.draw();
//    buffers.draw();
//    pixelations.draw();
//    globals.draw();
    
}

void GuiApp::keyPressed(int key) {

    if ( key == '+') {//--------------------------------------------SAVE SETTINGS

          ofFileDialogResult res;

          res = ofSystemSaveDialog("inputs.json", "Saving input Preset");

          if ( res.bSuccess ) inputs->saveToFile( res.filePath );

          res = ofSystemSaveDialog("buffers.json", "Saving buffer Preset");

          if ( res.bSuccess ) buffers->saveToFile( res.filePath );

          res = ofSystemSaveDialog("pixelizations.json", "Saving pixelate Preset");

          if ( res.bSuccess ) pixelations->saveToFile( res.filePath );

          res = ofSystemSaveDialog("globals.json", "Saving globals Preset");

          if ( res.bSuccess ) globals->saveToFile( res.filePath );

      }

      if(key == '-') {
      //--------------------------------------------LOAD SETTINGS



          inputs->loadFromFile( "inputs.json" );
          buffers->loadFromFile( "buffers.json" );
          pixelations->loadFromFile( "pixelizations.json" );
          globals->loadFromFile( "globals.json" );

      }
}


//---------------------------
