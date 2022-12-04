#include "../includes/tatatype.h"

word_node *make_game_board() {
	int row, col;
	int word_len, word_cnt;

	int random_number;

	word_node *node_list;

	node_list = make_word_node_list();
	word_node *tmp = node_list;

	row = 12;

	word_cnt = 0;
	while (row < 32) {
		col = 0;
		word_cnt = 0;
		while (word_cnt < 10) {
			mvaddstr(row, col, tmp->string);
			tmp->row = row;
			tmp->col = col;
			refresh();
			word_cnt++;
			col += strlen(tmp->string) + 3;
			tmp = tmp->next;
		}
		row += 2;
	}

	return node_list;
}