#pragma once

#include <stdbool.h>
#include <video.h>
#include <color.h>

struct Tetramino {
	int x, y;
	unsigned char type;
    unsigned char rotation;
};

void draw_tetramino(struct Tetramino * ent);
void draw_placed();
bool check_collision(struct Tetramino * ent);