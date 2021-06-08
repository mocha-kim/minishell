#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** count quote by num..
** closed==true, opened==flase
*/
void	count_quote(int *double_quote, int *single_quote, int i)
{
	if (*double_quote)
	{
		if (g_state.line[i] == '\"')
			*double_quote = FALSE;
	}
	else if (*single_quote)
	{
		if (g_state.line[i] == '\'')
			*single_quote = FALSE;
	}
	else
	{
		if (g_state.line[i] == '\"')
			*double_quote = TRUE;
		if (g_state.line[i] == '\'')
			*single_quote = TRUE;
	}
}

/*
** check single, double auotes are closed
** return 1:closed 0:opened(error) -1:empty line
*/
int		check_quote_closed(void)
{
	int		i;
	int		double_quote;
	int		single_quote;

	i = 0;
	double_quote = FALSE;
	single_quote = FALSE;
	if (!g_state.line)
		return (-1);
	while(g_state.line[i])
	{
		count_quote(&double_quote, &single_quote, i);
		i++;
	}
	return (!(double_quote || single_quote));
}

/*
** check single, double quotes before parsing
** return 0:failed 1:succeed 127:exit
*/
int		check_quote(void)
{
	if (!check_quote_closed())
		return (print_syntax_error(ERR_QUOTE));
	return (1);
}