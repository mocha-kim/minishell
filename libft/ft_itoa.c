/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:35:43 by sunhkim           #+#    #+#             */
/*   Updated: 2020/12/27 19:35:01 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_str_len(long n_long)
{
	int		length;

	if (n_long == 0)
		return (1);
	length = 0;
	if (n_long < 0)
	{
		length++;
		n_long *= -1;
	}
	while (n_long > 0)
	{
		n_long /= 10;
		length++;
	}
	return (length);
}

static void	int_to_ascii(char *result, long n_long, int length)
{
	result[length] = '\0';
	if (n_long < 0)
	{
		result[0] = '-';
		n_long *= -1;
	}
	result[--length] = n_long % 10 + '0';
	n_long /= 10;
	while (n_long > 0)
	{
		result[--length] = n_long % 10 + '0';
		n_long /= 10;
	}
}

char		*ft_itoa(int n)
{
	char	*result;
	long	n_long;
	int		length;

	n_long = n;
	length = get_str_len(n_long);
	if (!(result = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	int_to_ascii(result, n_long, length);
	return (result);
}
