/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:37:03 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/07 18:17:59 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/program.h"

int		free_remains(t_dlist **substr, t_dlist **parse, t_dlist **tmp)
{
	if (*substr)
		ft_dlstclear(substr, free);
	if (*parse)
		ft_dlstclear(parse, free);
	if (*tmp)
		ft_dlstclear(tmp, free);
	return (EXIT_CODE);
}

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
	parse = NULL;
	tmp = NULL;
	if (parse_line1(&sq, &dq, line, &substr) == EXIT_CODE)
		return (free_remains(&substr, &parse, &tmp));
	tmp = substr;
	while (tmp)
	{
		if (parse_env((char **)&(tmp->content)) != 1)
			return (free_remains(&substr, &parse, &tmp));
		else if (parse_line2(&sq, &dq, tmp->content, &parse) == EXIT_CODE)
			return (free_remains(&substr, &parse, &tmp));
		if (save_parse(programs, &parse) == EXIT_CODE)
			return (free_remains(&substr, &parse, &tmp));
		ft_dlstclear(&parse, free);
		if ((tmp->next) && ft_strchr((char *)(tmp->next->content), '|'))
		{
			save_flag(programs);
			tmp = tmp->next;
		}
		t_dlist *prnt = *programs;
		while (prnt)
		{
			if (((t_program *)(prnt->content))->args)
			{
				int i = 0;
				printf(">> program : ");
				while (((t_program *)(prnt->content))->args[i])
				{
					printf("%d(%s) ", i, ((t_program *)(prnt->content))->args[i]);
					i++;
				}
				printf("\n");
			}
			prnt = prnt->next;
		}
		if (((t_program *)((*programs)->content))->args)
			execute(*programs);
		tmp = tmp->next;
	}
	free_remains(&substr, &parse, &tmp);
	return (1);
}
