/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:37:06 by sunhkim           #+#    #+#             */
/*   Updated: 2021/06/29 19:12:18 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** cut line by semicolon, save to substr
** return 1:succeed 127:exit
*/

int		parse_semicolon(const char *line, t_dlist **substr,
						int *start, int *end)
{
	if (line[*end + 1] == ';')
		return (free_before_exit(substr, ERR_SEMICOLONE2));
	if (cut_line(line, substr, *start, *end) == EXIT_CODE)
		return (EXIT_CODE);
	*start = *end + 1;
	return (1);
}

/*
** parse line by semicolon or flags, save to substr
** return 1:succeed 127:exit
*/

int		parse_line1(int *sq, int *dq, const char *line, t_dlist **substr)
{
	int		start;
	int		end;

	init_args(sq, dq, &start);
	skip_whitespace(line, &start);
	end = start;
	while (line[end])
	{
		if (*dq && line[end] == '\'')
			*sq = !(*sq);
		else if (*sq && line[end] == '\"')
			*dq = !(*dq);
		else if (*sq && *dq && is_flag(line[end]))
		{
			if (parse_pipe(line, substr, &start, &end) == EXIT_CODE)
				return (EXIT_CODE);
		}
		else if (*sq && *dq && line[end] == ';')
			if (parse_semicolon(line, substr, &start, &end) == EXIT_CODE)
				return (EXIT_CODE);
		end++;
	}
	if (line[end] == '\0')
		return (cut_line(line, substr, start, end));
	return (0);
}
