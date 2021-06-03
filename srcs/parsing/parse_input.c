#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** get input by gnl, save to processed_line
** return 0:failed(error) 1:succeed 
*/
int				save_input(t_list **history, char **processed_line)
{
	int		c;
	int		nread;

	g_state.line = NULL;
	*processed_line = ft_strnew(0);
	while ((nread = read(0, &c, 1) >= 0))
	{
		if (c == '\n')
		{
			return (1);
		}
		else
			process_key(c, history);
		c = 0;
	}
	if (nread < 0)
		return(!(print_memory_error(ERR_MALLOC) == EXIT_CODE));
	process_backslash(processed_line);
	return (1);
}