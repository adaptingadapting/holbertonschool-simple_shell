#include "main.h"

/**
 * free4 - frees 4 strings
 * @str1: string
 * @str2: string2
 * @str3: string3
 * @s: stringy
 */

void free4(char *str1, char *str2, char *str3, char *s)
{
	free(str1);
	free(str2);
	free(str3);
	free(s);
}
