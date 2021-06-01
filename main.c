#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <sys/errno.h>
#include "includes/data.h"
#include "libft/libft.h"
#include "includes/builtin.h"
#include <string.h>

int main(int argc, char *argv[], char *envp[])
{
	char *line;
	// struct termios	save;

	// tcgetattr(0, &save);
	// tcsetattr(0, TCSANOW, &save);
	if (chdir("/Users/yoahn/test") < 0)
	{
		line = strerror(errno);
		printf("%s\n", line);
	}
	line = getcwd(line, 0);
	printf("%s\n", line);
	line = strerror(errno);
	printf("errno: %d\n", errno);
	printf("%s\n", line);
	// ft_echo(&cmd);
	// free(cmd.command);
	return (0);
}
