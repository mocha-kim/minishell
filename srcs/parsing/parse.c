#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** save parsed strings to info
** return 1:succeed 127:exit
*/

int		save_cmd(t_command **new, t_list **tmp)
{
	if (*tmp)
	{
		if (!((*new) = malloc(sizeof(t_command))))
			return (print_memory_error(ERR_MALLOC));
		(*new)->command = ft_strdup((*tmp)->content);
		(*new)->args = NULL;
		*tmp = (*tmp)->next;
	}
	return (1);
}

/*
** save parsed strings to info
** return 1:succeed 127:exit
*/

int		save_args(t_command **new, t_list **tmp, t_list **parse, int count)
{
	int		i;

	i = 0;
	*tmp = (*parse)->next;
	if (!((*new)->args = (char **)malloc(sizeof(char *) * (count + 1))))
		return (print_memory_error(ERR_MALLOC));
	while (i < count)
	{
		if (!((*new)->args[i] = ft_strdup((*tmp)->content)))
			return (print_memory_error(ERR_MALLOC));
		*tmp = (*tmp)->next;
		i++;
	}
	(*new)->args[i] = NULL;
	return (1);
}

/*
** save parsed strings to info
** return 1:succeed 127:exit
*/

int		save_parse(t_list **info, t_list **parse)
{
	t_list		*tmp;
	t_command	*new;
	int			count;

	del_quote(parse);
	tmp = *parse;
	count = 0;
	save_cmd(&new, &tmp);
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	new->argc = count;
	save_args(&new, &tmp, parse, count);
	ft_lstadd_back(info, ft_lstnew(new));
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
	char	**print;
	int		i;

	substr = NULL;
	if (parse_line_first(&is_sq_closed, &is_dq_closed, &substr) == EXIT_CODE)
		return (EXIT_CODE);
	parse = NULL;
	tmp = substr;
	while (tmp)
	{
		if (parse_line_second(&is_sq_closed, &is_dq_closed, (char *)(tmp->content), &parse) == EXIT_CODE)
			return (EXIT_CODE);
		if (save_parse(info, &parse) == EXIT_CODE)
			return (EXIT_CODE);
		ft_lstclear(&parse, free);
		parse = NULL;
		tmp = tmp->next;
	}
	ft_lstclear(&substr, free);
	substr = NULL;
	tmp = *info;
	while (tmp)
	{
		printf("info >> command : %s, ", ((t_command *)(tmp->content))->command);
		printf("args : ");
		print = ((t_command *)(tmp->content))->args;
		i = 0;
		while (print[i])
		{
			printf("%s/", print[i]);
			i++;
		}
		printf("\n");
		tmp = tmp->next;
	}
	return (1);
}