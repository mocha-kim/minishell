#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <signal.h>
#include "includes/data.h"
#include "libft/libft.h"
#include <sys/errno.h>
#include "includes/env.h"

int main(int argc, char *argv[], char *envp[])
{
	int	i = 0;
	int j = 0;

	i = !j;
	printf("i: %d, j: %d\n", i, j);
	j = 1;
	i = !j;
	printf("i: %d, j: %d\n", i, j);
	return (0);
}
