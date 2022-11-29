#include <font.h>

static char font[570] = {
    0, 1, 0,
    1, 0, 1,
    1, 1, 1,
    1, 0, 1,
    1, 0, 1,

    1, 1, 0,
    1, 0, 1,
    1, 1, 0,
    1, 0, 1,
    1, 1, 0,

    0, 1, 1,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    0, 1, 1,

    1, 1, 0,
    1, 0, 1,
    1, 0, 1,
    1, 0, 1,
    1, 1, 0,

    1, 1, 1,
    1, 0, 0,
    1, 1, 0,
    1, 0, 0,
    1, 1, 1,

    1, 1, 1,
    1, 0, 0,
    1, 1, 0,
    1, 0, 0,
    1, 0, 0,

    0, 1, 1,
    1, 0, 0,
    1, 0, 0,
    1, 0, 1,
    0, 1, 1,

    1, 0, 1,
    1, 0, 1,
    1, 1, 1,
    1, 0, 1,
    1, 0, 1,

    1, 1, 1,
    0, 1, 0, 
    0, 1, 0,
    0, 1, 0,
    1, 1, 1,

    0, 1, 1,
    0, 0, 1,
    0, 0, 1,
    1, 0, 1,
    0, 1, 1,

    1, 0, 1,
    1, 0, 1,
    1, 1, 0,
    1, 0, 1,
    1, 0, 1,

    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 1, 1,

    1, 1, 1,
    1, 1, 1,
    1, 0, 1,
    1, 0, 1,
    1, 0, 1,

    1, 0, 1,
    1, 1, 1,
    1, 0, 1,
    1, 0, 1,
    1, 0, 1,

    1, 1, 1,
    1, 0, 1,
    1, 0, 1,
    1, 0, 1,
    1, 1, 1,

    1, 1, 1,
    1, 0, 1,
    1, 1, 1,
    1, 0, 0,
    1, 0, 0,

    0, 1, 0,
    1, 0, 1,
    1, 0, 1,
    1, 0, 1,
    0, 1, 1,

    1, 1, 0,
    1, 0, 1,
    1, 1, 0,
    1, 0, 1,
    1, 0, 1,

    0, 1, 1,
    1, 0, 0,
    0, 1, 0,
    0, 0, 1,
    1, 1, 0,

    1, 1, 1,
    0, 1, 0,
    0, 1, 0,
    0, 1, 0,
    0, 1, 0,

    1, 0, 1,
    1, 0, 1,
    1, 0, 1,
    1, 0, 1,
    1, 1, 1,

    1, 0, 1,
    1, 0, 1,
    1, 0, 1,
    1, 0, 1,
    0, 1, 0,

    1, 0, 1,
    1, 0, 1,
    1, 0, 1,
    1, 1, 1,
    1, 0, 1,

    1, 0, 1,
    1, 0, 1,
    0, 1, 0,
    1, 0, 1,
    1, 0, 1,

    1, 0, 1,
    1, 0, 1,
    0, 1, 0,
    0, 1, 0,
    0, 1, 0,

    1, 1, 1,
    0, 0, 1,
    0, 1, 0,
    1, 0, 0,
    1, 1, 1,

    0, 1, 0,
    1, 0, 1,
    1, 0, 1,
    1, 0, 1,
    0, 1, 0,

    0, 1, 0,
    1, 1, 0,
    0, 1, 0,
    0, 1, 0,
    1, 1, 1,

    1, 1, 0,
    0, 0, 1,
    0, 1, 0,
    1, 0, 0,
    1, 1, 1,

    1, 1, 0,
    0, 0, 1,
    0, 1, 0,
    0, 0, 1,
    1, 1, 0,

    1, 0, 0,
    1, 0, 1,
    1, 1, 1,
    0, 0, 1,
    0, 0, 1,

    1, 1, 1,
    1, 0, 0,
    1, 1, 0,
    0, 0, 1,
    1, 1, 0,

    1, 1, 1,
    1, 0, 0,
    1, 1, 1,
    1, 0, 1,
    1, 1, 1,

    1, 1, 1,
    0, 0, 1,
    0, 1, 0,
    0, 1, 0,
    0, 1, 0,

    1, 1, 1,
    1, 0, 1,
    1, 1, 1,
    1, 0, 1,
    1, 1, 1,

    1, 1, 1,
    1, 0, 1,
    1, 1, 1,
    0, 0, 1,
    0, 0, 1,

    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,

    1, 1, 1,
    1, 1, 1,
    1, 1, 1,
    1, 1, 1,
    1, 1, 1,
};

void draw_char(int x, int y, char c, char color) {
    if (c >= 65 && c <= 90) {
        c -= 65;
    } else if (c >= 97 && c <= 122) {
        c -= 97;
    } else if (c >= 48 && c >= 57) {
        c -= 48 + 26;
    } else {
        c = 36;
    }

    for (int a = 0; a < 6; a += 2) {
		for (int b = 0; b < 10; b += 2) {
			pixel_vidmem(x * 2 + a, y * 2 + b, font[(c * 15) + (int) (b * 1.5) + a/2] * color);
			pixel_vidmem(x * 2 + a+1, y * 2 + b, font[(c * 15) + (int) (b * 1.5) + a/2] * color);
			pixel_vidmem(x * 2 + a, y * 2 + b+1, font[(c * 15) + (int) (b * 1.5) + a/2] * color);
			pixel_vidmem(x * 2 + a+1, y * 2 + b+1, font[(c * 15) + (int) (b * 1.5) + a/2] * color);
		}
	}
}

void print_str(int x, int y, const char * str, char color) {
    for (int c = 0; str[c] != 0; c++) {
        draw_char(x+c*4, y, str[c], color);
    }
}