#include "../../includes/builtin.h"

extern t_state	g_state;

static int	check_flag(char **args, int *flag)
{
	int		i;

	*flag = 0;
	i = 1;
	if (args && args[1] && args[1][0] == '-')
	{
		while (args[i] && !ft_strncmp(args[i], "-n", 2))
			i++;
		*flag = 1;
	}
	return (i);
}

void		ft_echo(t_program *cmd)
{
	int		flag;
	int		i;

	i = check_flag(cmd->args, &flag);
	printf("%s\n", cmd->args[1]);
	if (i != 0 || cmd->argc > 1)
	{
		if (i < cmd->argc)
			printf("%s", cmd->args[i++]);
		while (i < cmd->argc)
		{
			printf(" %s", cmd->args[i]);
			i++;
		}
		if (flag == 0)
			printf("\n");
	}
	else
		write(1, "\n", 1);
	g_state.ret = 0;
}
