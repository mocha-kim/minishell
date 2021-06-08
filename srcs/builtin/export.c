#include "../../includes/builtin.h"

extern t_state	g_state;

void	ft_export(t_command *cmd)
{
	int		i;

	i = 0;
	g_state.ret = 0;
	while (cmd->args[i])
	{
		env_add(&g_state.env, env_new(cmd->args[i]));
		i++;
	}
}