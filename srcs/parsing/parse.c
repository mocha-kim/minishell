#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** cut line, similar to ft_substtr, save to 
** return 1:succeed 127:exit
*/
int		cut_line(char *str, t_list **save_lst, int start, int end)
{
	char	*tmp;

	// printf("cut %d ~ %d ", start, end);
	if (start != end)
	{
		tmp = ft_substr(str, start, end - start);
		if (!tmp)
			return(print_memory_error(ERR_MALLOC));
		ft_lstadd_back(save_lst, ft_lstnew(tmp));
	}
	// printf("> %s\n", (char *)(ft_lstlast(*save_lst)->content));
	return (1);
}

/*
** save parsed strings to info
** return 1:succeed 127:exit
*/
int		save_command(t_list **info, t_list **parse)
{
	t_list	*tmp;
	int		count;
	int		i;

	tmp = *parse;
	count = 0;
	if (tmp)
	{
		if (!((*info) = malloc(sizeof(t_list))))
			return (print_memory_error(ERR_MALLOC));
		if (!(((*info)->content) = malloc(sizeof(t_command))))
			return (print_memory_error(ERR_MALLOC));
		((t_command *)((*info)->content))->command = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	i = 0;
	tmp = (*parse)->next;
	if (!(((t_command *)((*info)->content))->args = (char **)malloc(sizeof(char *) * (count + 1))))
		return (print_memory_error(ERR_MALLOC));
	while (i < count)
	{
		if (!(((t_command *)((*info)->content))->args[i] = ft_strdup(tmp->content)))
			return (print_memory_error(ERR_MALLOC));
		tmp = tmp->next;
		i++;
	}
	((t_command *)((*info)->content))->args[i] = NULL;
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
	t_list	*tmp2;
	char	**print;
	int		i;

	(void)info;
	substr = NULL;
	is_sq_closed = TRUE;
	is_dq_closed = TRUE;
	// printf(">> first\n");
	if (parse_line_first(&is_sq_closed, &is_dq_closed, &substr) == EXIT_CODE)
		return (EXIT_CODE);
	tmp = substr;
	printf("substr >> ");
	while (tmp)
	{
		printf("%s/", (char *)(tmp->content));
		tmp = tmp->next;
	}
	printf("\n");
	parse = NULL;
	tmp = substr;
	while (tmp)
	{
		is_sq_closed = TRUE;
		is_dq_closed = TRUE;
		if (parse_line_second(&is_sq_closed, &is_dq_closed, (char *)(tmp->content), &parse) == EXIT_CODE)
			return (EXIT_CODE);
		printf("parse >> ");
		tmp2 = parse;
		while (tmp2)
		{
			printf("%s/", (char *)(tmp2->content));
			tmp2 = tmp2->next;
		}
		printf("\n");
		if (save_command(info, &parse) == EXIT_CODE)
			return (EXIT_CODE);
		ft_lstclear(&parse, free);
		printf("info >> command : %s, ", ((t_command *)((*info)->content))->command);
		printf("args : ");
		print = ((t_command *)((*info)->content))->args;
		i = 0;
		while (print[i])
		{
			printf("%s/", print[i]);
			i++;
		}
		printf("\n");
		parse = NULL;
		tmp = tmp->next;
	}
	ft_lstclear(&substr, free);
	substr = NULL;
	return (1);
}