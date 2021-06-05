#include "../includes/minishell.h"

void	free_str(char *str)
{
	free(str);
	str = NULL;
}