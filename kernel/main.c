#include <video.h>
#include <keyboard.h>
#include <tetramino.h>
#include <font.h>

bool win = false;

struct Tetramino next = {
	1, 11, 1, 0
};
struct Tetramino current = {
	140, 60, 8, 2
};

void draw_borders() {
	for (int i = 0; i < 42; i++) {
		pixel_vidmem(i+139, 59, 0xF);
		pixel_vidmem(i+139, 141, 0xF);
	}

	for (int i = 0; i < 82; i++) {
		pixel_vidmem(139, 59+i, 0xF);
		pixel_vidmem(181, 59+i, 0xF);
	}
}

void render() {
	draw_borders();
	draw_tetramino(&current);
}

void gamelogic() {
	
}

void update() {
	clear_vidmem();

	render();

	swap_buffers();

	gamelogic();

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
