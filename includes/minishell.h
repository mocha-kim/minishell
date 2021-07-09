/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:44:46 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/09 16:51:17 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define VERSION "0.8"

# include <signal.h>
# include <sys/wait.h>

# include "program.h"

int		minishell(t_dlist **programs, t_history **history, char **envp);

#endif
