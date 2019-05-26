#include "bindings.h"
//	Need to run as sudo, because needs read access directly to device

// 	gcc -lX11 -lXtst kb_mouse.c
// 	./<executable> </dev/input/eventX>

// 	dependencies
//		libxtst-dev (XTest.h) 
//		X11

// helpful
// https://stackoverflow.com/questions/5848909/why-does-xwarppointer-only-work-once-while-in-a-loop
// https://tronche.com/gui/x/xlib/input/XWarpPointer.html
// https://stackoverflow.com/questions/14526522/how-to-get-screen-height-and-width-in-c
// https://linux.die.net/man/3/xtestfakebuttonevent
// https://stackoverflow.com/questions/8767524/how-do-we-simulate-a-mouse-click-with-xlib-c
// https://www.linuxquestions.org/questions/linux-software-2/simulate-right-click-550001/ (right mouse button)
// https://stackoverflow.com/questions/1485116/capturing-keystrokes-in-gnu-linux-in-c (read keypress directly from /dev/input/eventX)
//

/*
struct input_event {
	struct timeval time;
	__u16 type;
	__u16 code;
	__s32 value;
};
*/


//	TODO
//
//	diagonal movemnts
//	ONLY AFFECT THE MOUSE IF THE KEY IS ON THE KEYPAD
//	nanosleep in between polls so that many events arent created before you can even lift your finger
//		fix this shit -> the timer needs to PREVENT READING, not just wait because this still takes input
//		so this isnt really event waiting just a timer
//		set 'waiting' flag or something
//	have a toggle bound to ./delete keypad key so that you can toggle this thing on and off while you need to input or something
//	Have a click-and-hold thing, where the second false function isnt used
//	Vary movement based on key "state"
//		0 (pressed)	- pressed move more precisely
//		2 (held)- move faster
//		

int main (int argc, char * argv[])
{
	// Init X
  	Display *dpy = XOpenDisplay(0);
	Window root_window;
   	root_window = XRootWindow(dpy, 0);
	XSelectInput(dpy, root_window, KeyReleaseMask);
	XWindowAttributes ra;
	XGetWindowAttributes(dpy, DefaultRootWindow(dpy), &ra);
	
	int sens, mult, mouse_x, mouse_y, MAX_Y, MAX_X;	
	sens = DEFAULT_SENSITIVITY;
	MAX_Y = ra.height;
	MAX_X = ra.width;
	mouse_x = ra.width/2;
	mouse_y = ra.height/2;

	int fd;
    if(argc < 2) {
		printf("usage: %s <device>\n", argv[0]);
		return 1;
    }
    fd = open(argv[1], O_RDONLY);
	char key;
	struct input_event ev;
	
/*
 *	using input_event typename, which has:
 *		code
 *			this is the unique keycode
 *		value
 * 			0 for a key press
 * 			1 for a key release
 * 			2 for a key hold
 */

    while (1) {
    	read(fd, &ev, sizeof(struct input_event));

    	if(ev.type == 1)
		{
			// Debug
        	//printf("key %i state %i\n", ev.code, ev.value);
        	
			/* Set sensitivity/speed multiplyer if key is held */
			(ev.value == 2) ? (mult=5) : (mult=1);

        	switch(ev.code) {
			case K_UP:


				mouse_y -=sens*mult;
				break;
			case K_DOWN:
				mouse_y +=sens*mult;
				break;
			case K_RIGHT:
				mouse_x +=sens*mult;
				break;
			case K_LEFT:
				mouse_x -=sens*mult;
				break;
			case K_NW:
				mouse_y -=sens*mult;
				mouse_x -=sens*mult;
				break;	
			case K_NE:
				mouse_y -=sens*mult;
				mouse_x +=sens*mult;
				break;	
			case K_SW:
				mouse_y +=sens*mult;
				mouse_x -=sens*mult;
				break;	
			case K_SE:
				mouse_y +=sens*mult;
				mouse_x +=sens*mult;
				break;	
			case K_LCLICK:
				/*
					switch(ev.value
				}
				*/
				printf("\n%s\n","LEFT CLICK");
				XTestFakeButtonEvent(dpy, LMB, True, CurrentTime);
				XTestFakeButtonEvent(dpy, LMB, False, CurrentTime);
				break;
			case K_MCLICK:
				XTestFakeButtonEvent(dpy, MMB, True, CurrentTime);
				XTestFakeButtonEvent(dpy, MMB, False, CurrentTime);
				printf("\n%s\n","MIDDLE CLICK");
				break;
			case K_RCLICK:
				XTestFakeButtonEvent(dpy, RMB, True, CurrentTime);
				XTestFakeButtonEvent(dpy, RMB, False, CurrentTime);
				printf("\n%s\n","RIGHT CLICK");
				break;
			default:
				break;
			}
		}
		/* Keep mouse within screen boundaries */
		if (mouse_x > MAX_X) mouse_x = MAX_X;
		if (mouse_x < 0) mouse_x = 0;
		if (mouse_y > MAX_Y) mouse_y = MAX_Y;
		if (mouse_y < 0) mouse_y = 0;
		
		/* Move the pointer */
    	XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, mouse_x, mouse_y);
		XFlush(dpy);
    	XSync(dpy, False);
		
		/* Handle waiting flag */

		/*
		struct timespec req = {.tv_sec = 0, .tv_nsec = 50000000};
		struct timespec rem, *a = &req, *b = &rem;
		while (nanosleep(a, b) && errno == EINTR) {
			struct timespec *tmp = a;
				a = b;
				b = tmp;
		}
		*/
    }
	exit(EXIT_SUCCESS);
}
	
















