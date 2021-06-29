/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:33:51 by sunhkim           #+#    #+#             */
/*   Updated: 2021/06/29 18:06:03 by sunhkim          ###   ########.fr       */
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

/*
** delete outer quotes
** return 0:failed 1:succeed 127:exit
*/

static char	*split_and_join(char *str, int i, int j)
{
	char	*split[3];
	char	*tmp;
	char	*ret;

	while (str[j])
	{
		if (str[i] == str[j])
		{
			split[0] = ft_substr(str, 0, i);
			split[1] = ft_substr(str, i + 1, j - i - 1);
			split[2] = ft_substr(str, j + 1, ft_strlen(str) - j);
			printf(">>> 0: %s, 1: %s, 2: %s\n", split[0], split[1], split[2]);
			tmp = ft_strjoin_null(split[0], split[1]);
			ret = ft_strjoin_null(tmp, split[2]);
			if (!ret)
				return (NULL);
			free(split[0]);
			free(split[1]);
			free(split[2]);
			free(tmp);
			return (ret);
		}
		j++;
	}
	return (0);
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
				return (print_memory_error(ERR_MALLOC));
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
** return 1:succeed 127:exit
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
			i++;
		}
		tmp = tmp->next;
	}
	return (1);
}

int		free_before_exit(t_dlist **dlist, int errnum)
{
	if (*dlist)
		ft_dlstclear(dlist, free);
	return (print_syntax_error(errnum));
}
