#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** get input by gnl, save to processed_line
** return 0:failed(error) 1:succeed 
*/
int				save_input(char **processed_line)
{
	char	*line;
	int		c;
	int		nread;

	*processed_line = ft_strnew(0);
	while ((nread = read(0, &c, sizeof(c))) > 0)
	{
		if (c == '\n')
		{
			ft_putchar_fd('\n', STD_OUT);
			g_state.sig = 0;
		}
		else
				
		process_backslash(&line, processed_line);
		if (count_backslash(line) % 2 == ODD_NUM)
			continue ;
		else
			break ;
	}
	if (nread < 0)
	{
		print_memory_error(ERR_MALLOC);
		return (0);
	}
	return (1);
}