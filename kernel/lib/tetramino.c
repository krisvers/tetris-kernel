#include <tetramino.h>
#include <video.h>

static char tetraminos[84] = {
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
	for (int x = 0; x < 16; x += 4) {
		for (int y = 0; y < 12; y += 4) {
            if (tetraminos[ent->type * 12 + (y) + x/4] != 0)
			{
                pixel_vidmem(ent->x * 4 + x, ent->y * 4 + y, tetraminos[ent->type * 12 + (y) + x/4]);
		    	pixel_vidmem(ent->x * 4 + x, ent->y * 4 + y+1, tetraminos[ent->type * 12 + (y) + x/4]);
	    		pixel_vidmem(ent->x * 4 + x, ent->y * 4 + y+2, tetraminos[ent->type * 12 + (y) + x/4]);
	    		pixel_vidmem(ent->x * 4 + x, ent->y * 4 + y+3, tetraminos[ent->type * 12 + (y) + x/4]);
	    		pixel_vidmem(ent->x * 4 + x+1, ent->y * 4 + y, tetraminos[ent->type * 12 + (y) + x/4]);
	    		pixel_vidmem(ent->x * 4 + x+1, ent->y * 4 + y+1, tetraminos[ent->type * 12 + (y) + x/4]);
		    	pixel_vidmem(ent->x * 4 + x+1, ent->y * 4 + y+2, tetraminos[ent->type * 12 + (y) + x/4]);
    			pixel_vidmem(ent->x * 4 + x+1, ent->y * 4 + y+3, tetraminos[ent->type * 12 + (y) + x/4]);
	    		pixel_vidmem(ent->x * 4 + x+2, ent->y * 4 + y, tetraminos[ent->type * 12 + (y) + x/4]);
		    	pixel_vidmem(ent->x * 4 + x+2, ent->y * 4 + y+1, tetraminos[ent->type * 12 + (y) + x/4]);
    			pixel_vidmem(ent->x * 4 + x+2, ent->y * 4 + y+2, tetraminos[ent->type * 12 + (y) + x/4]);
			    pixel_vidmem(ent->x * 4 + x+2, ent->y * 4 + y+3, tetraminos[ent->type * 12 + (y) + x/4]);
    			pixel_vidmem(ent->x * 4 + x+3, ent->y * 4 + y, tetraminos[ent->type * 12 + (y) + x/4]);
			    pixel_vidmem(ent->x * 4 + x+3, ent->y * 4 + y+1, tetraminos[ent->type * 12 + (y) + x/4]);
	    		pixel_vidmem(ent->x * 4 + x+3, ent->y * 4 + y+2, tetraminos[ent->type * 12 + (y) + x/4]);
    			pixel_vidmem(ent->x * 4 + x+3, ent->y * 4 + y+3, tetraminos[ent->type * 12 + (y) + x/4]);
            }
		}
	}
}