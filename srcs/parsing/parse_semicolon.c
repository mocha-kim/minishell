#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** cut line by semicolon, save to substr
** return 1:succeed 127:exit
*/
int		parse_semicolon(t_list **substr, int *start, int *end)
{
	if (g_state.line[*end + 1] == ';')
	{
		if(g_state.line)
			ft_strdel(&g_state.line);
		return (print_syntax_error(ERR_SEMICOLONE2));
	}
	if (cut_line(g_state.line, substr, *start, *end) == EXIT_CODE)
		return (EXIT_CODE);
	(*end)++;
	skip_whitespace(g_state.line, end);
	*start = *end;
	(*end)--;
	return (1);
}

/*
** parse line by semicolon, save to substr
** return 1:succeed 127:exit
*/
int		parse_line_first(int *is_sq_c, int *is_dq_c, t_list **substr)
{
	int		start;
	int		end;

	start = 0;
	skip_whitespace(g_state.line, &start);
	end = start;
	while (g_state.line[end])
	{
		if (*is_dq_c && g_state.line[end] == '\'')
			*is_sq_c = !(*is_sq_c);
		else if (*is_sq_c && g_state.line[end] == '\"')
			*is_dq_c = !(*is_dq_c);
		else if (*is_sq_c && *is_dq_c && g_state.line[end] == ';')
			if (parse_semicolon(substr, &start, &end) == EXIT_CODE)
				return (EXIT_CODE);
		if (g_state.line[end] == '\0')
			return (cut_line(g_state.line, substr, start, end));
		if (g_state.line[end + 1] == '\0')
			return (cut_line(g_state.line, substr, start, end + 1));
		end++;
	}
	return (0);
}