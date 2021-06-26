#include "../../includes/builtin.h"

extern t_state	g_state;

static int	check_flag(char **args, int *flag)
{
	int		i;

	*flag = 0;
	i = 0;
	if (args && args[1] && args[1][0] == '-')
	{
		i = 1;
		while (args[1][i] && args[1][i] == 'n')
			i++;
		if (args[1][i] && args[1][i] != ' ')
			return (0);
		*flag = 1;
		// while (args[1][i] && args[1][i] == ' ')
		// 	i++;
	}
	return (i);
}

void		ft_echo(t_program *cmd)
{
	int		flag;
	int		i;
	char	*str;

	i = check_flag(cmd->args, &flag);
	if (*cmd->args)
	{
		str = ft_substr(cmd->args[1], i, ft_strlen(cmd->args[1]) - i);
		if (str != 0)
			write(1, str, ft_strlen(str));
		if (flag == 0)
			write(1, "\n", 1);
		g_state.ret = 0;
		free(str);
	}
	else
		write(1, "\n", 1);
}
