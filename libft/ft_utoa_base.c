/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:51:01 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/28 20:54:13 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_nbrlen(unsigned int nbr, int b_len)
{
	int cnt;

	if (nbr == 0)
		return (1);
	cnt = 0;
	while (nbr > 0)
	{
		nbr = nbr / b_len;
		cnt++;
	}
	return (cnt);
}

char			*ft_utoa_base(unsigned int n, char *base, int b_len)
{
	char			*res;
	int				len;

	len = get_nbrlen(n, b_len);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = base[n % b_len];
		n = n / b_len;
		len--;
	}
	return (res);
}
