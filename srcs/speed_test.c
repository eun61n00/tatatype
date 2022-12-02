#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "../includes/tatatype.h"

int calculate_speed(int sec, int char_cnt, int incorrect_cnt) {
	return (char_cnt - incorrect_cnt) * 60 / sec;
}

int incorrect_char(char *test_sentence, char *user_input) {

	int incorrect_cnt = 0;
	int i;
	int test_sentence_len = strlen(test_sentence);

	for (i = 0; i < test_sentence_len; i++) { // for문을 수정해야 함
			printf("%d   ", i);
			printf("%c-%c\n", *test_sentence, *user_input);
			if (*test_sentence != *user_input && user_input) {
					incorrect_cnt++;
			}
			test_sentence++;
			user_input++;
	}

	return incorrect_cnt;
}

void speed_test() {

	int random_number;
	char *test_sentence;
	char *user_input;
	time_t current_time;
	time_t elapse;
	int     speed;
	int incorrect_cnt;

	user_input = (char *)malloc(sizeof(char) * strlen(test_sentence));

	srand(time(NULL));
	random_number = rand() % 100;
	test_sentence = return_random_sentence_en(random_number);

	printf("다음 문장을 입력하세요\n");
	printf("%s\n", test_sentence);

	current_time = time(NULL);
	scanf("%[^\n]s", user_input);
	elapse = time(NULL) - current_time;

	incorrect_cnt = incorrect_char(test_sentence, user_input);
	printf("test_sentece: %d, incorrect_cnt: %d\n", strlen(test_sentence), incorrect_cnt);

	speed = calculate_speed(elapse, strlen(test_sentence), incorrect_cnt);
	printf("타수: %d타\n", speed);

	exit(0);

}