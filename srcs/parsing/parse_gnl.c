#include "../../includes/parsing.h"

extern int	g_signal;

/*
** get input by gnl, save to processed_line
** return 0:failed(error) 1:succeed 
*/
int			save_input(char **processed_line)
{
	char	*line;
	int		nread;

	*processed_line = ft_strnew(0);
	while ((nread = get_next_line(0, &line)) > 0)
	{
		g_signal = 0;
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