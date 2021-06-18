#include "../../includes/parsing.h"

extern t_state	g_state;

int		is_flag(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (TRUE);
	return (FALSE);
}

int		parse_pipe(int *end, t_dlist **substr)
{
	if (*end == 0)
	{
		if (g_state.line[*end + 1] == '|')
			return (free_before_exit(substr, ERR_PIPE2));
		return (free_before_exit(substr, ERR_PIPE));
	}
	return (1);
}

int		parse_lab(int *end, t_dlist **substr)
{
	if (g_state.line[*end + 1] == '\0')
		return (free_before_exit(substr, ERR_NEWLINE));
	else if (g_state.line[*end + 1] == '<')
		return (free_before_exit(substr, ERR_LAB));
	return (1);
}

int		parse_rab(int *end, t_dlist **substr)
{
	if (g_state.line[*end + 1] == '\0')
		return (free_before_exit(substr, ERR_NEWLINE));
	else if (g_state.line[*end + 1] == '>')
	{
		if (g_state.line[*end + 1] == '\0')
			return (free_before_exit(substr, ERR_NEWLINE));
		else if (g_state.line[*end + 1] == '>')
		{
			(*end)++;
			if (g_state.line[*end + 1] == '\0')
				return (free_before_exit(substr, ERR_NEWLINE));
			else if (g_state.line[*end + 1] == '>')
			{
				if (g_state.line[*end + 2] == '>')
					return (free_before_exit(substr, ERR_RAB2));
				return (free_before_exit(substr, ERR_RAB));
			}
		}
	}
	return (1);
}