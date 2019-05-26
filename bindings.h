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
#include <errno.h>

// Default mouse "speed"
#define DEFAULT_SENSITIVITY 10
//static const int DEFAULT_SENSITIVITY = 10;
// Toggle the program on and off
#define ON 	1
#define OFF 0
//static const int ON = 1;
//static const int OFF = 0;
// Left mouse button...
#define LMB 1 
#define MMB 2
#define RMB 3
//static const int LMB = 1;
//static const int MMB= 2;
//static const int RMB = 3;
// Keypad keys bound to mouse movement
#define K_UP 	72 
#define K_DOWN 	80
#define K_RIGHT 77
#define K_LEFT 	75
#define K_DOT 	83
#define K_NW 	71
#define K_NE 	73
#define K_SW 	79
#define K_SE 	81
/*
static const int K_UP = 72;
static const int K_DOWN = 80;
static const int K_RIGHT = 77;
static const int K_LEFT = 75;
static const int K_DOT = 83;
static const int K_NW = 71;
static const int K_NE = 73;	
static const int K_SW = 79;
static const int K_SE = 81;
*/
// Keypad keys bound to mouse click
#define K_LCLICK 82 
#define K_MCLICK 76
#define K_RCLICK 96
/*
static const int K_LCLICK = 82;
static const int K_MCLICK = 76;
static const int K_RCLICK = 96;
*/


/*
struct input_event {
        struct timeval time;
        __u16 type;
        __u16 code;
        __s32 value;
};
*/

#endif
