/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:33:12 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/07 19:33:14 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

extern t_state	g_state;

static char	*target_dir(t_program *cmd, int *code)
{
	char	*str;

	if (cmd->argc == 1 || !ft_strcmp("~", cmd->args[1]))
	{
		str = env_search("HOME");
		if (!(ft_strcmp("", str)))
		{
			free(str);
			*code = 1;
			return (0);
		}
	}
	else if (ft_strcmp(cmd->args[1], "-") == 0)
	{
		str = env_search("OLDPWD");
		if (str)
			printf("%s\n", str);
	}
	else
		str = ft_strdup(cmd->args[1]);
	return (str);
}

int			ft_cd(t_program *cmd)
{
	char	*pwd;
	char	*oldpwd;
	char	*str;
	int		code;

	pwd = 0;
	oldpwd = 0;
	oldpwd = getcwd(oldpwd, 0);
	code = 0;
	str = target_dir(cmd, &code);
	if (chdir(str) < 0)
	{
		free(oldpwd);
		print_cd_error(str, code);
		g_state.ret = 1;
		return (0);
	}
	free(str);
	env_change("OLDPWD", ft_strdup(oldpwd));
	free(oldpwd);
	pwd = getcwd(pwd, 0);
	env_change("PWD", ft_strdup(pwd));
	free(pwd);
	g_state.ret = 0;
	return (1);
}
