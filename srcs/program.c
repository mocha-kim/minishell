/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:37:03 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/05 16:11:10 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/program.h"

/*
** parse g_state.line to info
** return 0:failed(error) 1:succeed 127:exit
*/

int		run_program(t_dlist **programs, char *line)
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
		if (parse_env((char **)&(tmp->content)) != 1)
			return (EXIT_CODE);
		// printf("env parsed: %s\n", tmp->content);
		if (ft_strchr((char *)(tmp->content), '|'))
			ft_dlstadd_back(&parse, ft_dlstnew(ft_strdup("|")));
		else if (parse_line2(&sq, &dq, tmp->content, &parse) == EXIT_CODE)
			return (EXIT_CODE);
		if (save_parse(programs, &parse) == EXIT_CODE)
			return (EXIT_CODE);
		ft_dlstclear(&parse, free);
		// printf("args : %s\n", *((t_program *)((*programs)->content))->args);
		if (((t_program *)((*programs)->content))->args)
			execute(*programs);
		tmp = tmp->next;
	}
	ft_dlstclear(&substr, free);
	return (1);
}
