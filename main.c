#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <signal.h>
#include "includes/data.h"
#include "libft/libft.h"

int	g_signal;

// void	ft_echo(t_command *cmd)
// {
// 	int		i;

// 	i = 0;
// 	while (cmd->args && cmd->args[i] != 0)
// 	{
// 		write(1, cmd->args[i], ft_strlen(cmd->args[i]));
// 		i++;
// 	}
// 	if (cmd->option == 0)
// 		write(1, "\n", 1);
// }

void		prompt()
{
	ft_putstr_fd("minishell-", 1);
	ft_putstr_fd("0.0.0", 1);
	ft_putstr_fd("$ ", 1);
}

void		handler(int signo)
{
	if (signo == SIGTERM)
	{
		ft_putstr_fd("exit\n", 2);
		exit(0);
	}
	else
		ft_putstr_fd("\n", 2);
	if (g_signal)
		prompt();
}

int main(int argc, char *argv[], char *envp[])
{
	// struct termios	save;

	// tcgetattr(0, &save);
	// tcsetattr(0, TCSANOW, &save);
	// t_command cmd;
	// cmd.command = ft_strdup("echo");
	// cmd.option = ft_strdup("-n");
	// ft_echo(&cmd);
	// free(cmd.command);
	g_signal = 1;
	while (1)
	{
		signal(SIGTERM, handler);
	}
	return (0);
}
