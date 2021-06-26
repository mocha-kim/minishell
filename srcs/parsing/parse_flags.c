#include "../../includes/parsing.h"

extern t_state	g_state;

int		is_flag(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (TRUE);
	return (FALSE);
}

int		parse_pipe(const char *line, int *end, t_dlist **substr)
{
	if (*end == 0)
	{
		if (g_state.line[*end + 1] == '|')
			return (free_before_exit(substr, ERR_PIPE2));
		return (free_before_exit(substr, ERR_PIPE));
	}
	if (cut_line(line, substr, *end, *end + 1) == EXIT_CODE)
		return (EXIT_CODE);
	return (1);
}

int		parse_lab(const char *line, int *end, t_dlist **substr)
{
	if (g_state.line[*end + 1] == '\0')
		return (free_before_exit(substr, ERR_NEWLINE));
	else if (g_state.line[*end + 1] == '<')
		return (free_before_exit(substr, ERR_LAB));
	if (cut_line(line, substr, *end, *end + 1) == EXIT_CODE)
		return (EXIT_CODE);
	return (1);
}

int		parse_rab(const char *line, int *end, t_dlist **substr)
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
		if (cut_line(line, substr, *end - 1, *end + 1) == EXIT_CODE)
			return (EXIT_CODE);
		}
	}
	else
		if (cut_line(line, substr, *end, *end + 1) == EXIT_CODE)
			return (EXIT_CODE);
	return (1);
}