//*
// ****  Update 6-10-22 ***

/* ------------ NuWaaaves_0.83.0 -----------------

    From: Jer
 
    I'm calling this one 0.83.0 cause I'm not sure about things being a 1 or not.
    here's some important info you didn't ask for.
   
    tldr; pay people to do what they enjoy.
          I will gladly do the same.
 
    https://www.patreon.com /JerTittle
 
 {
    The original commit was probably 95% lil_waaaves-rqrt-pi by Andreijay(their info is below).
    much has been updated and tried to take care with matching vernacular in VW2.5, but this is me working
    through the code so I can better understand thus ≠ 1:1. This could change, I still kinda only get github.
 
    basically -
 
        - -2 buffer inputs.
                buffers 3 & 4? not in this timeline.
                n? maybe.
        
        - pixelations have been folded into respective window groups.
                Get in those fields my son. 
        
        - -all lfos.
                they are coming but I'm I'd like to have midi done first.
 
        - +TittlerVer0.83.
                This is a titler, for now!
                on canvas, use mouse to place the text draw point .Default is center.
                more instructions in ofApp.cpp!(maybe)
                computer talk aside it' s a t i t t  l e  r .

        - -texMod.
                also co ing but I want to research that a little more.
 
        - +1 ternerary.
                y'all fuck with ternerary operators or what?
       
        - midi is moving to the GuiApp.
                This is part of folding all the modulation into one container. lfo's next.
 
    Overall mindset long term will be modular, generative, and live/play.
}

// ****  Update 6-8-22 ***

oops wrong folder..

mostly just a fix to get directories in order. 

also added in the titler(tittler to u) from last year that I sorta forgot about.



// ****  Update 6-6-22  ***

My quest has gone full circle back to ImGui... 
so now This really is just an update to lil_waaaves_sqrt-pi-
Going to have to do more research on json in OF to get that functional again but it seeems do able.

Going forward:
"Objectifying" the gui modules.
adding a geometry/titler module.

//***********************************************************

ayy y’all this initial commit is a straight up port of Andrei's lil_waaaves but without MIDI or syphon. Also using the ofxGui addon. 
I'm using this as a starting point of working on the gui and modulation side, because starting from VW 2.5 was too much of a head ache.


https://github.com/ex-zee-ex/lil_waaaves_sqrt-PI-


https://www.patreon.com/andrei_jay


Did not fuck with the code too much aside from removing syphon, so everything is a little chunky. 
I did get basic presets implimented. it's in the Gui side if you want to take a look.
Going to progressively move into the newer code.


*//
