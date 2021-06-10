#include "../../includes/parsing.h"

extern t_state	g_state;

int		parse_env(void)
{
	int		is_finished;
	char	*start;
	char	*end;

	is_finished = 0;
	start = ft_strchr(g_state.line, '$');
	while(!is_finished)
	printf("get : %c\n", *start);
	return (1);
}