#include <video.h>
#include <keyboard.h>
#include <tetramino.h>
#include <font.h>

bool win = false;

struct Tetramino next = {
	1, 11, 1, 0
};
struct Tetramino current = {
	140, 60, 0, 1
};

void draw_borders() {
	for (int i = 0; i < 42; i++) {
		pixel_vidmem(i+139, 59, 0xF);
		pixel_vidmem(i+139, 140, 0xF);
	}

	for (int i = 0; i < 82; i++) {
		pixel_vidmem(139, 59+i, 0xF);
		pixel_vidmem(180, 59+i, 0xF);
	}
}

void render() {
	draw_borders();
	draw_placed();
	draw_tetramino(&current);
	check_collision(&current);

	print_str(0, 0, "Its Tetris Time!", c_r);

	current.y += 4;
}

void gamelogic() {
	
}

void update() {
	clear_vidmem();

	render();

	swap_buffers();

	gamelogic();

	for (int i = 0; i < 0x7FFFFFF; i++) {
		asm("nop");
	}
}

void main() {
	clear_vidmem();

	while (!win) {
		update();
	}
}
