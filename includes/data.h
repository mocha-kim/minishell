/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:44:34 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/07 19:47:23 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# define REDIR_IN	1
# define REDIR_OUT	2
# define REDIR_APP	3
# define F_PIPE		4

# define NOTF		2
# define IS_DIR		3

/*
** no such file or directory = NSFD
*/

# define NSFD		4

# include <term.h>
# include "../libft/libft.h"

/*
** flag: pipe / (>, <, >>)redirect
*/

typedef struct			s_program
{
	char				*command;
	int					flag;
	int					argc;
	char				**args;
	int					pip[2];
	int					fd[2];
}						t_program;

/*
** input info
*/

typedef struct			s_parse
{
	struct s_parse		*next;
	t_program			cmd;
}						t_parse;

/*
** environment variable
*/

typedef struct			s_env
{
	struct s_env		*next;
	char				*name;
	char				*content;
}						t_env;

/*
** history save
*/

typedef struct			s_history
{
	char				*save;
	char				*tmp;
	struct s_history	*prev;
	struct s_history	*next;
}						t_history;

/*
** global state
** ret: exit status code
*/

typedef struct			s_state
{
	int					ret;
	int					sig;
	t_history			*cur;
	t_history			*ptr;
	t_env				*env;
	struct termios		term;
	struct termios		t_sv;
	int					is_fork;
}						t_state;

#endif
