/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:14:49 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/07 19:35:47 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

void	print_cd_error(char *str, int code)
{
	char	*err;

	ft_putstr_fd("bash: cd: ", STD_ERR);
	if (code == 1)
	{
		ft_putstr_fd("HOME not set\n", STD_ERR);
		return ;
	}
	ft_putstr_fd(str, STD_ERR);
	free(str);
	ft_putstr_fd(": ", STD_ERR);
	err = strerror(errno);
	ft_putstr_fd(err, STD_ERR);
	write(2, "\n", 1);
}

int		print_error_msg(char *type, char *content)
{
	ft_putstr_fd(type, STD_ERR);
	ft_putstr_fd(": ", STD_ERR);
	ft_putstr_fd(content, STD_ERR);\
	ft_putstr_fd("\n", STD_ERR);
	return (EXIT_CODE);
}
