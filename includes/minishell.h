/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:44:46 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/07 19:45:53 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define VERSION "0.8"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>

# include "builtin.h"
# include "env.h"
# include "error.h"
# include "termios.h"
# include "parsing.h"
# include "command.h"
# include "data.h"
# include "utils.h"
# include "program.h"

int		minishell(t_dlist **programs, t_history **history, char **envp);

#endif
