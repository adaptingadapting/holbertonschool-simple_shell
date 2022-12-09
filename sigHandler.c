#include "main.h"

/**
 * sigintHandler - signal handler
 * @sig_num: signal number
 */

void sigintHandler(int sig_num)
{
	signal(SIGINT, sigintHandler);
	printf("\n$ ");
	fflush(stdout);
	(void)sig_num;
}
