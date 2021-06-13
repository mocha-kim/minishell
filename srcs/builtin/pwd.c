#include "../../includes/builtin.h"

extern t_state	g_state;

void	ft_pwd(void)
{
	char	*line;

	g_state.ret = 0;
	line = 0;
	line = getcwd(line, 0);
	ft_putstr_fd(line, 1);
	write(1, "\n", 1);
	free(line);
	g_state.ret = 0;
}
