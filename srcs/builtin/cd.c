#include "../../includes/builtin.h"
#include <stdio.h>

extern t_state	g_state;

int		ft_cd(t_command *cmd)
{
	char	*pwd;
	char	*oldpwd;

	pwd = 0;
	oldpwd = 0;
	oldpwd = getcwd(oldpwd, 0);
	if (!*(cmd->args) || !ft_strcmp("~", cmd->args[0]))
		chdir(env_search("HOME"));
	else if (ft_strcmp(cmd->args[0], "-") == 0)
		chdir(env_search("OLDPWD"));
	else if (chdir(cmd->args[0]) < 0)
	{
		pwd = strerror(errno);
		ft_putstr_fd(pwd, 2);
		g_state.ret = 1;
		return (0);
	}
	env_change("OLDPWD", ft_strdup(oldpwd));
	pwd = getcwd(pwd, 0);
	env_change("PWD", ft_strdup(pwd));
	g_state.ret = 0;
	return (1);
}
