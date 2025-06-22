#include "controls.h"

void handle_key_press(char character, int *speed_ms, int *flag) {
  if (character == ' ') { // если нажата пробел
    *flag = 1; // меняем флаг, чтобы выйти из цикла
  } else if (character == 'a') {
    if (*speed_ms > 50) {
      *speed_ms -= 50;
    }
  } else if (character == 'z') {
    if (*speed_ms < 5000) {
      *speed_ms += 50;
    }
  }
}
