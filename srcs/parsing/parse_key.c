#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** return 0:failed 1:succeed 
*/
int				del_last_char(void)
{
	int		len;
	char	*tmp;

	len = ft_strlen(g_state.line);
	if (g_state.line)
		return (0);
	else
	{
		tmp = malloc(sizeof(char) * len);
		ft_strlcpy(tmp, g_state.line, len);
		free(g_state.line);
		g_state.line = tmp;
		return (0);	
	}
}

void			save_key(int c)
{
	char	*tmp;
	int		i;

	if (!g_state.line)
	{
		g_state.line = malloc((sizeof(char) * 2));
		g_state.line[0] = c;
		g_state.line[1] = '\0';
	}
	else
	{
		tmp = malloc(sizeof(char) * (ft_strlen(g_state.line) + 2));
		i = -1;
		while (g_state.line[++i])
			tmp[i] = g_state.line[i];
		tmp[i] = c;
		tmp[i + 1] = '\0';
		free(g_state.line);
		g_state.line = tmp;
	}
}

/*
** return 0:failed 1:succeed 
*/
int				process_key(int c, t_list **history)
{
	printf("key %d\n", c);
	if (c == KEY_EOF)
	{
		if (!(g_state.line))
		{
			ft_putstr_fd("exit\n", STD_OUT);
			exit(0);
		}
	}
	else if (c == KEY_BACKSPACE)
		del_last_char();
	else if (c == KEY_UP)
		history_up(history);
	else if (c == KEY_DOWN)
		history_down(history);
	else
	{
		if (ft_isprint((char)c))
			save_key(c);
	}
	return (1);
}