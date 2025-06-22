#include "logic.h"
#include <stdio.h>

int input_into_static_matrix(int matrix[HEIGHT][WIDTH]) {
  for (int row = 1, col = 0; row < HEIGHT && col < HEIGHT;) {
    switch (getchar()) {
    case '0':
      matrix[row][col] = 0;
      col++;
      break;
    case '1':
      matrix[row][col] = 1;
      col++;
      break;
    case '\n':
      row++;
      col = 0;
      break;
    case EOF:
      return 0;
    }
  }
  return 0;
}

void reset_generation(int generation[HEIGHT][WIDTH]) {
  for (int row = 0; row < HEIGHT; row++)
    for (int col = 0; col < WIDTH; col++)
      generation[row][col] = 0;
}

int get_alive_neighbors_count(int generation[HEIGHT][WIDTH], int row, int col) {
  int count = 0;
  for (int dr = -1; dr <= 1; dr++)
    for (int dc = -1; dc <= 1; dc++) {
      if (dc == 0 && dr == 0)
        continue;
      count +=
          generation[(row + dr + HEIGHT) % HEIGHT][(col + dc + WIDTH) % WIDTH];
    }
  return count;
}

void advance_generation(int current_generation[HEIGHT][WIDTH],
                        int next_generation[HEIGHT][WIDTH]) {
  for (int row = 0; row < HEIGHT; row++)
    for (int col = 0; col < WIDTH; col++) {
      int alive_count = get_alive_neighbors_count(current_generation, row, col);
      if (current_generation[row][col] == 1)
        next_generation[row][col] = (alive_count == 2 || alive_count == 3);
      else
        next_generation[row][col] = (alive_count == 3);
    }
}

void copy_generation(int current_generation[HEIGHT][WIDTH],
                     int next_generation[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; i++)
    for (int j = 0; j < WIDTH; j++)
      current_generation[i][j] = next_generation[i][j];
}
