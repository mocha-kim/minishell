/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:03:38 by sunhkim           #+#    #+#             */
/*   Updated: 2020/12/23 18:16:51 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	char			*result;

	if (!(result = malloc(size * count)))
		return (0);
	i = 0;
	while (i < (size * count))
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}
