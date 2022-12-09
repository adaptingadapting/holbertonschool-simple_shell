#include "main.h"

/**
 * sigintHandler - signal handler
 * @sig_num: signal number
 */

void sigintHandler()
{
	signal(SIGINT, sigintHandler);
	printf("\n$ ");
	fflush(stdout);
}
