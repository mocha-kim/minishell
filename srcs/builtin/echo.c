#include "../../includes/builtin.h"

extern t_state	g_state;

static int	check_flag(char **args, int *flag)
{
	int		i;

	*flag = 0;
	i = 0;
	if (args && *args && !ft_strncmp(*args, "-n", 2))
	{
		*flag = 1;
		i = 2;
		while (args[0][i] && args[0][i] == 'n')
			i++;
		if (args[0][i] && args[0][i] != ' ')
			return (0);
		while (args[0][i] && args[0][i] == ' ')
			i++;
	}
	return (i);
}

void		ft_echo(t_command *cmd)
{
	int		flag;
	int		i;
	char	*str;

	i = check_flag(cmd->args, &flag);
	if (*cmd->args)
	{
		str = ft_substr(cmd->args[0], i, ft_strlen(cmd->args[0]) - i);
		if (str != 0)
			write(1, str, ft_strlen(str));
		if (flag == 0)
			write(1, "\n", 1);
		g_state.ret = 0;
		free(str);
	}
}
