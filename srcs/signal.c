#include "../includes/signal.h"

extern t_state	g_state;

static void	sig_int(void)
{
	if (g_state.is_fork == FALSE)
	{
		if (g_state.is_here)
		{
			ft_putstr_fd("\b\b\n", STD_OUT);
			exit(1);
		}
		write(STD_OUT, "\nminishell-1.0$ ", 17);
		if (g_state.ptr->tmp)
			ft_strdel(&(g_state.ptr->tmp));
		g_state.ret = 1;
	}
	else
	{
		if (g_state.need_nl)
			write(1, "\n", 1);
		g_state.ret = 130;
	}
}

static void	sig_quit(void)
{
	if (g_state.is_fork == TRUE)
	{
		g_state.ret = 131;
		if (!g_state.is_here)
			ft_putstr_fd("Quit: 3\n", STD_OUT);
		else
			write(1, " \b\b \b\b ", 7);
	}
}

void		handler(int signo)
{
	if (signo == SIGINT)
		sig_int();
	else if (signo == SIGQUIT)
		sig_quit();
}