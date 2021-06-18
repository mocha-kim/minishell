#include "../../includes/parsing.h"

extern t_state	g_state;

int		free_before_exit(t_dlist **substr, int errno)
{
	if(g_state.line)
		ft_strdel(&g_state.line);
	if (*substr)
		ft_dlstclear(substr, free);
	return (print_syntax_error(errno));
}

/*
** cut line by semicolon, save to substr
** return 1:succeed 127:exit
*/
int		parse_flags(t_dlist **substr, int *start, int *end)
{
	if (*end != 0)
	{
		if (cut_line(g_state.line, substr, *start, *end) == EXIT_CODE)
			return (EXIT_CODE);
		*start = *end - 1;
	}
	if (g_state.line[*end] == '|')
		if (parse_pipe(end, substr) == EXIT_CODE)
			return (EXIT_CODE);
	if (g_state.line[*end] == '<')
		if (parse_lab(end, substr) == EXIT_CODE)
			return (EXIT_CODE);
	if (g_state.line[*end] == '>')
		if (parse_rab(end, substr) == EXIT_CODE)
			return (EXIT_CODE);
	printf("end : %d(%c)\n", *end, g_state.line[*end]);
	if (cut_line(g_state.line, substr, *start, *end + 1) == EXIT_CODE)
		return (EXIT_CODE);
	*start = *end + 1;
	return (1);
}

/*
** cut line by semicolon, save to substr
** return 1:succeed 127:exit
*/
int		parse_semicolon(t_dlist **substr, int *start, int *end)
{
	if (g_state.line[*end + 1] == ';')
		return (free_before_exit(substr, ERR_SEMICOLONE2));
	if (cut_line(g_state.line, substr, *start, *end) == EXIT_CODE)
		return (EXIT_CODE);
	*start = *end + 1;
	return (1);
}

/*
** parse line by semicolon or flags, save to substr
** return 1:succeed 127:exit
*/
int		parse_line_first(int *is_sq_c, int *is_dq_c, t_dlist **substr)
{
	int		start;
	int		end;

	*is_sq_c = TRUE;
	*is_dq_c = TRUE;
	start = 0;
	end = start;
	while (g_state.line[end])
	{
		if (g_state.line[end] == '\0')
			return (cut_line(g_state.line, substr, start, end));
		if (*is_dq_c && g_state.line[end] == '\'')
			*is_sq_c = !(*is_sq_c);
		else if (*is_sq_c && g_state.line[end] == '\"')
			*is_dq_c = !(*is_dq_c);
		else if (*is_sq_c && *is_dq_c && is_flag(g_state.line[end]))
		{
			if (parse_flags(substr, &start, &end) == EXIT_CODE)
				return (EXIT_CODE);
		}
		else if (*is_sq_c && *is_dq_c && g_state.line[end] == ';')
			if (parse_semicolon(substr, &start, &end) == EXIT_CODE)
				return (EXIT_CODE);
		end++;
	}
	return (0);
}