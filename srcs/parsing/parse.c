/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:37:03 by sunhkim           #+#    #+#             */
/*   Updated: 2021/06/29 16:42:36 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		(*new)->command = NULL;
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

	tmp = *parse;
	if (tmp)
	{
		if (((char *)(tmp->content))[0] == '|')
			save_flag(programs);
		else
		{
			del_quote(parse);
			tmp = *parse;
			init_program(&new, &tmp);
			while (tmp)
			{
				(new->argc)++;
				tmp = tmp->next;
			}
			save_args(&new, &tmp, parse, new->argc);
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
	int		sq;
	int		dq;
	t_dlist	*substr;
	t_dlist	*parse;
	t_dlist	*tmp;

	substr = NULL;
	if (parse_line1(&sq, &dq, line, &substr) == EXIT_CODE)
		return (EXIT_CODE);
	parse = NULL;
	tmp = substr;
	while (tmp)
	{
		if (((char *)(tmp->content))[0] == '|')
			parse = ft_dlstnew(ft_strdup(tmp->content));
		else
		{
			if (parse_line2(&sq, &dq, tmp->content, &parse) == EXIT_CODE)
				return (EXIT_CODE);
		}
		if (save_parse(programs, &parse) == EXIT_CODE)
			return (EXIT_CODE);
		ft_dlstclear(&parse, free);
		tmp = tmp->next;
	}
	ft_dlstclear(&substr, free);
	return (1);
}
