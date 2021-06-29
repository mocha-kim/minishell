/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:18:15 by sunhkim           #+#    #+#             */
/*   Updated: 2021/06/29 14:39:03 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		s1_len;
	char	*result;

	if (!s1)
		return (NULL);
	s1_len = 0;
	while (s1[s1_len] != 0)
		s1_len++;
	if (!(result = (char *)malloc(sizeof(char) * (s1_len + 1))))
		return (0);
	i = 0;
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
