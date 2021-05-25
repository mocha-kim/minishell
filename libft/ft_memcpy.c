/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:10:25 by sunhkim           #+#    #+#             */
/*   Updated: 2020/12/27 16:37:07 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	while (i < n)
	{
		*((char *)dst_tmp + i) = *((char *)src_tmp + i);
		i++;
	}
	return (dst_tmp);
}
