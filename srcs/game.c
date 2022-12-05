#include "../includes/type.h"

#define DEFINED_KEY 0x19101969

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

void game_timer(pid_t pid)
{
	time_t t;

	t = time(NULL);
	while (time(NULL) - t < 10) {
		//progress bar
	}
	kill(pid, SIGINT);
	exit(0);
}

void game_header() {
	mvaddstr(1, 1, "************************************************************************************");
	mvaddstr(2, 1, "*                                                                                  *");
	mvaddstr(3, 1, "*               TYPING GAME (SEOULTECH UNIX PROGRAMMING PROJECT)                   *");
	mvaddstr(4, 1, "*                                                                                  *");
	mvaddstr(5, 1, "*                                                         developed by Eunbin Kwon *");
	mvaddstr(6, 1, "************************************************************************************");
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
			if (player == 0)
				tmp->color = 0;
			else
				tmp->color = 1;
			break;
		}
		tmp = tmp->next;
	}
	return ;
}

void display_score(word_node *node_list)
{
	int p1_score, p2_score = 0;
	word_node *tmp;

	tmp = node_list;
	while (tmp && tmp->next) {
		if (tmp->color == 0)
			p1_score++;
		else
			p2_score++;
		tmp = tmp->next;
	}

	if (p1_score > p2_score) {
		mvaddstr(35, 35, "PLAYER1 WIN");
		refresh();
	}
	else {
		mvaddstr(35, 35, "PLAYER2 WIN");
		refresh();
	}
	sleep(3);
}

void game()
{

	time_t start, end;
	int msg_qid;
	int player;
	int p1_score, p2_score = 0;
	struct {
		long mtype;
		char input[256];
	} msg;
	word_node *node_list, *tmp;
	struct msqid_ds m_stat;

	start = time(NULL);

	// TODO print remaining time and score

	node_list = make_game_board();

	if ((msg_qid = msgget(DEFINED_KEY, IPC_CREAT | 0666)) < 0) {
		perror("msgget: ");
		exit(-1);
	}

	while (true) {
		memset(msg.input, 0x0, 256);
		if (msgrcv(msg_qid, &msg, 256, 0, 0) < 0) {
			perror("msgrcv: ");
			exit(-1);
		}
		if (strcmp(msg.input, "quit")  == 0) {
			refresh();
			display_score(node_list);
			refresh();
			clear();
			endwin();
			exit(0);
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
		time(&end);
	}
}