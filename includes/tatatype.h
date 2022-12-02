#ifndef TATATYPE_H
# define TATATYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <curses.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

void speed_test();
void game();
char *return_random_sentence_ko(int idx);
char *return_random_sentence_en(int idx);

#endif