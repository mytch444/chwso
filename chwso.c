/*
 *  Copyright (c) 2015 Mytchel Hammond
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 *  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

static void usage(char *name)
{
	fprintf(stderr, "usage: %s -[rl] <wid>\n", name);
	exit(1);
}

int main(int argc, char **argv)
{
	int i, d;
	Display * dis;
	Window win;
	
	if (argc < 3)
		usage(argv[0]);

	dis = XOpenDisplay(NULL);
	
	if (argv[1][1] == 'r')
		d = 1;
	else if (argv[1][1] == 'l')
		d = 2;
	else
		usage(argv[0]);

	for (i = 2; i < argc; i++)
	{
		win = strtol(argv[i], NULL, 0);
		if (d == 1) XRaiseWindow(dis, win);
		else XLowerWindow(dis, win);
	}
	
	XCloseDisplay(dis);
	return 0;
}
