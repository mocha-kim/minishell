#include "../../includes/error.h"

/*
** syntax error print
** return 0:failed 127:succeed(exit)
*/
int		print_syntax_error(int errno)
{
	if (errno == ERR_QUOTE)
		ft_putstr_fd("bash: syntax error quote not closed\n", STD_ERR);
	else if (errno == ERR_SEMICOLONE)
		ft_putstr_fd("bash: syntax error near unexpected token `;'\n", STD_ERR);
	else if (errno == ERR_SEMICOLONE2)
		ft_putstr_fd("bash: syntax error near unexpected token `;;'\n", STD_ERR);
	else if (errno == ERR_PIPE)
		ft_putstr_fd("bash: syntax error near unexpected token `|'\n", STD_ERR);
	else if (errno == ERR_PIPE2)
		ft_putstr_fd("bash: syntax error near unexpected token `||'\n", STD_ERR);
	else
		return (0);
	return (EXIT_CODE);
}

int		print_memory_error(int errno)
{
	if (errno == ERR_MALLOC)
		ft_putstr_fd("bash: failed to allocate memory.\n", STD_ERR);
	else
		return (0);
	return (EXIT_CODE);
}