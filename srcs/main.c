#include "../includes/type.h"

#define DEFINED_KEY 0x19101969

int main(void)
{
	int option;
	time_t start;
	pid_t pid;

	initscr();
	clear();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(0, COLOR_YELLOW, COLOR_BLACK);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);


	if (!(vfork())) /* child process */
		game_timer(getpid());
	game_header();
	game();

	endwin();
	exit(0);

}