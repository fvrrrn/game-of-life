#ifndef LOGIC_H
#define LOGIC_H
#include "main.h"

void advance_generation(int current_generation[HEIGHT][WIDTH],
                        int next_generation[HEIGHT][WIDTH]);
void copy_generation(int current_generation[HEIGHT][WIDTH],
                     int next_generation[HEIGHT][WIDTH]);
void reset_generation(int generation[HEIGHT][WIDTH]);
int input_into_static_matrix(int matrix[HEIGHT][WIDTH]);

#endif
