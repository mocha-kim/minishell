/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:24:12 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/13 18:49:24 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

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
	t_dlist		*count;
	t_program	*new;

	tmp = *parse;
	if (tmp)
	{
		del_backslash(parse);
		del_quote(parse);
		tmp = *parse;
		init_program(&new, &tmp);
		count = tmp;
		while (count)
		{
			(new->argc)++;
			count = count->next;
		}
		save_args(&new, &tmp, parse, new->argc);
		ft_dlstadd_back(programs, ft_dlstnew(new));
	}
	return (1);
}
