#include "../includes/tatatype.h"

void free_node();
void force_quit(int signum);

int main(void)
{

	char option;

	// 초기화
	initscr();
	clear();

	// signal 처리
	// signal(SIGQUITs,function);

	move(3,10);
	addstr("******************************************************");
	move(4,10);
	addstr("*                                                    *");
	move(5,10);
	addstr("*                   TYPING GAME                      *");
	move(6,10);
	addstr("*                                                    *");
	move(7,10);
	addstr("*                                                    *");
	move(8,10);
	addstr("******************************************************");
	move(11,10);
	addstr("1. Start Game					      ");
	move(12,10);
	addstr("2. User score					      ");
	move(13,10);
	addstr("3. EXIT  					      ");

	move(16,20);
	refresh();

	option = getch();
	switch (option) {
		case '1':
			game();
	}
	// return 0;
}


// node free 함수
void reset() {
}

void force_quit(int signum){
	reset();
	curs_set(1);
	endwin();
	exit(1);
}
