# x11-keyboard-mouse-control
Control mouse with keyboard/numpad on X windowing system  
This was done for a full sized keyboard with a number pad.  
I'm not sure if the keycodes from /dev will be the same for every keyboard, but you can change the bindings in bindings.h.  
This reads input directly from /dev, uses X11 library to move mouse cursor, simulates key click events with XTest library.  

## Dependencies  
    libx11-dev  
    libxtst-dev  
Compile:  

    gcc -lX11 -lXtst xkbmouse.c -o xkbmouse

## Usage  
Have to run with sudo (it reads directly from /dev/input/eventX)  
Have to also figure out which input event is your keyboard. Easy way is to "sudo cat /dev/input/event<number>" and mash your keyboard until strange hieroglyphics appear lol.  
Then run :  
    
    sudo /path/to/executable /dev/input/event<number-for-keyboard>  
You can run it in the background so it isn't tied to a terminal  

## Key bindings
NumLock does not matter, as input is read directly from keyboard.  
Numpad keys:  
8 = up  
2 = down  
4 = left  
6 = right  
0 = left click  
5 = middle click  
Enter = right click  
1, 3, 7, 9 keys move mouse in their respective diagonal direction  

## TODO
Add click and drag

## Bugs
There is <del>a rare</del> an uncommon problem where the mouse moves very slowly, pressing/toggling NumLock key fixes it. Not sure what the issue is
