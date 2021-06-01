#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include "includes/data.h"
#include "libft/libft.h"

void	ft_echo(t_command *cmd)
{
	int		i;

	i = 0;
	while (cmd->args && cmd->args[i] != 0)
	{
		write(1, cmd->args[i], ft_strlen(cmd->args[i]));
		i++;
	}
	if (cmd->option == 0)
		write(1, "\n", 1);
}

int main(int argc, char *argv[], char *envp[])
{
	// struct termios	save;

	// tcgetattr(0, &save);
	// tcsetattr(0, TCSANOW, &save);
	t_command cmd;
	cmd.command = ft_strdup("echo");
	cmd.option = ft_strdup("-n");
	ft_echo(&cmd);
	free(cmd.command);
	return (0);
}
