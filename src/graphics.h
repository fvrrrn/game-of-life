#ifndef GRAFIC_H
#define GRAFIC_H

#include <ncurses.h>

#include "main.h"

#define LIVE_CELL "##" //"\u2588\u2588"  // ██
#define DEAD_CELL " "
#define CURSOR_CELL "##" //"\u2588\u2588"  // ██ (синий)
#define MENU_HEIGHT 3

void resize_terminal(int height, int width);
void init_graphics(void);
void end_graphics(void);
void draw_frame(int height, int width);
void render_generation(int generation[HEIGHT][WIDTH]);
void draw_cursor(int y, int x, int visible);
void show_menu(int selected);
void doubleX_coords(int y, int x, int *out_y, int *out_x);
void transform_coords(int y, int x, int *ty, int *tx);
void show_speed_info(float speed);

#endif
