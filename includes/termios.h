/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:44:57 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/07 19:46:04 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMIOS_H
# define TERMIOS_H

# include <term.h>

# include "data.h"

void		init_term(void);
void		restore_term(void);

#endif
