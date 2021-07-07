/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:20:59 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/07 17:37:22 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

/*
** count quote by num..
** closed==true, opened==flase
*/

void		count_quote(char *line, int *double_quote, int *single_quote, int i)
{
	if (*double_quote)
	{
		if (line[i] == '\"')
			*double_quote = FALSE;
	}
	else if (*single_quote)
	{
		if (line[i] == '\'')
			*single_quote = FALSE;
	}
	else
	{
		if (line[i] == '\"')
			*double_quote = TRUE;
		if (line[i] == '\'')
			*single_quote = TRUE;
	}
}

/*
** check single, double auotes are closed
** return 1:closed 0:opened(error) -1:empty line
*/

int			check_quote_closed(char *line)
{
	int		i;
	int		double_quote;
	int		single_quote;

	i = 0;
	double_quote = FALSE;
	single_quote = FALSE;
	if (!line)
		return (-1);
	while (line[i])
	{
		count_quote(line, &double_quote, &single_quote, i);
		i++;
	}
	return (!(double_quote || single_quote));
}

/*
** check single, double quotes before parsing
** return 0:failed 1:succeed 127:exit
*/

int			check_quote(char *line)
{
	if (!check_quote_closed(line))
		return (print_syntax_error(ERR_QUOTE));
	return (1);
}

/*
** delete outer quotes
** return 0:not found 1:succeed 127:exit
*/

static int	del_quote2(char **content, int *i)
{
	int		j;
	char	*str;

	j = *i + 1;
	while ((*content)[j])
	{
		if ((*content)[*i] == (*content)[j])
		{
			if (j == *i + 1)
			{
				free(*content);
				*content = ft_strnew(0);
				return (1);
			}
			if (!(str = split_and_join(*content, *i, j)))
			{
				printf("del_quote2\n");
				return (print_memory_error(ERR_MALLOC));
			}
			free(*content);
			*content = str;
			(*i) += j - *i - 2;
			return (1);
		}
		j++;
	}
	return (0);
}

/*
** delete outer quotes
** return 0:null 1:succeed 127:exit
*/

int			del_quote(t_dlist **parse)
{
	int		i;
	t_dlist	*tmp;

	tmp = *parse;
	while (tmp)
	{
		i = 0;
		while (((char *)(tmp->content))[i])
		{
			if (((char *)(tmp->content))[i] == '\''
				|| ((char *)(tmp->content))[i] == '\"')
			{
				if (del_quote2((char **)(&(tmp->content)), &i) == EXIT_CODE)
					return (EXIT_CODE);
			}
			if (((char *)(tmp->content))[i] == '\0')
				return (0);
			i++;
		}
		tmp = tmp->next;
	}
	return (1);
}
