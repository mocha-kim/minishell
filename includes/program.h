/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:44:52 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/09 16:09:14 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H

# include "error.h"
# include "parsing.h"
# include "command.h"

/*
** program.c
*/

int						run_program(t_dlist **programs, char *line);

#endif
