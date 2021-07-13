/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:22:00 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/13 17:52:17 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

/*
** return 1:success 127:exit
*/

static int	del_char(char **str, int idx)
{
	char	*pre;
	char	*next;
	char	*ret;

	if (!(pre = ft_substr(*str, 0, idx)))
		return (print_memory_error(ERR_MALLOC));
	if (!(next = ft_substr(*str, idx + 1, ft_strlen(*str) - idx - 1)))
	{
		free(pre);
		return (print_memory_error(ERR_MALLOC));
	}
	if (!(ret = ft_strjoin_null(pre, next)))
	{
		free(pre);
		free(next);
		return (print_memory_error(ERR_MALLOC));
	}
	free(pre);
	free(next);
	free(*str);
	*str = NULL;
	*str = ret;
	return (1);
}

static void	set_qt(const char *str, int i, int *sq, int *dq)
{
	if (*dq && is_quote(str, i) == SINGLE_QUOTE)
		*sq = !(*sq);
	if (*sq && is_quote(str, i) == DOUBLE_QUOTE)
		*dq = !(*dq);
}

/*
** return 1:success 127:exit
*/

int			del_backslash(t_dlist **parse)
{
	int		i;
	int		sq;
	int		dq;
	t_dlist	*tmp;

	tmp = *parse;
	while (tmp)
	{
		i = 0;
		sq = TRUE;
		dq = TRUE;
		while (((char *)(tmp->content))[i])
		{
			set_qt((char *)(tmp->content), i, &sq, &dq);
			if (sq && ((char *)(tmp->content))[i] == '\\')
				if (del_char((char **)(&(tmp->content)), i) == EXIT_CODE)
					return (EXIT_CODE);
			if (((char *)(tmp->content))[i] == '\0')
				return (0);
			i++;
		}
		tmp = tmp->next;
	}
	return (1);
}