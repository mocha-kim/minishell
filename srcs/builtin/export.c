#include "../../includes/builtin.h"

extern t_state	g_state;

static int	find_char(char *str)
{
	int		i;

	i = 0;
	if (str[i] != '_' && !ft_isalpha(str[i]))
		return (-1);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (-1);
		i++;
	}
	return (i);
}

void		print_export(void)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = g_state.env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "?"))
		{
			tmp = tmp->next;
			continue ;
		}
		printf("declare -x %s", tmp->name);
		if (tmp->content)
			printf("=\"%s\"", tmp->content);
		printf("\n");
		tmp = tmp->next;
	}
}

void		ft_export(t_program *cmd)
{
	int		i;
	int		j;
	t_env	*env;

	i = 1;
	g_state.ret = 0;
	if (cmd->argc == 1)
		print_export();
	else
	{
		while (cmd->args[i])
		{
			if ((j = find_char(cmd->args[i])) < 0)
				error_export(cmd->args[i]);
			else if (j > 0)
			{
				if (env_change2(cmd->args[i]) == 0)
				{
					env = env_new(cmd->args[i]);
					env_add(&(g_state.env), env);
				}
			}
			i++;
		}
	}
}
