#include "../../includes/error.h"

int		print_error(int errno)
{
	if (errno == ERR_SYNTAX)
		write(2, "bash: syntax error near unexpected token `;", 43);
}