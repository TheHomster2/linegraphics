#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int octant(int x0, int y0, int x1, int y1){
	int deltax = x1 - x0;
	int deltay = y1 - y0;

	//octant 1 with bound 0 to 1
	if (deltay >= 0 && deltax >= deltay){
		return 1;
	}
	//octant 2 could tend to 1
	else if (deltay >= 0 && deltax <= deltay){
		return 2;
	}
	//octant 7 with bound of -1 to 0
	else if (deltay < 0 && deltax <= -1 * deltay){
		return 7;
	}
	//octant 8 could tend to -1
	else if (deltay < 0 && deltax >= -1 * deltay){
		return 8;
	}
	//error
	else {

	return -1;

	}
}

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
	if (x1 < x0){
		int temp = x0;
		x0 = x1;
		x1 = temp;	
		temp = y0;
		y1 = y0;
		y1 = temp;
	}

	int A = y1 - y0;
	int B = x0 - x1;
	int d;
	int add_octant = octant(x0, y0, x1, y1);
	int x = x0;
	int y = y0;

	if (add_octant == 1){
		d = 2 * A + B;
		while (x <= x1){
			plot(s, c, x, y);
			if (d > 0){
				y++;
				d += 2 * B;
			}
			x++;
			d += 2 * A;
		}
	}

	else if (add_octant == 2){
		d = A + 2 * B;
		while (y <= y1){
			plot(s, c, x, y);
			if (d < 0){
				x++;
				d += 2 * A;
			}
			y++;
			d += 2 * B;
		}
	}

	else if (add_octant == 7){
		d = A - 2 * B;
		while (y >= y1){
			plot(s, c, x, y);
			if (d > 0){
				x++;
				d += 2 * A;
			}
			y--;
			d -= 2 * B;
		}
	}

	else{

		d = 2 * A - B;
		while (x <= x1){
			plot(s, c, x, y);
			if (d < 0){
				y--;
				d -= 2 * B;
			}
			x++;
			d += 2 * B;
		}
	}
}
