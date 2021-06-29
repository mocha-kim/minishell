#include "../../includes/env.h"

extern t_state	g_state;

static char	*envp_join(char *name, char *cont)
{
	char	*str;
	char	*tmp;

	str = ft_strjoin(name, "=");
	tmp = ft_strjoin(str, cont);
	free(str);
	return (tmp);
}

char		**make_envp(void)
{
	char	**res;
	int		i;
	int		len;
	t_env	*env;

	i = 0;
	len = env_cnt();
	if (!(res = malloc(sizeof(char *) * (len + 1))))
		return (0);
	env = g_state.env;
	while (i < len)
	{
		if (!ft_strcmp("?", env->name))
		{
			env = env->next;
			continue ;
		}
		res[i] = envp_join(env->name, env->content);
		env = env->next;
		i++;
	}
	res[i] = 0;
	return (res);
}

int			env_cnt(void)
{
	int		i;
	t_env	*tmp;

	tmp = g_state.env;
	i = 0;
	while (tmp)
	{
		if (!ft_strcmp("?", tmp->name))
		{
			tmp = tmp->next;
			continue ;
		}
		i++;
		tmp = tmp->next;
	}
	return (i);
}
