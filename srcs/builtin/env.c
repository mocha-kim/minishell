#include "../../includes/builtin.h"

extern t_state	g_state;

int		ft_env()
{
	t_env	*env;
	
	env = g_state.env;
	while (env)
	{
		printf("%s=%s\n", env->name, env->content);
		env = env->next;
	}
	return (0);
}