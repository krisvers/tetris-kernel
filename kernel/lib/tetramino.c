#include <tetramino.h>
#include <video.h>

static char tetraminos[] = {
    c_c, c_c, c_c, c_c,     //  long I and rotation
    c__, c__, c__, c__,
    c__, c__, c__, c__,
    c__, c__, c__, c__,

    c_c, c__, c__, c__,
    c_c, c__, c__, c__,
    c_c, c__, c__, c__,
    c_c, c__, c__, c__,

    c_c, c_c, c_c, c_c,
    c__, c__, c__, c__,
    c__, c__, c__, c__,
    c__, c__, c__, c__,

    c_c, c__, c__, c__,
    c_c, c__, c__, c__,
    c_c, c__, c__, c__,
    c_c, c__, c__, c__,


    c_y, c_y, c__, c__,
    c_y, c_y, c__, c__,
    c__, c__, c__, c__,
    c__, c__, c__, c__,

    c_y, c_y, c__, c__,
    c_y, c_y, c__, c__,
    c__, c__, c__, c__,
    c__, c__, c__, c__,

    c_y, c_y, c__, c__,
    c_y, c_y, c__, c__,
    c__, c__, c__, c__,
    c__, c__, c__, c__,

    c_y, c_y, c__, c__,
    c_y, c_y, c__, c__,
    c__, c__, c__, c__,
    c__, c__, c__, c__,


    c_p, c_p, c_p, c__,
    c__, c_p, c__, c__,
    c__, c__, c__, c__,
    c__, c__, c__, c__,

    c_p, c__, c__, c__,
    c_p, c_p, c__, c__,
    c_p, c__, c__, c__,
    c__, c__, c__, c__,

    c__, c_p, c__, c__,
    c_p, c_p, c_p, c__,
    c__, c__, c__, c__,
    c__, c__, c__, c__,

    c__, c_p, c__, c__,
    c_p, c_p, c__, c__,
    c__, c_p, c__, c__,
    c__, c__, c__, c__,


    c_o, c_o, c__, c__,
    c__, c_o, c__, c__, 
    c__, c_o, c__, c__, 
    c__, c__, c__, c__,

    c__, c__, c_o, c__,
    c_o, c_o, c_o, c__, 
    c__, c__, c__, c__, 
    c__, c__, c__, c__,

    c_o, c__, c__, c__,
    c_o, c__, c__, c__, 
    c_o, c_o, c__, c__, 
    c__, c__, c__, c__,

    c_o, c_o, c_o, c__,
    c_o, c__, c__, c__, 
    c__, c__, c__, c__, 
    c__, c__, c__, c__,


    c__, c_g, c_g, c__,
    c_g, c_g, c__, c__,
    c__, c__, c__, c__,
    c__, c__, c__, c__,

    c_g, c__, c__, c__,
    c_g, c_g, c__, c__,
    c__, c_g, c__, c__,
    c__, c__, c__, c__,

    c__, c_g, c_g, c__,
    c_g, c_g, c__, c__,
    c__, c__, c__, c__,
    c__, c__, c__, c__,

    c_g, c__, c__, c__,
    c_g, c_g, c__, c__,
    c__, c_g, c__, c__,
    c__, c__, c__, c__,


    c_b, c_b, c__, c__,
    c_b, c__, c__, c__,
    c_b, c__, c__, c__,
    c__, c__, c__, c__,

    c_b, c_b, c_b, c__,
    c__, c__, c_b, c__,
    c__, c__, c__, c__,
    c__, c__, c__, c__,

    c__, c_b, c__, c__,
    c__, c_b, c__, c__,
    c_b, c_b, c__, c__,
    c__, c__, c__, c__,

    c__, c__, c_b, c__,
    c_b, c_b, c_b, c__,
    c__, c__, c__, c__,
    c__, c__, c__, c__,


    c_r, c_r, c__, c__,
    c__, c_r, c_r, c__,
    c__, c__, c__, c__,
    c__, c__, c__, c__,

    c__, c_r, c__, c__,
    c_r, c_r, c__, c__,
    c_r, c__, c__, c__,
    c__, c__, c__, c__,

    c_r, c_r, c__, c__,
    c__, c_r, c_r, c__,
    c__, c__, c__, c__,
    c__, c__, c__, c__,

    c__, c_r, c__, c__,
    c_r, c_r, c__, c__,
    c_r, c__, c__, c__,
    c__, c__, c__, c__,
};

char rot[] = {

};

void draw_tetramino(struct Tetramino * ent) {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (tetraminos[ent->type * 4 + ent->rotation * 16 + y * 4 + x] != 0) {
				for (int a = 0; a < 4; a++) {
					for (int b = 0; b < 4; b++) {
						pixel_vidmem(x * 4 + a + ent->x, y*4 + b + ent->y, tetraminos[ent->type * 4 + ent->rotation * 16 + y * 4 +x]);
					}
				}
			}
		}
	}
}
