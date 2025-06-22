#include "graphics.h"

#include <curses.h>

#include "main.h"

void resize_terminal(int height, int width) {
  printf("\033[8;%d;%dt", height, width);
  refresh();
}
void init_graphics(void) {
  // setlocale(LC_ALL, ""); // Локализация для Unicode
  resize_terminal(HEIGHT + 4 + 2, (WIDTH + 2) * 2); //+2 для рамки
  initscr();
  cbreak();
  start_color();
  curs_set(0);
  noecho();
  keypad(stdscr, TRUE);
  timeout(0);
  nodelay(stdscr, TRUE);

  // Цветовые пары
  init_pair(1, COLOR_WHITE, COLOR_WHITE);   // Живые клетки
  init_pair(2, COLOR_BLUE, COLOR_BLUE);     // Курсор
  init_pair(3, COLOR_WHITE, COLOR_BLACK);   // Меню
  init_pair(4, COLOR_YELLOW, COLOR_YELLOW); // Рамка
}
void doubleX_coords(int y, int x, int *out_y, int *out_x) {
  *out_x = x * 2;
  *out_y = y;
}
void transform_coords(int y, int x, int *ty, int *tx) {
  int screen_y = y + 1;
  int screen_x = x + 1;
  //*tx = x + 1;  //+1 для рамочки
  //*ty = y + 1; //+1 для рамочки
  // doubleX_coords(screen_y, screen_x, ty, tx);
  doubleX_coords(screen_y, screen_x, ty, tx);
}

void draw_frame(int height, int width) {
  attron(COLOR_PAIR(4));
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (x == 0 || x == (width - 1) || y == 0 || y == (height - 1)) {
        int ty, tx;
        doubleX_coords(y, x, &ty, &tx);
        mvprintw(ty, tx, LIVE_CELL);
        // mvprintw(y, x * 2 + 1, LIVE_CELL);
      }
    }
  }
  attroff(COLOR_PAIR(4));
}

void render_generation(int generation[HEIGHT][WIDTH]) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      int tx, ty;
      transform_coords(y, x, &ty, &tx);

      if (generation[y][x]) {
        attron(COLOR_PAIR(1));
        mvprintw(ty, tx, LIVE_CELL);
        // mvprintw(ty, tx + 1, LIVE_CELL);
        attroff(COLOR_PAIR(1));
      } else {
        mvprintw(ty, tx, DEAD_CELL);
        // mvprintw(ty, tx + 1, DEAD_CELL);
      }
    }
  }
}

/*
void draw_cursor(int y, int x, int visible) {
    int tx, ty;
    transform_coords(y, x, &ty, &tx);

    if (visible) {
        attron(COLOR_PAIR(2));
        mvprintw(ty, tx, CURSOR_CELL);
        mvprintw(ty, tx + 1, CURSOR_CELL);
        attroff(COLOR_PAIR(2));
    } else {
        // При скрытии курсора восстанавливаем клетку
        if (visible) {
            attron(COLOR_PAIR(1));
            mvprintw(ty, tx, LIVE_CELL);
            mvprintw(ty, tx + 1, LIVE_CELL);
            attroff(COLOR_PAIR(1));
        } else {
            mvprintw(ty, tx, DEAD_CELL);
            mvprintw(ty + 1, tx, DEAD_CELL);
        }
    }
}
*/
void show_speed_info(float speed) {
  attron(A_BOLD);
  mvprintw(HEIGHT + 4, 0, "Speed: %.2f (A/Z to change, SPACE to exit)", speed);
  attroff(A_BOLD);
}

/*
void show_menu(int selected) {
    attron(COLOR_PAIR(3));
    mvprintw(0, 0, "1. Загрузить шаблон");
    mvprintw(1, 0, "2. Ручная отрисовка");
    mvprintw(2, 0, "3. Выход");

    // Подсветка выбранного пункта
    attron(A_REVERSE);
    mvprintw(selected, 0,
             selected == 0 ? "1. Загрузить шаблон" : (selected == 1 ? "2. Ручная
отрисовка" : "3. Выход")); attroff(A_REVERSE);

    attroff(COLOR_PAIR(3));
}
*/
void end_graphics(void) { endwin(); }
