#include "../../includes/parsing.h"

/*
** cut curstr by blank, save to parse
** return 1:succeed 127:exit
*/

int		parse_blank(char *curstr, t_dlist **parse, int *start, int *end)
{
	if (cut_line(curstr, parse, *start, *end) == EXIT_CODE)
		return (EXIT_CODE);
	if (skip_whitespace(curstr, end) > 0)
		(*end)--;
	*start = *end + 1;
	return (1);
}

/*
** parse curstr by semicolon, save to parse
** return 1:succeed 127:exit
*/

int		parse_line_second(int *is_sq_c, int *is_dq_c, char *curstr, t_dlist **parse)
{
	int		start;
	int		end;

	*is_sq_c = TRUE;
	*is_dq_c = TRUE;
	start = 0;
	skip_whitespace(curstr, &start);
	end = start;
	while (curstr[end])
	{
		// printf("curstr[%d] : %c\n", end, curstr[end]);
		if (*is_dq_c && (curstr[end] == '\''))
			*is_sq_c = !(*is_sq_c);
		else if (*is_sq_c && curstr[end] == '\"')
			*is_dq_c = !(*is_dq_c);
		else if (*is_sq_c && *is_dq_c && curstr[end] == ' ')
			if (parse_blank(curstr, parse, &start, &end) == EXIT_CODE)
				return (EXIT_CODE);
		if (curstr[end] == '\0')
			return (cut_line(curstr, parse, start, end));
		if (curstr[end + 1] == '\0')
			return (cut_line(curstr, parse, start, end + 1));
		end++;
	}
	return (0);
}