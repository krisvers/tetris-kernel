#pragma once

#define c__ 0
#define c_r 64
#define c_o 66
#define c_y 67
#define c_g 73
#define c_c 77
#define c_b 79
#define c_p 81

struct Tetramino {
	int x, y;
	unsigned char type;
    unsigned char rotation;
};

void draw_tetramino(struct Tetramino * ent);