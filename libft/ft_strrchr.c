/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:14:47 by sunhkim           #+#    #+#             */
/*   Updated: 2020/12/22 17:18:58 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = 0;
	result = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			result = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		result = (char *)&s[i];
	return (result);
}
