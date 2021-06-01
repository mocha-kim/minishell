#include "../../includes/minishell.h"

void	ft_echo(t_command *cmd)
{
	int		i;

	i = 0;
	while (cmd->args[i] != 0)
	{
		write(1, cmd->args[i], ft_strlen(cmd->args[i]));
		i++;
	}
	if (cmd->option == 0)
		write(1, "\n", 1);
}