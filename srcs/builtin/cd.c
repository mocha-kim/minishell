#include "../../includes/builtin.h"

int		ft_cd(t_command *cmd)
{
	(void)cmd;
	// char	*line;
	// int		i;
	
	// i = 0;
	// while (*(cmd->args) && *(cmd->args) == ' ')
	// 	cmd->args++;
	// if (*(cmd->args) == 0)
	// {
	// 	chdir("/Users/");
	// 	// user 홈 디렉토리로 이동
	// 	return (1);
	// }
	// while (cmd->args[i] && cmd->args[i] != ' ')
	// 	i++;
	// cmd->args[i] = 0;
	// // 공백, quote 파싱해서 앞에 경로만 chdir
	// // if (cmd->args == 0)
	// if (chdir(cmd->args) < 0)
	// {
	// 	line = strerror(errno);
	// 	ft_putstr_fd(line, 2);
	// }
	return (1);
}