#include "../../includes/parsing.h"

extern t_state	g_state;

void	cut_line(t_list **substr, int start, int end)
{
	char	*tmp;

	tmp = ft_substr(g_state.line, start, end - start);
	ft_lstadd_back(substr, ft_lstnew(tmp));
}

void	parse_blank(int *is_quote_closed, t_list **substr)
{
	int		start;
	int		end;

	start = 0;
	skip_whitespace(g_state.line, &start);
	end = start;
	while (g_state.line[end])
	{
		if (g_state.line[end] == '\'' || g_state.line[end] == '\"')
			*is_quote_closed = !(*is_quote_closed);
		else if (*is_quote_closed && g_state.line[end] == ' ')
		{
			cut_line(substr, start, end);
			skip_whitespace(g_state.line, &end);
			start = end;
			continue ;
		}
		if (*is_quote_closed && g_state.line[end + 1] == '\0')
		{
			printf("in\n");
			cut_line(substr, start, end + 1);
			break ;
		}
		end++;
	}
}

void	parse_semicolon()
{

}

/*
** parse g_state.line to t_command struct
** return 0:failed(error) 1:succeed 
*/
int		parse_line(t_parse **info)
{
	int		is_quote_closed;
	t_list	*substr;
	t_list	*tmp;

	(void)info;
	is_quote_closed = TRUE;
	substr = NULL;
	parse_blank(&is_quote_closed, &substr);
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