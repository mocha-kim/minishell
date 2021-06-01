#include "../../includes/error.h"

/*
** syntax error print
** return 0:failed 1:succeed 
*/
int		print_syntax_error(int errno)
{
	if (errno == ERR_QUOTE)
		write(2, "bash: syntax error quote not closed", 43);
	if (errno == ERR_SEMICOLONE)
		write(2, "bash: syntax error near unexpected token `;'", 45);
	if (errno == ERR_SEMICOLONE2)
		write(2, "bash: syntax error near unexpected token `;;'", 46);
	if (errno == ERR_PIPE)
		write(2, "bash: syntax error near unexpected token `|'", 45);
	if (errno == ERR_PIPE2)
		write(2, "bash: syntax error near unexpected token `||'", 46);
	else
		return (0);
	return (1);
}