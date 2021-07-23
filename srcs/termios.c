/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:20:09 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/23 15:49:39 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/termios.h"

extern t_state	g_state;

void	init_term(void)
{
	tcgetattr(STDIN_FILENO, &g_state.t_sv);
	tcgetattr(STDIN_FILENO, &g_state.term);
	g_state.term.c_lflag &= ~ICANON;
	g_state.term.c_lflag &= ~ECHO;
	g_state.term.c_cc[VMIN] = 1;
	g_state.term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &g_state.term);
	tgetent(NULL, "xterm");
}

void	restore_term(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &g_state.t_sv);
}
