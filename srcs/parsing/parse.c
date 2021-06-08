#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** cut line by semicolon
** return 1:succeed 127:exit
*/
int		cut_line(char *str, t_list **substr, int start, int end)
{
	char	*tmp;

	printf("cut %d ~ %d ", start, end);
	if (start != end)
	{
		tmp = ft_substr(str, start, end - start);
		if (!tmp)
			return(print_memory_error(ERR_MALLOC));
		ft_lstadd_back(substr, ft_lstnew(tmp));
	}
		printf("> %s\n", (char *)(ft_lstlast(*substr)->content));
	return (1);
}

/*
** cut line by semicolon
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

/*
** cut curstr by blank, save to parse
** return 1:succeed 127:exit
*/
int		parse_blank(char *curstr, t_list **parse, int *start, int *end)
{
	if (cut_line(curstr, parse, *start, *end) == EXIT_CODE)
		return (EXIT_CODE);
	skip_whitespace(g_state.line, end);
	*start = *end;
	(*end)--;
	return (1);
}

int		parse_line_second(int *is_sq_c, int *is_dq_c, char *curstr, t_list **parse)
{
	int		start;
	int		end;

	start = 0;
	skip_whitespace(curstr, &start);
	end = start;
	while (curstr[end])
	{
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

/*
** save parsed strings to info
** return 1:succeed 127:exit
*/
int		save_command(t_list **info, t_list **parse)
{
	t_list	*tmp;

	tmp = *parse;
	while (tmp)
	{
		((t_command *)((*info)->content))->command = (*parse)->content;
	}
	return (1);
}

/*
** parse g_state.line to info
** return 0:failed(error) 1:succeed 127:exit
*/
int		parse(t_list **info)
{
	int		is_sq_closed;
	int		is_dq_closed;
	t_list	*substr;
	t_list	*parse;
	t_list	*tmp;

	(void)info;
	substr = NULL;
	is_sq_closed = TRUE;
	is_dq_closed = TRUE;
	// printf(">> first\n");
	if (parse_line_first(&is_sq_closed, &is_dq_closed, &substr) == EXIT_CODE)
		return (EXIT_CODE);
	tmp = substr;
	// printf("substr : ");
	// while (tmp)
	// {
	// 	printf("%s/", tmp->content);
	// 	tmp = tmp->next;
	// }
	// printf("\n");
	tmp = substr;
	while (tmp)
	{
		parse = NULL;
		is_sq_closed = TRUE;
		is_dq_closed = TRUE;
		if (parse_line_second(&is_sq_closed, &is_dq_closed, (char *)(tmp->content), &parse) == EXIT_CODE)
			return (EXIT_CODE);
		// if (save_command(info, &parse) == EXIT_CODE)
		// 	return (EXIT_CODE);
		ft_lstclear(parse, free);
		tmp = tmp->next;
	}
	ft_lstclear(substr, free);
	return (0);
}