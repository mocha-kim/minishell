/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:15:15 by sunhkim           #+#    #+#             */
/*   Updated: 2020/12/27 18:14:20 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	i = 0;
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	while (i < n && src_tmp[i] != (unsigned char)c)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		dst_tmp[i] = src_tmp[i];
		i++;
		return (&dst_tmp[i]);
	}
}
