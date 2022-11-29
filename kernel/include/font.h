#pragma once

#include <video.h>

#define c__ 0
#define c_r 65
#define c_o 66
#define c_y 67
#define c_g 72
#define c_c 75
#define c_b 74
#define c_p 78
#define c_w 15

void draw_char(int x, int y, char c, char color);
void print_str(int x, int y, const char * str, char color);