#version 120


uniform sampler2DRect ndi;
uniform sampler2DRect cam1;
uniform sampler2DRect tittle;

uniform sampler2DRect fb0;
uniform sampler2DRect fb1;



//variables from gui
uniform int channel1;
uniform int channel2;


//channel1 variablesfrom gui
uniform float channel1hue_x;
uniform float channel1saturation_x;
uniform float channel1bright_x;

uniform int channel1satwrap;
uniform int channel1brightwrap;

uniform int ch1hue_inverttoggle;
uniform int ch1sat_inverttoggle;
uniform int ch1bright_inverttoggle;

uniform float channel1hue_powmap;
uniform float channel1sat_powmap;
uniform float channel1bright_powmap;

//channel2 variablesfrom gui
//mix1 variables
uniform int mix1;
uniform float mix1blend1;
uniform float mix1keybright;
uniform float mix1keythresh;

uniform float channel2hue_x;
uniform float channel2saturation_x;
uniform float channel2bright_x;

uniform int channel2satwrap;
uniform int channel2brightwrap;

uniform int ch2hue_inverttoggle;
uniform int ch2sat_inverttoggle;
uniform int ch2bright_inverttoggle;

uniform float channel2hue_powmap;
uniform float channel2sat_powmap;
uniform float channel2bright_powmap;


uniform int cam1_hflip_switch;
uniform int cam1_vflip_switch;


uniform float ch1_h_mirror;

//vidmixervariables

uniform float cam1_scale;
uniform float tittle_scale;

uniform float width;
uniform float height;



varying vec2 texCoordVarying;






//fbmixvariables

//fb0
uniform float fb0lumakeyvalue;
uniform float fb0lumakeythresh;
uniform int fb0mix;
uniform float fb0blend;

uniform int fb0_hflip_switch;
uniform int fb0_vflip_switch;
uniform int fb0_toroid_switch;

uniform vec3 fb0_hsb_x;
uniform vec3 fb0_hue_x;
uniform vec3 fb0_rescale;
uniform vec3 fb0_modswitch;
uniform float fb0_rotate;

//fb1
uniform float fb1lumakeyvalue;
uniform float fb1lumakeythresh;
uniform int fb1mix;
uniform float fb1blend;

uniform int fb1_hflip_switch;
uniform int fb1_vflip_switch;
uniform int fb1_toroid_switch;

uniform vec3 fb1_hsb_x;
uniform vec3 fb1_hue_x;
uniform vec3 fb1_rescale;
uniform vec3 fb1_modswitch;
uniform float fb1_rotate;







uniform int fb0_pixel_switch;
uniform int fb0_pixel_scale_x;
uniform int fb0_pixel_scale_y;
uniform float fb0_pixel_mix;
uniform float fb0_pixel_brightscale;

uniform int fb1_pixel_switch;
uniform int fb1_pixel_scale_x;
uniform int fb1_pixel_scale_y;
uniform float fb1_pixel_mix;
uniform float fb1_pixel_brightscale;



uniform int cam1_pixel_switch;
uniform int cam1_pixel_scale_x;
uniform int cam1_pixel_scale_y;
uniform float cam1_pixel_mix;
uniform float cam1_pixel_brightscale;

uniform int ndi_pixel_switch;
uniform int ndi_pixel_scale_x;
uniform int ndi_pixel_scale_y;
uniform float ndi_pixel_mix;
uniform float ndi_pixel_brightscale;



uniform float ps;

uniform vec2 cam1dimensions;
uniform vec2 textdimensions;

uniform float pp=1.0;

//just some generice testing varibles
//uniform float qq;
//uniform float ee;




vec3 rgb2hsv(vec3 c ){
    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz),
                 vec4(c.gb, K.xy),
                 step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r),
                 vec4(c.r, p.yzx),
                 step(p.x, c.r));
    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)),
                d / (q.x + e),
                q.x);
}

vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}


vec3 fb_hsbop(vec3 c,vec3 hsbx,vec3 huex,vec3 modswitch,float bright_fold_switch)
{
    
    int sat_fold_switch=0;
    
    c.r=abs(c.r*hsbx.r+huex.z*sin(c.r/3.14));
    c.r=fract(mod(c.r,huex.x)+huex.y);
    c.g=c.g*hsbx.g;
    c.b=c.b*hsbx.b;
    
    
    if(c.g>1.0){
        
        if(sat_fold_switch==1){
            c.g=fract(c.g);
        }
        if(sat_fold_switch==0){
            c.g=1.0;
        }
        
    }
    
    
    if(c.b>1.0){
        if(bright_fold_switch==1){
            if(c.b>1){
                c.b=1.0-fract(c.b);
            }
        }
        if(bright_fold_switch==0){
            c.b=1.0;
        }
        
        
    }//endifcb
    
    
    if(modswitch.r==1.0){ c.r=1.0-c.r;}
    if(modswitch.g==1.0){ c.g=1.0-c.g;}
    if(modswitch.b==1.0){ c.b=1.0-c.b;}
    //do some overflow stuffs
    if(abs(c.x)>1.0){
        
        c.x=fract(c.x);
        c.x=abs(c.x);
    }
    
    
    if(c.y>1.0){c.y=1.0;}
    if(c.z>1.0){c.z=1.0;}
    
    if(c.y<.0){c.y=0.0;}
    if(c.z<.0){c.z=0.0;}


    
    /*
    if(abs(c.y)>1.0){
        // c.y=1.0-abs(c.y);
        c.y=abs(c.y);
        
        c.y=fract(c.y);
        
    }
    
    if(abs(c.z)>1.0){
        //c.z=1.0-abs(c.z);
        c.z=abs(c.z);
        c.z=fract(c.z);
        
    }
    */
    //c.z=1.0-c.z;
    //c.y=1.0-c.y;
    return c;
    
}


//a function for all hsb operations to be invoked by each channel

//change every like hsb thing out there to a vec3 duh
vec3 channel_hsboperations(vec3 c,float hue_x,float sat_x, float bright_x
                           ,float hue_powmap, float sat_powmap, float bright_powmap
                           ,int satwrap,int brightwrap,int hueinvert,int satinvert,int brightinvert)
{
    
    //attenuators
    c.x=c.x*hue_x;
    c.y=c.y*sat_x;
    c.z=c.z*bright_x;
    
    //deal with underflows
    if(c.x<0){
        if(hueinvert==0){ c.x=1.0-abs(c.x);}
        if(hueinvert==1){c.x=abs(1.0-abs(c.x));}
    }
    
    
    if(c.y<0){
        if(satinvert==0){ c.y=1.0-abs(c.y);}
        if(satinvert==1){c.y=abs(1.0-abs(c.y));}
        
    }
    
    
    if(c.z<0){
        if(brightinvert==0){ c.z=1.0-abs(c.z);}
        if(brightinvert==1){c.z=abs(1.0-abs(c.z));}
    }
    
    //and over flows
    if(satwrap==1.0){
        if(abs(c.y)>1.0){
            c.y=fract(c.y);
        }
    }
    
    if(brightwrap==1.0){
        if(abs(c.z)>1.0){
            c.z=fract(c.z);
        }
    }
    
    if(satwrap==0.0){
        if(c.y>1.0){
            c.y=1;
        }
    }
    
    if(brightwrap==0.0){
        if(c.z>1.0){
            c.z=1;
        }
    }
    
    
    
    c.x=fract(c.x);
    
    //powmaps
    //c.x=pow((c.x),hue_powmap);
    c.y=pow((c.y),sat_powmap);
    c.z=pow((c.z),bright_powmap);
    
    
    
    
    
    
    return c;
}

//lets instead rewrite this for rgb modes bc i dont think blend works without rgb
//can just send the brightness value from the earlier hsb version along for the ride to calculate the lumakey thingss

vec4 mix_rgb(vec4 ch1, vec4 ch2, int mixswitch,float blend, float lumavalue, float lumathresh, float bright1){

    vec4 mixout=mix(ch1,ch2,blend);
        
    if((bright1> lumavalue-lumathresh) && (bright1<lumavalue+lumathresh)){
        mixout=ch2;
    }
    
    
    
        
   
    
    //mixout=vec3(mixhue,mixsat,mixbright);
    return mixout;
}//endmixfunction




//pixelatefunction


vec4 pixelate(float x_scale, float y_scale, vec2 coord,sampler2DRect pixelTex,float pixelMixxx,vec4 c,float brightscale){
    vec4 pixel_color=texture2DRect(pixelTex,coord);
    vec2 pixelScaleCoord= coord;
    x_scale=floor(x_scale*((1-brightscale)+(brightscale)*(.33*pixel_color.r+.5*pixel_color.g+.16*pixel_color.b)));
    
    y_scale=floor(y_scale*((1-brightscale)+(brightscale)*(.33*pixel_color.r+.5*pixel_color.g+.16*pixel_color.b)));
    
    pixelScaleCoord.x=coord.x/width;
    pixelScaleCoord.y=coord.y/height;
    
    pixelScaleCoord.x=floor(x_scale*pixelScaleCoord.x)/x_scale;
    pixelScaleCoord.y=floor(y_scale*pixelScaleCoord.y)/y_scale;
    
    pixelScaleCoord.x=width*pixelScaleCoord.x +(width/x_scale)*.5;
    pixelScaleCoord.y=height*pixelScaleCoord.y +(height/y_scale)*.5;
    
    pixel_color=texture2DRect(pixelTex,pixelScaleCoord);
    
    return mix(c,pixel_color,pixelMixxx);
    
}//endpixelatefunction



vec2 rotate(vec2 coord,float theta){
    vec2 center_coord=vec2(coord.x-width/2,coord.y-height/2);
    vec2 rotate_coord=vec2(0,0);
    float spiral=abs(coord.x+coord.y)/2*width;
    coord.x=spiral+coord.x;
    coord.y=spiral+coord.y;
    rotate_coord.x=center_coord.x*cos(theta)-center_coord.y*sin(theta);
    rotate_coord.y=center_coord.x*sin(theta)+center_coord.y*cos(theta);
    
    rotate_coord=rotate_coord+vec2(width/2,height/2);
    
    
    
    return rotate_coord;
    
    
}//endrotate


vec2 wrapCoord(vec2 coord){
    
    if(abs(coord.x)>width){coord.x=abs(width-coord.x);}
    if(abs(coord.y)>height){coord.y=abs(height-coord.y);}
    
    coord.x=mod(coord.x,width);
    coord.y=mod(coord.y,height);
    
   
    
    return coord;
}

vec2 mirrorCoord(vec2 coord){

    //trying out a different kind of wrapping for rotations
    if(coord.x>width){coord.x=width-mod(coord.x,width);}
    if(coord.y>height){coord.y=height-mod(coord.y,height);}
    
    if(coord.x<0){coord.x=abs(coord.x);}
    if(coord.y<0){coord.y=abs(coord.y);}
    
    return coord;
}

void main()
{
    //set up dummy variables for each channel
    vec4 channel1_color=vec4(0.0, 0.0, 0.0, 0.0);
    
    vec4 channel2_color=vec4(0.0, 0.0, 0.0, 0.0);
    
    vec4 ndi_color=texture2DRect(ndi,texCoordVarying);
    
    if(ndi_pixel_switch==1){
        ndi_color=pixelate(ndi_pixel_scale_x,ndi_pixel_scale_y,texCoordVarying,ndi,ndi_pixel_mix,ndi_color,ndi_pixel_brightscale);
    }
    
    
    vec2 cam1_coord=texCoordVarying*cam1_scale;
    
    if(cam1_hflip_switch==1){
        if(texCoordVarying.x>width/2){cam1_coord.x=cam1_scale*abs(width-texCoordVarying.x);}
    }//endifhflip1
    if(cam1_vflip_switch==1){
        if(texCoordVarying.y>height/2){cam1_coord.y=cam1_scale*abs(height-texCoordVarying.y);}
        
    }//endifvflip1
    
    vec4 cam1color=vec4(0.0,0.0,0.0,0.0);
    
    if(texCoordVarying.x*cam1_scale<cam1dimensions.x){
        if(texCoordVarying.y*cam1_scale<cam1dimensions.y){
            cam1color=texture2DRect(cam1,vec2(cam1_coord.x,cam1_coord.y));
        }
    }
    
    if(cam1_pixel_switch==1){
        
        cam1color=pixelate(cam1_pixel_scale_x,cam1_pixel_scale_y,cam1_coord,cam1,cam1_pixel_mix,cam1color,cam1_pixel_brightscale);
    }
    
    

     vec2 tittle_coord=texCoordVarying*tittle_scale;


     vec4 tittle_color=vec4(0.0,0.0,0.0,0.0);
       
    //   vec4 tittle_color=texture2DRect(tittle,texCoordVarying);

       if(texCoordVarying.x*tittle_scale<textdimensions.x){
           if(texCoordVarying.y*tittle_scale<textdimensions.y){
               tittle_color=texture2DRect(tittle,vec2(tittle_coord.x,tittle_coord.y));
           }
       }

    
    
    //select which input for channel1
    
    
    
    if(channel1==1){
        channel1_color=cam1color;
        
    }//endifch1_1
    
    if(channel1==2){
        channel1_color=ndi_color;
        
    }//endifch1_2
    
    if(channel1==3){
        channel1_color=tittle_color;
        
    }//endifch1_3
    
    if(channel2==1){
           channel2_color=cam1color;
           
       }//endifch2_1
       
       if(channel2==2){
           channel2_color=ndi_color;
           
       }//endifch2_2
       
       if(channel2==3){
           channel2_color=tittle_color;
           
       }//endifch2_3
    
   

    
    vec3 channel1color_hsb=rgb2hsv(vec3(channel1_color.r,channel1_color.g,channel1_color.b));
    vec3 channel2color_hsb=rgb2hsv(vec3(channel2_color.r,channel2_color.g,channel2_color.b));

    vec3 ch1_hsbstrip=channel_hsboperations(channel1color_hsb, channel1hue_x, channel1saturation_x, channel1bright_x
                                            
                                            ,channel1hue_powmap,channel1sat_powmap,channel1bright_powmap
                                            ,channel1satwrap,channel1brightwrap,
                                            ch1hue_inverttoggle,ch1sat_inverttoggle,ch1bright_inverttoggle);
    
    vec3 ch2_hsbstrip=channel_hsboperations(channel2color_hsb, channel2hue_x, channel2saturation_x, channel2bright_x
                                               
                                               ,channel2hue_powmap,channel2sat_powmap,channel2bright_powmap
                                               ,channel2satwrap,channel2brightwrap,
                                               ch2hue_inverttoggle,ch2sat_inverttoggle,ch2bright_inverttoggle);
    
    //so will want to do something similar here where there is a dif set of coordinates
    //for each of the framebuffers then each one can be seperatly remapped
    //1 variable for zoome in and out (multiplier plus modulo for wraparound
    //1 variable each for x and y shift
    //can rotations work in here?  try and research this a second
    
    
    //vec2 fb0_coord=fb0_rescale.z*texCoordVarying;
    
    //center should be a variable sent that displaces where yr center is wished to be
    vec2 center=vec2(width/2,height/2);
    
    
    //try some flips
    
    
    vec2 fb0_coord=vec2(texCoordVarying.x-center.x,texCoordVarying.y-center.y);
    fb0_coord=fb0_coord* fb0_rescale.z;
    fb0_coord.xy=fb0_rescale.xy+fb0_coord.xy;
    fb0_coord.x=fb0_coord.x+center.x;
    fb0_coord.y=fb0_coord.y+center.y;
    
    //fb0_coord=1024-fb0_coord;
    fb0_coord=rotate(fb0_coord,fb0_rotate);
    
    if(fb0_toroid_switch==1){
        fb0_coord=wrapCoord(fb0_coord);
    }
    if(fb0_toroid_switch==2){
           fb0_coord=mirrorCoord(fb0_coord);
       }
    
    //try a smoother flip
    //this is much better there is less spazzing out
    
    if(fb0_hflip_switch==1){
        if(fb0_coord.x>width/2){fb0_coord.x=abs(width-fb0_coord.x);}
    }//endifhflip1
    if(fb0_vflip_switch==1){
        if(fb0_coord.y>height/2){fb0_coord.y=abs(height-fb0_coord.y);}
    }//endifvflip1
    //vec4 fb0_color = texture2DRect(fb0,fb0_coord);
    
    vec4 fb0_color = texture2DRect(fb0,fb0_coord);
    
    if(abs(fb0_coord.x-width/2)>=width/2||abs(fb0_coord.y-height/2)>=height/2){
        fb0_color=vec4(0,0,0,1.0);
    }
    ///testing the pixelation function
    //0 mix value is pure pixel
    //1 mix value is bypass
    //smaller values for pixel size make larger pixels
    //the way to calculate the actual pixel size is width/index
    if(fb0_pixel_switch==1){
        //fb0_color=pixelate(64,fb0_coord,fb0,.25,fb0_color,.5);
        // fb1_color=pixelate(fb1_pixel_scale,fb1_coord,fb1,fb1_pixel_mix,fb1_color,fb1_pixel_brightscale);
        fb0_color=pixelate( fb0_pixel_scale_x, fb0_pixel_scale_y,fb0_coord,fb0,fb0_pixel_mix,fb0_color,fb0_pixel_brightscale);
    }
    
    
    
    //original flavor
    
    vec2 fb1_coord=vec2(texCoordVarying.x-center.x,texCoordVarying.y-center.y);
     fb1_coord=fb1_coord* fb1_rescale.z;
     fb1_coord.xy=fb1_rescale.xy+fb1_coord.xy;
     fb1_coord.x=fb1_coord.x+center.x;
     fb1_coord.y=fb1_coord.y+center.y;
    
    
    fb1_coord=rotate(fb1_coord,fb1_rotate);
    
    if(fb1_toroid_switch==1){
        fb1_coord=wrapCoord(fb1_coord);
    }
    if(fb1_toroid_switch==2){
           fb1_coord=mirrorCoord(fb1_coord);
       }
    
    
    if(fb1_hflip_switch==1){
        if(fb1_coord.x>width/2){fb1_coord.x=abs(width-fb1_coord.x);}
    }//endifhflip1
    if(fb1_vflip_switch==1){
        if(fb1_coord.y>height/2){fb1_coord.y=abs(height-fb1_coord.y);}
    }//endifvflip1
    
    
    vec4 fb1_color=texture2DRect(fb1,fb1_coord);
    
    if(abs(fb1_coord.x-width/2)>=width/2||abs(fb1_coord.y-height/2)>=height/2){
        fb1_color=vec4(0,0,0,255);
    }
    
    
    if(fb1_pixel_switch==1){
        //fb0_color=pixelate(64,fb0_coord,fb0,.25,fb0_color,.5);
        // fb1_color=pixelate(fb1_pixel_scale,fb1_coord,fb1,fb1_pixel_mix,fb1_color,fb1_pixel_brightscale);
        fb1_color=pixelate( fb1_pixel_scale_x, fb1_pixel_scale_y,fb1_coord,fb1,fb1_pixel_mix,fb1_color,fb1_pixel_brightscale);
    }
    
    //cam1color=pixelate(cam1_pixel_scale_x,cam1_pixel_scale_y,cam1_coord,cam1,cam1_pixel_mix,cam1color,cam1_pixel_brightscale)
    
    
    
    
    
    
    
    
    
    
    
    
    // vec4 syphon_color=texture2DRect(syphon,texCoordVarying);
    
    
    
    
    
    //just like  spare dummy variabl for a color vector
    vec4 color = vec4(0.0, 0.0, 0.0, 0.0);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //convert to hsb and make some variables for easy readin
    
   // vec3 channel1color_hsb=rgb2hsv(vec3(channel1_color.r,channel1_color.g,channel1_color.b));
    
    
    vec3 fb0color_hsb=rgb2hsv(vec3(fb0_color.r,fb0_color.g,fb0_color.b));
    vec3 fb1color_hsb=rgb2hsv(vec3(fb1_color.r,fb1_color.g,fb1_color.b));
    
  
    fb0color_hsb=fb_hsbop(fb0color_hsb,
                          fb0_hsb_x,
                          fb0_hue_x,fb0_modswitch,0);
    
    fb1color_hsb=fb_hsbop(fb1color_hsb,
                          fb1_hsb_x,
                          fb1_hue_x,fb1_modswitch,0);
    
    
    vec3 channel1_rgb=vec3(hsv2rgb(ch1_hsbstrip));
    vec3 channel2_rgb=vec3(hsv2rgb(ch2_hsbstrip));
    
      //switch on and off alpha in here... and test a lot more
      channel1_color=vec4(vec3(hsv2rgb(ch1_hsbstrip)),1.0);
    channel2_color=vec4(vec3(hsv2rgb(ch2_hsbstrip)),1.0);
    fb0_color=vec4(vec3(hsv2rgb(fb0color_hsb)),1.0);
      fb1_color=vec4(vec3(hsv2rgb(fb1color_hsb)),1.0);
    
    
    //next we do the mixxxing
    
    
    
    vec4 mixout_color=mix_rgb(channel1_color,channel2_color,mix1,mix1blend1,mix1keybright,mix1keythresh,ch1_hsbstrip.z);
     
     vec3 mixout_colorhsb=vec3(rgb2hsv(vec3(mixout_color.x,mixout_color.y,mixout_color.z)));

     //fb0
     mixout_color=mix_rgb(mixout_color,fb0_color,fb0mix,fb0blend,
                          fb0lumakeyvalue,
                          fb0lumakeythresh,
                          mixout_colorhsb.z);
     
     mixout_colorhsb=vec3(rgb2hsv(vec3(mixout_color.x,mixout_color.y,mixout_color.z)));
    
     //fb1
     mixout_color=mix_rgb(mixout_color,fb1_color,fb1mix,fb1blend,
                          fb1lumakeyvalue,
                          fb1lumakeythresh,
                          mixout_colorhsb.z);
    
     mixout_colorhsb=vec3(rgb2hsv(vec3(mixout_color.x,mixout_color.y,mixout_color.z)));
    
    
    
    
    
    
    
    
    
    
    
    
    gl_FragColor = mixout_color;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}
