/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:36:29 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/27 20:37:37 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int value)
{
	int		rest;
	char	*str;
	char	c[2];
	char	*tmp;

	str = ft_strnew(1);
	c[1] = '\0';
	while (value >= 10)
	{
		rest = value % 10;
		value /= 10;
		c[0] = (rest > 9) ? ((rest - 10) + 'A') : rest + '0';
		tmp = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(c, tmp);
		ft_strdel(&tmp);
	}
	c[0] = (value > 9) ? ((value - 10) + 'A') : value + '0';
	tmp = ft_strdup(str);
	ft_strdel(&str);
	str = ft_strjoin(c, tmp);
	ft_strdel(&tmp);
	return (str);
}
