#include "../../includes/builtin.h"

extern t_state	g_state;

int			ft_cd(t_program *cmd)
{
	char	*pwd;
	char	*oldpwd;

	pwd = 0;
	oldpwd = 0;
	oldpwd = getcwd(oldpwd, 0);
	if (!*(cmd->args[1]) || !ft_strcmp("~", cmd->args[1]))
		chdir(env_search("HOME"));
	else if (ft_strcmp(cmd->args[1], "-") == 0)
		chdir(env_search("OLDPWD"));
	else if (chdir(cmd->args[1]) < 0)
	{
		free(oldpwd);
		print_cd_error(cmd->args[1]);
		g_state.ret = 1;
		return (0);
	}
	env_change("OLDPWD", ft_strdup(oldpwd));
	free(oldpwd);
	pwd = getcwd(pwd, 0);
	env_change("PWD", ft_strdup(pwd));
	free(pwd);
	g_state.ret = 0;
	return (1);
}
