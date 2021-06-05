#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** get input by read, save to g_state.line
** return 0:failed(error) 1:succeed 
*/
int				save_input(t_list **history)
{
	int		c;
	int		nread;

	c = 0;
	g_state.line = NULL;
	while ((nread = read(0, &c, 1) >= 0))
	{
		if (c == '\n')
		{
			c = 0;
			break ;
		}
		else
			process_key(c, history);
		c = 0;
	}
	if (nread < 0)
		return(!(print_memory_error(ERR_MALLOC) == EXIT_CODE));
	return (1);
}