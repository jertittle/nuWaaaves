#version 120


uniform sampler2DRect tex0;

varying vec2 texCoordVarying;

uniform float sharpen_amount;
uniform float sharpen_boost;
uniform float sharpen_radius;


vec3 rgb2hsb(vec3 c)
{
    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz), vec4(c.gb, K.xy), step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r), vec4(c.r, p.yzx), step(p.x, c.r));
    
    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)), d / (q.x + e), q.x);
}

vec3 hsb2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

void main()
{
    vec4 color_sharpen=vec4(0.0,0.0,0.0,1.0);
    
    
    float sharpen_radius_mod=sharpen_radius;
    
    float color_sharpen_bright=0.0;
       
     color_sharpen_bright=
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(sharpen_radius_mod,0)).rgb).z+
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(-sharpen_radius_mod,0)).rgb).z+
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(0,sharpen_radius_mod)).rgb).z+
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(0,-sharpen_radius_mod)).rgb).z+
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(sharpen_radius_mod,sharpen_radius_mod)).rgb).z+
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(-sharpen_radius_mod,sharpen_radius_mod)).rgb).z+
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(sharpen_radius_mod,-sharpen_radius_mod)).rgb).z+
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(-sharpen_radius_mod,-sharpen_radius_mod)).rgb).z;
    
    color_sharpen_bright=color_sharpen_bright/8.0;
    
    vec4 original_color=texture2DRect(tex0,texCoordVarying);
    vec3 original_color_hsb=rgb2hsb(original_color.rgb);
    original_color_hsb.z-=(sharpen_amount)*color_sharpen_bright;
    
    
    //old school manual boost method
    //original_color_hsb.z*=(1.0+sharpen_boost+texmod_sharpen_boost*texmod_bright);
    
    //try baking in the boost into the amount
    //this does not work so well over here lol
    if(sharpen_amount>0){
        original_color_hsb.z*=(1.0+sharpen_amount+sharpen_boost);
    }
    
    
    color_sharpen=vec4(hsb2rgb(original_color_hsb),1.0);
    
    
    
     gl_FragColor =color_sharpen;
}
