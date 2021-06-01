#include "../../includes/builtin.h"

int		ft_cd(t_command *cmd)
{
	char	*path;
	int		i;
	int		quote;
	
	i = 0;
	while (cmd->args[i] && cmd->args[i] == ' ')
		i++;
	while (cmd->args[i])
	// 공백, quote 파싱해서 앞에 경로만 chdir
	// if (cmd->args == 0)
	chdir(cmd->args)
}