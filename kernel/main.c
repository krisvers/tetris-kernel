#include <video.h>
#include <keyboard.h>
#include <tetramino.h>
#include <font.h>

bool win = false;
unsigned int move = 0;
unsigned int randrot = 0;
unsigned int randtype = 0;

struct Tetramino next = {
	197, 77, 1, 0
};
struct Tetramino current = {
	152, 60, 2, 2
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

	print_str(95, 30, "next", c_p);

	for (int i = 0; i < 24; i++) {
		pixel_vidmem(i+193, 75, 0xF);
		pixel_vidmem(i+193, 95, 0xF);
	}

	for (int i = 0; i < 20; i++) {
		pixel_vidmem(193, i+75, 0xF);
		pixel_vidmem(216, i+75, 0xF);
	}

	draw_tetramino(&next);
}

void render() {
	draw_borders();
	draw_placed();
	draw_tetramino(&current);

	current.y += 4;
	current.x += 4 * move;
}

void gamelogic() {
	if (check_collision(&current)) {
		current = next;
		current.x = 152;
		current.y = 60;
		next.rotation = randrot;
		next.type = randtype;
	}

	if (current.x < 160) {
		current.x = 160;
	}
}

void update() {
	clear_vidmem();

	render();

	swap_buffers();

	gamelogic();

	for (int i = 0; i < 0x3FFFFFF; i++) {
		asm("nop");
	}

	if (read_key_char() == 'a') {
		move = -1;
	} else if (read_key_char() == 'd') {
		move = 1;
	} else {
		move = 0;
	}

	randtype++;
	randrot++;
	if (randtype > 6) {
		randtype = 0;
	}
	if (randrot > 3) {
		randrot = 0;
	}
}

void main() {
	clear_vidmem();

	while (!win) {
		update();
	}
}
