#include "../../includes/builtin.h"

void	ft_pwd(void)
{
	char	*line;

	line = 0;
	line = getcwd(line, 0);
	ft_putstr_fd(line, 1);
}