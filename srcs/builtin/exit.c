#include "../../includes/builtin.h"
#include <stdlib.h>

extern t_state	g_state;

static int		is_num(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void			ft_exit(t_program *cmd)
{
	int		i;

	i = 0;
	ft_putstr_fd("exit\n", STD_ERR);
	if (cmd->args != 0)
	{
		while (cmd->args[i])
			i++;
		if (i > 1)
		{
			i = 0;
			if (!is_num(cmd->args[0]))
			{
				print_exit_error(cmd->args[0], 1);
				exit(g_state.ret);
			}
			g_state.ret = 1;
			print_exit_error("bash: exit: too many arguments\n", 2);
			return ;
		}
	}
	exit(g_state.ret);
}
