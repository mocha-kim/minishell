/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:37:08 by sunhkim           #+#    #+#             */
/*   Updated: 2021/06/29 16:37:09 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

/*
** cut curstr by blank, save to parse
** return 1:succeed 127:exit
*/

int		parse_blank(const char *curstr, t_dlist **parse, int *start, int *end)
{
	if (cut_line(curstr, parse, *start, *end) == EXIT_CODE)
		return (EXIT_CODE);
	if (skip_whitespace(curstr, end) > 0)
		(*end)--;
	*start = *end + 1;
	return (1);
}

/*
** parse curstr by semicolon, save to parse
** return 1:succeed 127:exit
*/

int		parse_line2(int *is_sq_c, int *is_dq_c, const char *curstr, t_dlist **parse)
{
	int		start;
	int		end;

	*is_sq_c = TRUE;
	*is_dq_c = TRUE;
	start = 0;
	skip_whitespace(curstr, &start);
	end = start;
	while (curstr[end])
	{
		if (*is_dq_c && (curstr[end] == '\''))
			*is_sq_c = !(*is_sq_c);
		else if (*is_sq_c && curstr[end] == '\"')
			*is_dq_c = !(*is_dq_c);
		else if (*is_sq_c && *is_dq_c && is_flag(curstr[end]))
		{
			if (parse_redir(curstr, parse, &start, &end) == EXIT_CODE)
				return (EXIT_CODE);
		}
		else if (*is_sq_c && *is_dq_c && curstr[end] == ' ')
			if (parse_blank(curstr, parse, &start, &end) == EXIT_CODE)
				return (EXIT_CODE);
		end++;
	}
	if (curstr[end] == '\0')
		return (cut_line(curstr, parse, start, end));
	return (0);
}