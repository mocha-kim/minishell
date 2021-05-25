/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:48:28 by sunhkim           #+#    #+#             */
/*   Updated: 2020/12/28 17:59:44 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_word(const char *s, char c)
{
	int		i;
	int		count;

	if (!s[0])
		return (0);
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static void			find_next_str(char **str, unsigned int *len, char c)
{
	unsigned int	i;

	*str += *len;
	*len = 0;
	while (**str && **str == c)
		(*str)++;
	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

static char			**freee(char **result)
{
	unsigned int	i;

	i = 0;
	while (result[i] != 0)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	substr_num;
	unsigned int	substr_len;
	char			**result;
	char			*substr;

	if (!s)
		return (NULL);
	substr_num = count_word(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (substr_num + 1))))
		return (NULL);
	i = 0;
	substr = (char *)s;
	substr_len = 0;
	while (i < substr_num)
	{
		find_next_str(&substr, &substr_len, c);
		if (!(result[i] = (char *)malloc(sizeof(char) * (substr_len + 1))))
			return (freee(result));
		ft_strlcpy(result[i], substr, substr_len + 1);
		i++;
	}
	result[i] = NULL;
	return (result);
}
