#include "../../includes/builtin.h"

extern t_state	g_state;

void		ft_unset(t_program cmd)
{
	int		i;

	i = 1;
	g_state.ret = 0;
	while (cmd.args[i])
	{
		env_delone(cmd.args[i]);
		i++;
	}
}
