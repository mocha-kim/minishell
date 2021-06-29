/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:37:06 by sunhkim           #+#    #+#             */
/*   Updated: 2021/06/29 16:37:06 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** cut line by semicolon, save to substr
** return 1:succeed 127:exit
*/
int		parse_semicolon(const char *line, t_dlist **substr, int *start, int *end)
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
int		parse_line1(int *is_sq_c, int *is_dq_c, const char *line, t_dlist **substr)
{
	int		start;
	int		end;

	*is_sq_c = TRUE;
	*is_dq_c = TRUE;
	start = 0;
	end = start;
	while (line[end])
	{
		if (*is_dq_c && line[end] == '\'')
			*is_sq_c = !(*is_sq_c);
		else if (*is_sq_c && line[end] == '\"')
			*is_dq_c = !(*is_dq_c);
		else if (*is_sq_c && *is_dq_c && is_flag(line[end]))
		{
			if (parse_pipe(line, substr, &start, &end) == EXIT_CODE)
				return (EXIT_CODE);
		}
		else if (*is_sq_c && *is_dq_c && line[end] == ';')
			if (parse_semicolon(line, substr, &start, &end) == EXIT_CODE)
				return (EXIT_CODE);
		end++;
	}
	if (line[end] == '\0')
		return (cut_line(line, substr, start, end));
	return (0);
}