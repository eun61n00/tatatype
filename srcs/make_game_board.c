#include "../includes/tatatype.h"

word_node *make_game_board() {
	int row, col;
	int word_len, word_cnt;

	int random_number;

	word_node *node_list;

	node_list = make_word_node_list();
	word_node *tmp = node_list;

	row = 10;

	word_cnt = 0;
	while (row < 30) {
		col = 1;
		word_cnt = 0;
		while (word_cnt < 10) {
			if (word_cnt % 2 == 0) {
				attroff(COLOR_PAIR(0));
				attron(COLOR_PAIR(1) | A_BOLD);
				tmp->color = 1;
			} else {
				attroff(COLOR_PAIR(1));
				attron(COLOR_PAIR(0) | A_BOLD);
				tmp->color = 0;
			}
			mvaddstr(row, col, tmp->string);
			tmp->row = row;
			tmp->col = col;
			refresh();
			word_cnt++;
			col += strlen(tmp->string) + 3;
			tmp = tmp->next;
			if (row == 28 && word_cnt == 9)
				break;
		}
		row += 2;
	}

	return node_list;
}