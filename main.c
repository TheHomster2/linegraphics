#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 130;
  c.green = 150;
  c.blue = MAX_COLOR;

  clear_screen(s);

  int x0 = 250;
  int y0 = 326;
  int x1 = 0;
  int y1 = -132;

  for (int i = 0; i < 20; i++){
  	c.red = 12;
  	c.blue = MAX_COLOR / 2;
  	c.green = 200;
  	x0 -= 13;
  	y0 += 79;
  	x1 += 40;
  	y1 -= 37;
  	draw_line(x0, y0, x1, y1, s, c);
  }

  for (int i = 50; i < 250; i+= 20){
  	c.red = MAX_COLOR;
  	c.blue = 140;
  	c.green = MAX_COLOR / 4;
  	draw_line(0, 500, i, i , s, c);
  	draw_line(500, 0, -i, -i, s, c);
  	draw_line(i, -i, 0, 500, s, c);
  	draw_line(-i, i, 500, 0, s, c);
  }

  c.red = MAX_COLOR / 2;
  c.green = MAX_COLOR / 3;
  c.blue = MAX_COLOR / 4;

  draw_line(0, 500, 500, 0, s, c);
  draw_line(0, 0, 500, 500, s, c);
  draw_line(0, 250, 500, 250, s, c);
  draw_line(250, 0, 250, 500, s, c);

  display(s);
  save_extension(s, "lines.png");
}