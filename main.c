#include <stdio.h>
#include <unistd.h>
#include <termios.h>


int main(int argc, char *argv[], char *envp[])
{
	struct termios	save;

	tcgetattr(0, &save);
	tcsetattr(0, TCSANOW, &save);

	
	return (0);
}
