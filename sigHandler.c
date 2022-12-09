#include "main.h"

/**
 * sigintHandler - signal handler
 * @sig_num: signal number
 */

void sigintHandler(void)
{
	signal(SIGINT, sigintHandler);
	printf("\n$ ");
	fflush(stdout);
}
