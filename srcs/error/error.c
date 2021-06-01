#include "../../includes/error.h"

/*
** syntax error print
** return 0:failed 127:succeed 
*/
int		print_syntax_error(int errno)
{
	if (errno == ERR_QUOTE)
		write(2, "bash: syntax error quote not closed\n", 37);
	if (errno == ERR_SEMICOLONE)
		write(2, "bash: syntax error near unexpected token `;'\n", 46);
	if (errno == ERR_SEMICOLONE2)
		write(2, "bash: syntax error near unexpected token `;;'\n", 47);
	if (errno == ERR_PIPE)
		write(2, "bash: syntax error near unexpected token `|'\n", 46);
	if (errno == ERR_PIPE2)
		write(2, "bash: syntax error near unexpected token `||'\n", 47);
	else
		return (0);
	return (EXIT_CODE);
}