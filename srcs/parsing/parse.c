#include "../../includes/parsing.h"

extern t_state	g_state;

int		cut_line(t_list **substr, int start, int end)
{
	char	*tmp;

	printf("cut %d ~ %d\n", start, end);
	if (start != end)
	{
		tmp = ft_substr(g_state.line, start, end - start);
		ft_lstadd_back(substr, ft_lstnew(tmp));
	}
	return (1);
}

/*
** syntax error print
** return 1:succeed 127:exit
*/
int		parse_semicolon(t_list **substr, int *start, int *end)
{
	if (g_state.line[*end + 1] == ';')
	{
		
		return (print_syntax_error(ERR_SEMICOLONE2));
	}
	cut_line(substr, *start, *end);
	(*end)++;
	skip_whitespace(g_state.line, end);
	*start = *end;
	(*end)--;
	return (1);
}

/*
** syntax error print
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
			return (cut_line(substr, start, end));
		if (g_state.line[end + 1] == '\0')
			return (cut_line(substr, start, end + 1));
		end++;
	}
	return (0);
}

int		parse_blank(t_list **parse, t_list **substr)
{
	t_command	*new;

	if (*substr)
	{
		new = malloc(sizeof(t_command));
		new->command = (*substr)->content;
		ft_lstadd_back(parse, ft_lstnew(new));
		// (*info)->cmd.command = (*substr)->content;
		// (*info)->next = NULL;
		(*substr) = (*substr)->next;
	}
	while (*substr)
	{
		if (ft_strncmp(new->command, "echo", 4))
		{
		}
		// (*info)->cmd.args = (*substr)->content;
		(*substr) = (*substr)->next;
	}
	return (1);
}

int		parse_line_second(t_list **parse, int *is_sq_c, int *is_dq_c, t_list **substr)
{
	int		start;
	int		end;

	start = 0;
	skip_whitespace(g_state.line, &start);
	end = start;
	while (g_state.line[end])
	{
		// printf("g_state.line[%d] : %c sq : %d dq : %d\n", end, g_state.line[end], *is_sq_c, *is_dq_c);
		if (*is_dq_c && g_state.line[end] == '\'')
			*is_sq_c = !(*is_sq_c);
		else if (*is_sq_c && g_state.line[end] == '\"')
			*is_dq_c = !(*is_dq_c);
		else if (*is_sq_c && *is_dq_c && g_state.line[end] == ' ')
			parse_blank(parse, substr);
		if (g_state.line[end] == '\0')
			return (cut_line(substr, start, end));
		if (g_state.line[end + 1] == '\0')
			return (cut_line(substr, start, end + 1));
		end++;
	}
	return (0);
}

/*
** parse g_state.line to t_command struct
** return 0:failed(error) 1:succeed 127:exit
*/
int		parse(t_parse **info)
{
	int		is_sq_closed;
	int		is_dq_closed;
	t_list	*substr;
	t_list	*tmp;
	t_list	*parse;

	(void)info;
	substr = NULL;
	parse = NULL;
	is_sq_closed = TRUE;
	is_dq_closed = TRUE;
	if (parse_line_first(&is_sq_closed, &is_dq_closed, &substr) == EXIT_CODE)
		return (EXIT_CODE);
	tmp = substr;
	printf(">> first\n");
	while (tmp)
	{
		printf("%s/", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	// is_sq_closed = TRUE;
	// is_dq_closed = TRUE;
	// parse_line_second(&parse, &is_sq_closed, &is_dq_closed, &substr);
	// tmp = substr;
	// printf(">> second\n", tmp->content);
	// while (tmp)
	// {
	// 	printf("%s/", tmp->content);
	// 	tmp = tmp->next;
	// }
	// printf("\n");
	return (0);
}