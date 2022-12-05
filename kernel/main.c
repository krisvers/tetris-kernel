#include <video.h>
#include <keyboard.h>
#include <tetramino.h>
#include <font.h>

bool win = false;
char input = 0;
unsigned int move = 0;
unsigned int randrot = 0;
unsigned int randtype = 0;
unsigned int speed = 1;

struct Tetramino next = {
	197, 77, 0, 1
};
struct Tetramino current = {
	152, 60, 0, 1
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
}

void gamelogic() {
	current.y += 4;

	if (check_collision(&current)) {
		current = next;
		current.x = 152;
		current.y = 60;
		next.rotation = randrot;
		next.type = randtype;
	}

	current.x += 4 * move;
	
	if (current.x < 140) {
		current.x = 140;
	}

	switch (current.type) {
		case 0:
			if (current.rotation == 0) {
				if (current.x > 190) {
					current.x = 190;
				}
			} else if (current.rotation % 2 == 0) {
				if (current.x > 164) {
					current.x = 164;
				}
			} else {
				if (current.x > 180) {
					current.x = 180;
				}
			}
		case 1:
			if (current.x > 172) {
				current.x = 172;
			}
		case 2:
			if (current.rotation % 2 != 0) {
				if (current.x > 172) {
					current.x = 172;
				}
			}
	}

	check_line();
}

void update() {
	clear_vidmem();

	render();

	swap_buffers();

	gamelogic();

	if (speed > 4 && current.y < 64) {
		for (; speed > 4;) {
			asm("nop");

			input = read_key_char();

			if (input != ' ') {
				speed = 1;
			}
		}
	}

	for (int i = 0; i < 0x1FFFFF/speed; i++) {
		asm("nop");

		input = read_key_char();

		move = 0;
		speed = 1;

		if (input == 'a') 
			move = -1;
		if (input == 'd')
			move = 1;
		if (input == 's')
			speed = 4;
		if (input == ' ')
			speed = 1000;
		if (input == 'w')
			current.rotation++;
			if (current.rotation > 3)
				current.rotation = 0;
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
