#include "../../includes/parsing.h"

/*
** cut curstr by blank, save to parse
** return 1:succeed 127:exit
*/
int		parse_blank(char *curstr, t_list **parse, int *start, int *end)
{
	if (cut_line(curstr, parse, *start, *end) == EXIT_CODE)
		return (EXIT_CODE);
	skip_whitespace(curstr, end);
	*start = *end;
	if (!ft_strcmp((*parse)->content, "echo"))
		*end += ft_strlen(curstr) - *end - 1;
	(*end)--;
	return (1);
}

/*
** parse curstr by semicolon, save to parse
** return 1:succeed 127:exit
*/
int		parse_line_second(int *is_sq_c, int *is_dq_c, char *curstr, t_list **parse)
{
	int		start;
	int		end;

	start = 0;
	skip_whitespace(curstr, &start);
	end = start;
	while (curstr[end])
	{
		// printf("> %d : %c, sq: %d, dq: %d\n", end, curstr[end], *is_sq_c, *is_dq_c);
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