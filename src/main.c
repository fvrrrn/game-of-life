#include "controls.h"
#include "graphics.h"
#include "logic.h"
#include <stdio.h>

int main() {
  int speed_ms = 500;
  int flag = 0;
  int generation[HEIGHT][WIDTH];
  int next_generation[HEIGHT][WIDTH];
  reset_generation(generation);
  reset_generation(next_generation);
  input_into_static_matrix(generation);
  if (!freopen("/dev/tty", "r", stdin))
    return 1;

  init_graphics();

  while (flag != 1) {
    clear();
    draw_frame(HEIGHT + 2, WIDTH + 2); // рамка вокруг поля H;W
    render_generation(generation);
    show_speed_info(speed_ms);

    char character = getch();
    handle_key_press(character, &speed_ms, &flag);

    advance_generation(generation, next_generation);
    copy_generation(generation, next_generation);

    napms(speed_ms);
    refresh();
  }

  end_graphics();
  return 0;
}
