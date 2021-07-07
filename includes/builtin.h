/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:44:25 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/07 19:46:21 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "data.h"
# include "../libft/libft.h"
# include "env.h"
# include <sys/errno.h>
# include <string.h>
# include <stdio.h>
# include "error.h"

void		ft_echo(t_program *cmd);
int			ft_cd(t_program *cmd);
void		ft_pwd(void);
void		ft_exit(t_program *cmd);
void		ft_unset(t_program cmd);
int			ft_env(void);
void		ft_export(t_program *cmd);

#endif
