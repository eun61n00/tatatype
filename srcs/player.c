#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "../includes/type.h"

#define DEFINED_KEY 0x19101969

int main(int argc, char *argv[])
{
	int msg_qid;
	struct {
		long mtype;
		char input[256];
	} msg;

	fprintf(stdout, "========== Player ==========\n");
	if ((msg_qid = msgget(DEFINED_KEY, IPC_CREAT | 0666)) < 0) {
		perror("msgget: ");
		exit(-1);
	}

	msg.mtype = 1;
	while (TRUE) {
		memset(msg.input, 0x0, 256);
		gets(msg.input);
		if (msgsnd(msg_qid, &msg, sizeof(msg.input), 0) < 0) {
			perror("msgsnd: ");
			exit(-1);
		}
	}
}