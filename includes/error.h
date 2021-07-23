/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:44:41 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/21 23:13:31 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "data.h"
# include <errno.h>
# include <string.h>

# define ERR_QUOTE 0
# define ERR_SEMICOLONE 1
# define ERR_SEMICOLONE2 2
# define ERR_PIPE 3
# define ERR_PIPE2 4
# define ERR_NEWLINE 5
# define ERR_LAB 6
# define ERR_LAB2 7
# define ERR_RAB 8
# define ERR_RAB2 9
# define ERR_MALLOC 0
# define ERR_IO 1

# define EXIT_CODE 127

/*
** error.c
*/

int		print_syntax_error(int errnum);
int		print_memory_error(int errnum);
int		print_exit_error(char *str, int code);
void	error_export(char *str);
void	execute_error(char *cmd, int type);

/*
** error2.c
*/

void	print_cd_error(char *str, int code);
int		print_error_msg(char *type, char *content);

#endif
