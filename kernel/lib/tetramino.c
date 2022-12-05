#include <tetramino.h>

static char placed[200];

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

void draw_tetramino(struct Tetramino * ent) {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (tetraminos[ent->type * 64 + ent->rotation * 16 + y * 4 + x] != 0) {
				for (int a = 0; a < 4; a++) {
					for (int b = 0; b < 4; b++) {
						pixel_vidmem(x * 4 + a + ent->x, y * 4 + b + ent->y, tetraminos[ent->type * 64 + ent->rotation * 16 + (y * 4) + x]);
					}
				}
			}
		}
	}
}

void draw_placed() {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 20; y++) {
            if (placed[y * 10 + x] != 0) {
				for (int a = 0; a < 4; a++) {
					for (int b = 0; b < 4; b++) {
						pixel_vidmem(x * 4 + a + 140, y * 4 + b + 60, placed[y * 10 + x]);
					}
				}
			}
        }
    }
}

bool check_collision(struct Tetramino * ent) {
    bool collision = false;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (tetraminos[ent->type * 64 + ent->rotation * 16 + (y * 4) + (x)] != 0) {
                if (placed[((ent->y - 60)/4 + y)* 10 + (ent->x - 140)/4 + x] != 0 || ((ent->y - 60)/4 + y)* 10 + (ent->x - 140)/4 + x > 200) {
                    collision = true;
                }
            }
        }
    }

    if (collision) {
        pixel_vidmem(0, 0, c_g);
        for (int x = 0; x < 4; x++) {
           for (int y = 0; y < 4; y++) {
                if (tetraminos[ent->type * 64 + ent->rotation * 16 + (y * 4) + x] != 0) {
                    placed[((ent->y-4 - 60)/4 + y) * 10 + (ent->x - 140)/4 + x] = tetraminos[ent->type * 64 + ent->rotation * 16 + (y * 4) + x];
                }
            }
        }
        ent->y = 60;
    } else {
        pixel_vidmem(0, 0, c_r);
    }

    return collision;
}