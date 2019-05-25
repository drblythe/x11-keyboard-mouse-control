#include <stdio.h>
#include <ncurses.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>

#define DEFAULT_SENSITIVITY 25

// helpful
// https://stackoverflow.com/questions/5848909/why-does-xwarppointer-only-work-once-while-in-a-loop
// https://tronche.com/gui/x/xlib/input/XWarpPointer.html
// https://stackoverflow.com/questions/14526522/how-to-get-screen-height-and-width-in-c
//

int main (int argc, char * argv[])
{
	// Init Ncurses
	initscr();
    noecho();
    keypad(stdscr,TRUE);
    curs_set(0); /* 0, 1, 2 */
    cbreak();
    	
	// Init X
  	Display *dpy = XOpenDisplay(0);
	Window root_window;
   	root_window = XRootWindow(dpy, 0);
	XSelectInput(dpy, root_window, KeyReleaseMask);
	XWindowAttributes ra;
	XGetWindowAttributes(dpy, DefaultRootWindow(dpy), &ra);
	
	char key;
	int speed, mouse_x, mouse_y, MAX_Y, MAX_X ;
	MAX_Y = ra.height;
	MAX_X = ra.width;
	mouse_x = ra.width/2;
	mouse_y = ra.height/2;
	//(argc > 1) ? (speed = argv[0]) : (speed = DEFAULT_SENSITIVITY);
	//printf("%s",argv[0]);
	speed = DEFAULT_SENSITIVITY;

	while (1) {
		flushinp();
		key = getch();
		switch(key) {
		case '8':
			mouse_y -= speed;
			break;
		case '2':
			mouse_y += speed;
			break;
		case '6':
			mouse_x += speed;
			break;
		case '4':
			mouse_x -= speed;
			break;
		case '9':
			mouse_x += speed;
			mouse_y -= speed;
			break;
		case '7':
			mouse_x -= speed;
			mouse_y -= speed;
			break;
		case '3':
			mouse_x += speed;
			mouse_y += speed;
			break;
		case '1':
			mouse_x -= speed;
			mouse_y += speed;
			break;
		default:
			break;
		}
		if (mouse_x > MAX_X) mouse_x = MAX_X;
		if (mouse_x < 0) mouse_x = 0;
		if (mouse_y > MAX_Y) mouse_y = MAX_Y;
		if (mouse_y < 0) mouse_y = 0;
    	XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, mouse_x, mouse_y);
		XFlush(dpy);
    	XSync(dpy, False);
	}	

	return 0;
}
	

