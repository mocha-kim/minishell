/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:21:56 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/19 18:23:01 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int		is_flag(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (TRUE);
	return (FALSE);
}

/*
** cut line by pipe, save to substr
** return 1:succeed 127:exit
*/

int		parse_pipe(const char *line, t_dlist **substr, int *start, int *end)
{
	if (line[*end] == '|')
	{
		if (*end != 0)
		{
			if (cut_line(line, substr, *start, *end) == EXIT_CODE)
				return (EXIT_CODE);
			*start = *end - 1;
		}
		if (*end == 0)
		{
			if (line[*end + 1] == '|')
				return (free_before_exit(substr, ERR_PIPE2));
			return (free_before_exit(substr, ERR_PIPE));
		}
		if (cut_line(line, substr, *end, *end + 1) == EXIT_CODE)
			return (EXIT_CODE);
		*start = *end + 1;
	}
	return (1);
}

/*
** cut line by redirections, save to parse
** return 1:succeed 127:exit
*/

int		parse_redir(const char *curstr, t_dlist **parse, int *start, int *end)
{
	if (*end != 0)
	{
		if (cut_line(curstr, parse, *start, *end) == EXIT_CODE)
			return (EXIT_CODE);
		*start = *end - 1;
	}
	if (curstr[*end] == '<')
		if (parse_lab(curstr, end, parse) == EXIT_CODE)
			return (EXIT_CODE);
	if (curstr[*end] == '>')
		if (parse_rab(curstr, end, parse) == EXIT_CODE)
			return (EXIT_CODE);
	*start = *end + 1;
	return (1);
}

int		parse_lab(const char *curstr, int *end, t_dlist **parse)
{
	if (curstr[*end + 1] == '\0')
		return (free_before_exit(parse, ERR_NEWLINE));
	else if (curstr[*end + 1] == '<')
	{
		(*end)++;
		if (curstr[*end + 1] == '\0')
			return (free_before_exit(parse, ERR_NEWLINE));
		else if (curstr[*end + 1] == '<')
		{
			if (curstr[*end + 2] == '\0')
				return (free_before_exit(parse, ERR_LAB));
			else if (curstr[*end + 2] == '<')
				return (free_before_exit(parse, ERR_LAB2));
		}
		if (cut_line(curstr, parse, *end - 1, *end + 1) == EXIT_CODE)
			return (EXIT_CODE);
	}
	else if (cut_line(curstr, parse, *end, *end + 1) == EXIT_CODE)
		return (EXIT_CODE);
	return (1);
}

int		parse_rab(const char *curstr, int *end, t_dlist **parse)
{
	if (curstr[*end + 1] == '\0')
		return (free_before_exit(parse, ERR_NEWLINE));
	else if (curstr[*end + 1] == '>')
	{
		(*end)++;
		if (curstr[*end + 1] == '\0')
			return (free_before_exit(parse, ERR_NEWLINE));
		else if (curstr[*end + 1] == '>')
		{
			if (curstr[*end + 2] == '\0')
				return (free_before_exit(parse, ERR_RAB));
			else if (curstr[*end + 2] == '>')
				return (free_before_exit(parse, ERR_RAB2));
		}
		if (cut_line(curstr, parse, *end - 1, *end + 1) == EXIT_CODE)
			return (EXIT_CODE);
	}
	else if (cut_line(curstr, parse, *end, *end + 1) == EXIT_CODE)
		return (EXIT_CODE);
	return (1);
}
