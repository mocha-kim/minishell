#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** save parsed strings to info
** return 1:succeed 127:exit
*/

int		init_program(t_program **new, t_dlist **tmp)
{
	if (*tmp)
	{
		if (!((*new) = malloc(sizeof(t_program))))
			return (print_memory_error(ERR_MALLOC));
		(*new)->args = NULL;
		(*new)->argc = 0;
		(*new)->flag = 0;
	}
	return (1);
}

/*
** save parsed strings to info
** return 1:succeed 127:exit
*/

int		save_args(t_program **new, t_dlist **tmp, t_dlist **parse, int count)
{
	int		i;

	i = 0;
	*tmp = *parse;
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

void	save_flag(t_dlist **programs)
{
	t_program	*tmp;

	tmp = ft_dlstlast(*programs)->content;
	tmp->flag = F_PIPE;
}

/*
** save parsed strings to info
** return 1:succeed 127:exit
*/

int		save_parse(t_dlist **programs, t_dlist **parse)
{
	t_dlist		*tmp;
	t_program	*new;
	int			count;

	tmp = *parse;
	if (tmp)
	{
		printf(">>>> %s\n", tmp->content);
		if (((char *)(tmp->content))[0] == '|')
			save_flag(programs);
		else
		{
			del_quote(parse);
			tmp = *parse;
			count = 0;
			init_program(&new, &tmp);
			while (tmp)
			{
				count++;
				tmp = tmp->next;
			}
			new->argc = count;
			save_args(&new, &tmp, parse, count);
			ft_dlstadd_back(programs, ft_dlstnew(new));
		}
	}
	return (1);
}

/*
** parse g_state.line to info
** return 0:failed(error) 1:succeed 127:exit
*/

int		parse(t_dlist **programs, char *line)
{
	int		is_sq_closed;
	int		is_dq_closed;
	t_dlist	*substr;
	t_dlist	*parse;
	t_dlist	*tmp;
	char	**print;
	int		i;

	substr = NULL;
	if (parse_line_first(&is_sq_closed, &is_dq_closed, line, &substr) == EXIT_CODE)
		return (EXIT_CODE);
	parse = NULL;
	tmp = substr;
	while (tmp)
	{
		if (((char *)(tmp->content))[0] == '|')
			parse = ft_dlstnew(ft_strdup(tmp->content));
		else
			if (parse_line_second(&is_sq_closed, &is_dq_closed, (char *)(tmp->content), &parse) == EXIT_CODE)
				return (EXIT_CODE);
		if (save_parse(programs, &parse) == EXIT_CODE)
			return (EXIT_CODE);
		ft_dlstclear(&parse, free);
		parse = NULL;
		tmp = tmp->next;
	}
	ft_dlstclear(&substr, free);
	substr = NULL;
	tmp = *programs;
	printf("============program============\n");
	while (tmp)
	{
		printf("flag : %d, argc : %d, ", ((t_program *)(tmp->content))->flag, ((t_program *)(tmp->content))->argc);
		printf("args : ");
		print = ((t_program *)(tmp->content))->args;
		i = 0;
		while (print[i])
		{
			printf("%s/", print[i]);
			i++;
		}
		printf("\n");
		tmp = tmp->next;
	}
	printf("===============================\n");
	return (1);
}