/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:55:29 by sunhkim           #+#    #+#             */
/*   Updated: 2020/12/23 17:09:57 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	unsigned int	i;

	tmp = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		tmp[i] = c;
		i++;
	}
	return (b);
}
