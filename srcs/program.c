/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:37:03 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/21 22:42:18 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/program.h"

static int	free_remains(t_dlist **substr, t_dlist **parse)
{
	if (*substr)
		ft_dlstclear(substr, free);
	*substr = NULL;
	if (*parse)
		ft_dlstclear(parse, free);
	*parse = NULL;
	return (EXIT_CODE);
}

static int	save(t_dlist **programs, t_dlist **parse, t_dlist **tmp)
{
	if (save_parse(programs, parse) == EXIT_CODE)
		return (EXIT_CODE);
	ft_dlstclear(parse, free);
	if (((*tmp)->next) && ft_strchr((char *)((*tmp)->next->content), '|'))
	{
		save_flag(programs);
		*tmp = (*tmp)->next;
	}
	return (1);
}

/*
** parse g_state.line to info
** return 0:failed(error) 1:succeed 127:exit
*/

int			run_program(t_dlist **programs, char *line)
{
	int		sq;
	int		dq;
	t_dlist	*substr;
	t_dlist	*parse;
	t_dlist	*tmp;

	substr = NULL;
	parse = NULL;
	if (parse_line1(&sq, &dq, line, &substr) == EXIT_CODE)
		return (EXIT_CODE);
	tmp = substr;
	while (tmp)
	{
		parse_env((char **)&(tmp->content));
		if (parse_line2(&sq, &dq, tmp->content, &parse) == EXIT_CODE)
			return (free_remains(&substr, &parse));
		if (save(programs, &parse, &tmp) != 1)
			return (EXIT_CODE);
		if (*programs && ((t_program *)((*programs)->content))->args)
			execute(*programs);
		tmp = tmp->next;
	}
	free_remains(&substr, &parse);
	return (1);
}
