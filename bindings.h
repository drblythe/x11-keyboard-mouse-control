#ifndef BINDINGS_H
#define BINDINGS_H
#include <stdio.h>
#include <ncurses.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <X11/extensions/XTest.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Default mouse "speed"
#define DEFAULT_SENSITIVITY 25
// Left mouse button...
#define LMB 1 
#define MMB 2
#define RMB 3
// Keypad keys bound to mouse movement
#define K_UP 72 
#define K_DOWN 80
#define K_RIGHT 77
#define K_LEFT 75
// Keypad keys bound to mouse click
#define K_LCLICK 82 
#define K_MCLICK 76
#define K_RCLICK 96

/*
struct input_event {
        struct timeval time;
        __u16 type;
        __u16 code;
        __s32 value;
};
*/
#endif
