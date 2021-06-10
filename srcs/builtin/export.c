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

void		error_export(char *str)
{
	ft_putstr_fd("bash: export: `", STD_ERR);
	ft_putstr_fd(str, STD_ERR);
	ft_putstr_fd("': not a valid identifier\n", STD_ERR);
	g_state.ret = 1;
}

void		print_export(void)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = g_state.env;
	while (tmp)
	{
		printf("declare -x %s=\"%s\"\n", tmp->name, tmp->content);
		tmp = tmp->next;
	}
}

void		ft_export(t_command *cmd)
{
	int		i;
	int		j;
	t_env	*env;

	i = 0;
	g_state.ret = 0;
	if (cmd->argc == 0)
		print_export();
	else
	{
		while (cmd->args[i])
		{
			if ((j = find_char(cmd->args[i])) < 0)
				error_export(cmd->args[i]);
			else if (j > 0 && cmd->args[i][j] != 0)
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
