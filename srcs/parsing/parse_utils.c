/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:33:51 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/07 17:57:03 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** cut line, similar to ft_substtr, save to
** return 1:succeed 127:exit
*/

int			cut_line(const char *str, t_dlist **save_lst, int start, int end)
{
	char	*tmp;

	if (start != end)
	{
		tmp = ft_substr(str, start, end - start);
		if (!tmp)
			return (print_memory_error(ERR_MALLOC));
		ft_dlstadd_back(save_lst, ft_dlstnew(tmp));
	}
	return (1);
}

int			free_before_exit(t_dlist **dlist, int errnum)
{
	if (*dlist)
		ft_dlstclear(dlist, free);
	*dlist = NULL;
	return (print_syntax_error(errnum));
}

void		init_args(int *sq, int *dq, int *s)
{
	*sq = TRUE;
	*dq = TRUE;
	*s = 0;
}
