#include "../../includes/builtin.h"

void	ft_echo(t_command *cmd)
{
	if (cmd->args != 0)
		write(1, cmd->args, ft_strlen(cmd->args));
	if (cmd->option == 0)
		write(1, "\n", 1);
}