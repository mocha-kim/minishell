#include "../../includes/builtin.h"

extern t_state	g_state;

static void	print_error(char *str)
{
	char	*err;

	ft_putstr_fd("bash: cd: ", STD_ERR);
	ft_putstr_fd(str, STD_ERR);
	ft_putstr_fd(": ", STD_ERR);
	err = strerror(errno);
	ft_putstr_fd(err, STD_ERR);
	write(2, "\n", 1);
}

int			ft_cd(t_program *cmd)
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
		free(oldpwd);
		print_error(cmd->args[0]);
		g_state.ret = 1;
		return (0);
	}
	free(oldpwd);
	env_change("OLDPWD", ft_strdup(oldpwd));
	pwd = getcwd(pwd, 0);
	env_change("PWD", ft_strdup(pwd));
	free(pwd);
	g_state.ret = 0;
	return (1);
}
