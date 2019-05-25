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
#include <unistd.h>

#define DEFAULT_SENSITIVITY 25
#define M_LCLICK 1
#define M_MCLICK 2
#define M_RCLICK 3
#define K_UP 72
#define K_DOWN 80
#define K_RIGHT 77
#define K_LEFT 75
#define K_LCLICK 82
#define K_MCLICK 76
#define K_RCLICK 96

