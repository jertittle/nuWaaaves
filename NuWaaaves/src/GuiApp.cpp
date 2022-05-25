//
//  GuiApp.cpp
//  NuWaaaves
//
//  Created by Mac User on 5/24/22.
//

#include "GuiApp.h"

int fbob = 60;

void GuiApp::setup(){
    
   
   
   
    
    ofBackground(0);
    inputs.setup( "input Channel", "inputSettings.json" );
  
    inputs.setPosition(20, 20);
    channel1Group.setup("channel 1");
    channel1Group.add( channel1.setup("channel select",0,0,1));
    channel1Group.add( channel1hue.setup("hue", 1.0,-5.0,5.0));
    channel1Group.add( channel1saturation.setup("saturation", 1.0,-5.0,5.0));
    channel1Group.add( channel1bright.setup("bright", 1.0,-5.0,5.0));
    channel1Group.add( channel1satwrap.setup("saturation wrapping", false));
    channel1Group.add( channel1brightwrap.setup("bright wrapping", false));
    channel1Group.add( ch1hue_powmaptoggle.setup("hue pow", false));
    channel1Group.add( ch1sat_powmaptoggle.setup("saturation pow", false));
    channel1Group.add( ch1bright_powmaptoggle.setup("bright pow", false));
    channel1Group.add( channel1brightpowmap.setup("bright powmap", 1.0,-5.0,5.0));
    channel1Group.add( channel1huepowmap.setup("hue powmap", 1.0,-5.0,5.0));
    channel1Group.add( channel1saturationpowmap.setup("saturation powmap", 1.0,-5.0,5.0));
    
    
    inputs.add( &channel1Group );
    inputs.minimizeAll();
    
    buffers.setup( "Buffers", "buffers.json" );
    
    //fb0
    buffers.setPosition(300,20);
    framebuffer0Group.setup( "buffer 0" );
    framebuffer0Group.add( FB0mix.setup("blend mode(none-mix-key)",0,0,2));
    framebuffer0Group.add( fb0blend.setup("blend amount", 0.0, -2.0, 2.0));
    framebuffer0Group.add( fb0lumakeyvalue.setup("luma key value", 0.0, 0.0, 1.0));
    framebuffer0Group.add( fb0lumakeythresh.setup("luma key thresh", 0.0, 0.0, 1.0));
    framebuffer0Group.add( fb0delayamnt.setup("delay amount", 0,0,fbob-1));
    framebuffer0Group.add( fb0_hue.setup("hue", 10.0, -20.0, 20.0));
    framebuffer0Group.add( fb0_saturation.setup("saturation", 10.0, -20.0, 20.0));
    framebuffer0Group.add( fb0_bright.setup("bright", 10.0, -20.0, 20.0));
    framebuffer0Group.add( fb0_hue_invert.setup("hue invert",false));
    framebuffer0Group.add( fb0_saturation_invert.setup("saturation invert",false));
    framebuffer0Group.add( fb0_bright_invert.setup("bright invert",false));
    framebuffer0Group.add( fb0_vflip_switch.setup("V invert",false));
    framebuffer0Group.add( fb0_hflip_switch.setup("H invert",false));
    framebuffer0Group.add( fb0_toroid_switch.setup("toroid switch",false));
    framebuffer0Group.add( fb0_huex_mod.setup("hueX mod",0.0,0.0,20.0));
    framebuffer0Group.add( fb0_huex_offset.setup("hueX offset",0.0,-20.0,20.0));
    framebuffer0Group.add( fb0_huex_lfo.setup("hueX lfo",0.0,-20.0,20.0));
    framebuffer0Group.add( fb0_x_displace.setup("x displace", 0.0, -100.0, 100.0));
    framebuffer0Group.add( fb0_y_displace.setup("y displace", 0.0, -100.0, 100.0));
    framebuffer0Group.add( fb0_z_displace.setup("z displace", 100.0, 90.0, 110.0));
    framebuffer0Group.add( fb0_rotate.setup("rotate",0.0, -157.0, 157.0));
    
    buffers.add( &framebuffer0Group);
    //fb1
    framebuffer1Group.setup( "buffer 1" );
    framebuffer1Group.add( FB1mix.setup("blend mode(none-mix-key)",0,0,2));
    framebuffer1Group.add( fb1blend.setup("blend amount", 0.0, -2.0, 2.0));
    framebuffer1Group.add( fb1lumakeyvalue.setup("luma key value", 0.0, 0.0, 1.0));
    framebuffer1Group.add( fb1lumakeythresh.setup("luma key thresh", 0.0, 0.0, 1.0));
    framebuffer1Group.add( fb1delayamnt.setup("delay amount", 0,0,fbob-1));
    framebuffer1Group.add( fb1_hue.setup("hue", 10.0, -20.0, 20.0));
    framebuffer1Group.add( fb1_saturation.setup("saturation", 10.0, -20.0, 20.0));
    framebuffer1Group.add( fb1_bright.setup("bright", 10.0, -20.0, 20.0));
    framebuffer1Group.add( fb1_hue_invert.setup("hue invert",false));
    framebuffer1Group.add( fb1_saturation_invert.setup("saturation invert",false));
    framebuffer1Group.add( fb1_bright_invert.setup("bright invert",false));
    framebuffer1Group.add( fb1_vflip_switch.setup("V invert",false));
    framebuffer1Group.add( fb1_hflip_switch.setup("H invert",false));
    framebuffer1Group.add( fb1_toroid_switch.setup("toroid switch",false));
    framebuffer1Group.add( fb1_huex_mod.setup("hueX mod",0.0,0.0,20.0));
    framebuffer1Group.add( fb1_huex_offset.setup("hueX offset",0.0,-20.0,20.0));
    framebuffer1Group.add( fb1_huex_lfo.setup("hueX lfo",0.0,-20.0,20.0));
    framebuffer1Group.add( fb1_x_displace.setup("x displace", 0.0, -100.0, 100.0));
    framebuffer1Group.add( fb1_y_displace.setup("y displace", 0.0, -100.0, 100.0));
    framebuffer1Group.add( fb1_z_displace.setup("z displace", 100.0, 90.0, 110.0));
    framebuffer1Group.add( fb1_rotate.setup("rotate",0.0, -157.0, 157.0));
    
    
    buffers.add( &framebuffer1Group);
    
    buffers.minimizeAll();
    //------------------------------------
    pixelations.setup("pixelations", "pixelizations.json" );
    pixelations.setPosition(20, 320);
    pixcamgroup.setup("cam pix");
    pixcamgroup.add( cam1_pixel_switch.setup("pixelate", false));
    pixcamgroup.add( cam1_pixel_scale.setup("scale", 64, 0, 128));
    pixcamgroup.add( cam1_pixel_mix.setup("mix", 1.0,-2.0,2.0));
    pixcamgroup.add( cam1_pixel_brightscale.setup("bright scale", 0.0, 0.0, 5.0));
    
    pixelations.add( &pixcamgroup);
    //------------------------------------
    pixbuffergroup.setup("buffer pix");
    pixbuffergroup.add( fb0_pixel_switch.setup("pixelate", false));
    pixbuffergroup.add( fb0_pixel_scale.setup("scale", 64, 0, 128));
    pixbuffergroup.add( fb0_pixel_mix.setup("mix", 1.0,-2.0,2.0));
    pixbuffergroup.add( fb0_pixel_brightscale.setup("bright scale", 0.0, 0.0, 5.0));
    
    pixbuffergroup.add( fb1_pixel_switch.setup("pixelate", false));
    pixbuffergroup.add( fb1_pixel_scale.setup("scale", 64, 0, 128));
    pixbuffergroup.add( fb1_pixel_mix.setup("mix", 1.0,-2.0,2.0));
    pixbuffergroup.add( fb1_pixel_brightscale.setup("bright scale", 0.0, 0.0, 5.0));
    
    
    pixelations.add( &pixbuffergroup);
    pixelations.minimizeAll();
    
    //------------------------------------
    globals.setup("globals","globals.json" );
    globals.setPosition(20, 660);
    globalgroup.setup(("global settings"));
    globalgroup.add( blur_amount.setup("blur amp", 0.0, 0.0, 5.0));
    globalgroup.add( sharpen_amount.setup("sharpen amp", 0.0, 0.0, .3));
    globalgroup.add( x_skew.setup("skew x", 0.0, -3.14/8, 3.14/8));
    globalgroup.add( y_skew.setup("skew y", 0.0, -3.14/8, 3.14/8));
    globalgroup.add( cam1_vflip_switch.setup("cam1 V flip", false));
    globalgroup.add( cam1_hflip_switch.setup("cam1 H flip", false));
    globalgroup.add( cam1_scale.setup("cam1 scale", 1.0, 0.0, 2.0));
    
    
    globals.add( &globalgroup);
    globals.minimizeAll();
}
//----------------------------------
void GuiApp::update() {
    
}


//------------------------------
void GuiApp::draw() {
    inputs.draw();
    buffers.draw();
    pixelations.draw();
    globals.draw();
    
}

void GuiApp::keyPressed(int key) {
    if ( key == '+') {//--------------------------------------------SAVE SETTINGS
          
          ofFileDialogResult res;
          
          res = ofSystemSaveDialog("inputs.json", "Saving input Preset");
          
          if ( res.bSuccess ) inputs.saveToFile( res.filePath );
          
          res = ofSystemSaveDialog("buffers.json", "Saving buffer Preset");
          
          if ( res.bSuccess ) buffers.saveToFile( res.filePath );
          
          res = ofSystemSaveDialog("pixelizations.json", "Saving pixelate Preset");
          
          if ( res.bSuccess ) pixelations.saveToFile( res.filePath );
          
          res = ofSystemSaveDialog("globals.json", "Saving globals Preset");
          
          if ( res.bSuccess ) globals.saveToFile( res.filePath );
          
      }
      
      if(key == '-') {
      //--------------------------------------------LOAD SETTINGS
          
          
          
          inputs.loadFromFile( "inputs.json" );
          buffers.loadFromFile( "buffers.json" );
          pixelations.loadFromFile( "pixelizations.json" );
          globals.loadFromFile( "globals.json" );
          
      }
}


//---------------------------
