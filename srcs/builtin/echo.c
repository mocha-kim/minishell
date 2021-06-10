#include "../../includes/builtin.h"

extern t_state	g_state;

void	ft_echo(t_command *cmd)
{
	int		flag;
	int		i;
	char	*str;

	printf("-----ft_echo-----\n");
	printf("cmd->args: %s\n", cmd->args[0]);
	flag = 0;
	i = 0;
	if (cmd->args && cmd->args[0]
	&& !ft_strncmp(cmd->args[0], "-n", 2))
	{
		flag = 1;
		i = 2;
		while (cmd->args[0][i] && cmd->args[0][i] == 'n')
			i++;
		if (cmd->args[0][i] && cmd->args[0][i] != ' ')
			i = 0;
		while (cmd->args[0][i] && cmd->args[0][i] == ' ')
			i++;
	}
	if (*cmd->args)
	{
		str = ft_substr(cmd->args[0], i, ft_strlen(cmd->args[0]) - i);
		if (str != 0)
			write(1, str, ft_strlen(str));
		if (cmd->flag == 0)
			write(1, "\n", 1);
		g_state.ret = 0;
		free(str);
	}
	printf("--------------\n");
}