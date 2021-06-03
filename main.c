#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <signal.h>
#include "includes/data.h"
#include "libft/libft.h"
#include <sys/errno.h>

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
	char *line;
	// struct termios	save;

	// tcgetattr(0, &save);
	// tcsetattr(0, TCSANOW, &save);
	// char *path = ft_strdup("/Users / ");
	// path[6] = 0;
	// if (chdir(path) < 0)
	// {
	// 	line = strerror(errno);
	// 	printf("error: %s\n", line);
	// }
	// free(path);
	// line = getcwd(line, 0);
	// printf("%s\n", line);
	// line = strerror(errno);
	// printf("errno: %d\n", errno);
	// printf("%s\n", line);

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
	char *path = ft_strdup("/Users / ");
	path[6] = 0;
	if (chdir(path) < 0)
	{
		line = strerror(errno);
		printf("error: %s\n", line);
	}
	line = getcwd(line, 0);
	printf("%s\n", line);
	// ft_echo(&cmd);
	// free(cmd.command);
	return (0);
}
