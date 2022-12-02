#include "../includes/tatatype.h"

void game() {
	initscr();
	clear();


	// default setting
	move(0,70);
	addstr("*username");

	// score print
	move(1,1);
	addstr("score : ");
	// sprintf(score_str,"%d",score);
	// addstr(score_str);
	refresh();

	// hp print
	move(0,1);
	addstr("life  : ");
	// sprintf(hp_str,"%d",hp);
	// addstr(hp_str);
	refresh();

	// enter setting
	// draw(20, 20, "	| Enter | : ");
}