#include "../../includes/parsing.h"

extern t_state	g_state;

int		free_before_exit(t_dlist **substr, int errnum)
{
	if(g_state.line)
		ft_strdel(&g_state.line);
	if (*substr)
		ft_dlstclear(substr, free);
	return (print_syntax_error(errnum));
}

/*
** cut line by semicolon, save to substr
** return 1:succeed 127:exit
*/
int		parse_flags(const char *line, t_dlist **substr, int *start, int *end)
{
	printf(">> before: %d ~ %d\n", *start, *end);
	if (*end != 0)
	{
		if (cut_line(line, substr, *start, *end) == EXIT_CODE)
			return (EXIT_CODE);
		*start = *end - 1;
	}
	if (line[*end] == '|')
		if (parse_pipe(line, end, substr) == EXIT_CODE)
			return (EXIT_CODE);
	if (line[*end] == '<')
		if (parse_lab(line, end, substr) == EXIT_CODE)
			return (EXIT_CODE);
	if (line[*end] == '>')
		if (parse_rab(line, end, substr) == EXIT_CODE)
			return (EXIT_CODE);
	*start = *end + 1;
	printf(">> after: %d ~ %d\n", *start, *end);
	return (1);
}

/*
** cut line by semicolon, save to substr
** return 1:succeed 127:exit
*/
int		parse_semicolon(const char *line, t_dlist **substr, int *start, int *end)
{
	if (line[*end + 1] == ';')
		return (free_before_exit(substr, ERR_SEMICOLONE2));
	if (cut_line(line, substr, *start, *end) == EXIT_CODE)
		return (EXIT_CODE);
	*start = *end + 1;
	return (1);
}

/*
** parse line by semicolon or flags, save to substr
** return 1:succeed 127:exit
*/
int		parse_line_first(int *is_sq_c, int *is_dq_c, const char *line, t_dlist **substr)
{
	int		start;
	int		end;

	*is_sq_c = TRUE;
	*is_dq_c = TRUE;
	start = 0;
	end = start;
	while (line[end])
	{
		if (*is_dq_c && line[end] == '\'')
			*is_sq_c = !(*is_sq_c);
		else if (*is_sq_c && line[end] == '\"')
			*is_dq_c = !(*is_dq_c);
		else if (*is_sq_c && *is_dq_c && is_flag(line[end]))
		{
			if (parse_flags(line, substr, &start, &end) == EXIT_CODE)
				return (EXIT_CODE);
		}
		else if (*is_sq_c && *is_dq_c && line[end] == ';')
			if (parse_semicolon(line, substr, &start, &end) == EXIT_CODE)
				return (EXIT_CODE);
		end++;
	}
	if (line[end] == '\0')
		return (cut_line(line, substr, start, end));
	return (0);
}