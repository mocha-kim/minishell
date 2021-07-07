/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:14:16 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/07 17:59:41 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** return 0:failed 1:succeed
*/

int				del_last_char(void)
{
	int		len;
	char	*tmp;

	if (!(g_state.ptr->tmp) || g_state.ptr->tmp[0] == '\0')
		return (0);
	else
	{
		len = ft_strlen(g_state.ptr->tmp);
		ft_putchar_fd('\b', STD_OUT);
		ft_putstr_fd(" \b", STD_OUT);
		tmp = malloc(sizeof(char) * len);
		ft_strlcpy(tmp, g_state.ptr->tmp, len);
		free(g_state.ptr->tmp);
		g_state.ptr->tmp = tmp;
		return (0);
	}
}

/*
** save char to g_state.line
*/

void			save_key(int c)
{
	char	*tmp;
	int		i;

	if (!(g_state.ptr->tmp))
	{
		g_state.ptr->tmp = malloc((sizeof(char) * 2));
		g_state.ptr->tmp[0] = c;
		g_state.ptr->tmp[1] = '\0';
	}
	else
	{
		tmp = malloc(sizeof(char) * (ft_strlen(g_state.ptr->tmp) + 2));
		i = -1;
		while (g_state.ptr->tmp[++i])
			tmp[i] = g_state.ptr->tmp[i];
		tmp[i] = c;
		tmp[i + 1] = '\0';
		free(g_state.ptr->tmp);
		g_state.ptr->tmp = tmp;
	}
	ft_putchar_fd(c, STD_OUT);
}

/*
** return 0:failed 1:succeed
*/

void			process_key(int c)
{
	if (c == KEY_EOF)
	{
		if (!(g_state.ptr->tmp) || g_state.ptr->tmp[0] == '\0')
		{
			if (g_state.ptr->tmp)
				ft_strdel(&(g_state.ptr->tmp));
			ft_putstr_fd("exit\n", STD_OUT);
			exit(g_state.ret);
		}
	}
	else if (c == KEY_BSPACE)
		del_last_char();
	else if (c == KEY_ARROW_UP)
		history_up();
	else if (c == KEY_ARROW_DOWN)
		history_down();
	else if (ft_isprint((char)c))
		save_key(c);
}

/*
** get input by read, save to g_state.line
** return 0:failed(error) 1:succeed 2:/n 127:exit
*/

int				save_input(void)
{
	int		c;
	int		nread;

	c = 0;
	nread = 1;
	while ((nread = read(STD_IN, &c, sizeof(c))) > 0)
	{
		if (c == '\n')
		{
			ft_putchar_fd('\n', STD_OUT);
			break ;
		}
		else
			process_key(c);
		c = 0;
	}
	if (nread < 0)
		return (EXIT_CODE);
	return (1);
}
