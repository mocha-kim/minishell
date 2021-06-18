#include "../../includes/error.h"

void	print_cd_error(char *str)
{
	char	*err;

	ft_putstr_fd("bash: cd: ", STD_ERR);
	ft_putstr_fd(str, STD_ERR);
	ft_putstr_fd(": ", STD_ERR);
	err = strerror(errno);
	ft_putstr_fd(err, STD_ERR);
	write(2, "\n", 1);
}