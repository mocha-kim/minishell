#include "../../includes/parsing.h"

extern t_state	g_state;

void	cut_line(t_list **substr, int start, int end)
{
	char	*tmp;

	printf("cut %d ~ %d\n", start, end);
	if (start != end)
	{
		tmp = ft_substr(g_state.line, start, end - start);
		ft_lstadd_back(substr, ft_lstnew(tmp));
	}
}

void	parse_blank(t_list **substr, int *start, int *end)
{
	cut_line(substr, *start, *end);
	skip_whitespace(g_state.line, end);
	*start = *end;
	(*end)--;
}

void	parse_semicolon()
{

}

void	parse_line(int *is_sq_c, int *is_dq_c, t_list **substr)
{
	int		start;
	int		end;

	start = 0;
	skip_whitespace(g_state.line, &start);
	end = start;
	while (g_state.line[end])
	{
		printf("g_state.line[%d] : %c sq : %d dq : %d\n", end, g_state.line[end], *is_sq_c, *is_dq_c);
		if (*is_dq_c && g_state.line[end] == '\'')
			*is_sq_c = !(*is_sq_c);
		else if (*is_sq_c && g_state.line[end] == '\"')
			*is_dq_c = !(*is_dq_c);
		else if (*is_sq_c && *is_dq_c && g_state.line[end] == ';')
			parse_semicolon();
		else if (*is_sq_c && *is_dq_c && g_state.line[end] == ' ')
			parse_blank(substr, &start, &end);
		if (g_state.line[end] == '\0')
			return (cut_line(substr, start, end));
		if (g_state.line[end + 1] == '\0')
			return (cut_line(substr, start, end + 1));
		end++;
	}
}

/*
** parse g_state.line to t_command struct
** return 0:failed(error) 1:succeed 
*/
int		parse(t_parse **info)
{
	int		is_sq_closed;
	int		is_dq_closed;
	t_list	*substr;
	t_list	*tmp;

	(void)info;
	is_sq_closed = TRUE;
	is_dq_closed = TRUE;
	substr = NULL;
	parse_line(&is_sq_closed, &is_dq_closed, &substr);
	// parse_semicolon();
	// (*info)->cmd.command = substr->content;
	tmp = substr;
	while (tmp)
	{
		printf("%s/", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	return (0);
}