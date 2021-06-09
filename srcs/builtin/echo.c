#include "../../includes/builtin.h"

extern t_state	g_state;

void	ft_echo(t_command *cmd)
{
	if (*cmd->args != 0)
		write(1, *cmd->args, ft_strlen(*cmd->args));
	if (cmd->option == 0)
		write(1, "\n", 1);
	g_state.ret = 0;
}