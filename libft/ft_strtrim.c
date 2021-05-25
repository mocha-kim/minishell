/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:20:34 by sunhkim           #+#    #+#             */
/*   Updated: 2020/12/27 19:17:47 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	check_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	unsigned int	t_len;
	char			*t_start;
	char			*t_end;
	char			*result;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && check_set(s1[i], set))
		i++;
	t_start = (char *)&s1[i];
	if ((i = ft_strlen(s1) - 1) != -1)
		while (i >= 0 && check_set(s1[i], set))
			i--;
	t_end = (char *)&s1[i];
	if (!*s1 || t_end == t_start)
		t_len = 2;
	else
		t_len = t_end - t_start + 2;
	if (!(result = malloc(sizeof(char) * t_len)))
		return (result);
	ft_strlcpy(result, t_start, t_len);
	return (result);
}
