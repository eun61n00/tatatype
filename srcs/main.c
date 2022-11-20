#include <stdio.h>
#include "../includes/tatatype.h"

int main(void)
{

	int mode;

	printf("Choose game mode \n1. Typing speed test\n2. Typing game\n");
	scanf("%d", &mode);
	if (mode == 1) {
		speed_test();
	}
	return 0;
}