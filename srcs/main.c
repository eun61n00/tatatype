#include "../includes/tatatype.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define DEFINED_KEY 0x19101969

int remaining = 100;
pid_t player_list[2] = {NULL, NULL};

int	define_player(int msg_qid)
{
	struct msqid_ds m_stat;
	if (msgctl(msg_qid, IPC_STAT, &m_stat) == -1){
		printf("msgctl failed");
		exit(-1);
	}
	if (!player_list[0] || player_list[0] == m_stat.msg_lspid) {
		player_list[0] = m_stat.msg_lspid;
		return 0;
	} else {
		player_list[1] = m_stat.msg_lspid;
		return 1;
	}
}

void game_header() {
	mvaddstr(1, 1, "******************************************************");
	mvaddstr(2, 1, "*                                                    *");
	mvaddstr(3, 1, "*                   TYPING GAME                      *");
	mvaddstr(4, 1, "*                                                    *");
	mvaddstr(5, 1, "*                       developed by Eunbin Kwon     *");
	mvaddstr(6, 1, "******************************************************");
	mvaddstr(7, 1, "Press Enter key to start game");
}

void find_word(char *msg_input, word_node *node_list, int player)
{
	int i = 0;
	int j;
	word_node *tmp = node_list;

	while (tmp && tmp->next) {
		if (strcmp(tmp->string, msg_input) == 0) {
			move(tmp->row, tmp->col);
			for (j = 0; j < strlen(msg_input); j++) {
				delch();
			}
			mvinsstr(tmp->row, tmp->col, msg_input);
			refresh();
			break;
		}
		tmp = tmp->next;
	}
	return ;
}

void game()
{
	int msg_qid;
	int player;
	struct {
		long mtype;
		char input[256];
	} msg;
	word_node *node_list;
	struct msqid_ds m_stat;

	mvaddstr(10, 70, "username");

	// TODO print remaining time and score

	node_list = make_game_board();
	// attron(COLOR_PAIR(0) | A_BOLD);

	if ((msg_qid = msgget(DEFINED_KEY, IPC_CREAT | 0666)) < 0) {
		perror("msgget: ");
		exit(-1);
	}

	while (TRUE) {
		memset(msg.input, 0x0, 256);
		if (msgrcv(msg_qid, &msg, 256, 0, 0) < 0) {
			perror("msgrcv: ");
			exit(-1);
		}
		if(msgctl(msg_qid, IPC_STAT, &m_stat) == -1){
			printf("msgctl failed");
			exit(-1);
		}
		player = define_player(msg_qid);
		if (player == 0) {
			attroff(COLOR_PAIR(1));
			attron(COLOR_PAIR(0) | A_BOLD);
			refresh();
		} else {
			attroff(COLOR_PAIR(0));
			attron(COLOR_PAIR(1) | A_BOLD);
			refresh();
		}
		refresh();
		find_word(msg.input, node_list, player);
		refresh();
	}
}

int main(void)
{
	int option;

	initscr();
	clear();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(0, COLOR_YELLOW, COLOR_BLACK);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);

	game_header();
	game();

	// while ((option = getch()) != KEY_ENTER) {
	// 	game();
	// }
	endwin();
	exit(0);
}