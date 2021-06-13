#include "../../includes/builtin.h"

extern t_state	g_state;

void		ft_unset(t_command cmd)
{
	// t_env	*env;
	int		i;

	i = 0;
	g_state.ret = 0;
	// env = g_state.env;
	if (cmd.args == 0)
		return ;
	while (cmd.args[i])
	{
		env_delone(cmd.args[i]);
		i++;
	}
}
