#include <video.h>
#include <keyboard.h>
#include <tetramino.h>
#include <font.h>

bool win = false;

struct Tetramino next = {
	1, 11, 1, 0
};
struct Tetramino test = {
	30, 30, 0, 0
};
struct Tetramino test1 = {
	34, 30, 0, 0
};
struct Tetramino test2 = {
	38, 30, 1, 0
};
struct Tetramino test3 = {
	50, 30, 0, 0
};
struct Tetramino test4 = {
	50, 30, 0, 0
};
struct Tetramino test5 = {
	50, 30, 0, 0
};

void draw_borders() {
	for (int i = 0; i < 40; i++) {
		pixel_vidmem(i+120, 60, 0xF);
		pixel_vidmem(i+120, 140, 0xF);
	}

	for (int i = 0; i < 80; i++) {
		pixel_vidmem(120, 60+i, 0xF);
		pixel_vidmem(160, 60+i, 0xF);
	}
}

void render() {
	draw_borders();
	draw_tetramino(&test);
	draw_tetramino(&test1);
	draw_tetramino(&test2);
	draw_tetramino(&test3);
	draw_tetramino(&test4);
	draw_tetramino(&test5);
}

void update() {
	clear_vidmem();

	render();

	swap_buffers();

	//gamelogic();

	for (int i = 0; i < 0x26FFFF; i++) {
		asm("nop");
	}
}

void main() {
	clear_vidmem();

	while (!win) {
		update();
	}
}