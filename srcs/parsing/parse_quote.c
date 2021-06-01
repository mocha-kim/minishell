#include "../../includes/parsing.h"

int		check_quote_close(char *line)
{
	int		i;
	int		double_quote;
	int		single_quote;

	i = 0;
	double_quote = FALSE;
	single_quote = FALSE;
	while(line[i])
	{
		if (double_quote)
		{
			if (line[i] == '\"')
				double_quote = FALSE;
		}
		else if (single_quote)
		{
			if (line[i] == '\'')
				single_quote = FALSE;
		}
		else
		{
			if (line[i] == '\"')
				double_quote = TRUE;
			if (line[i] == '\'')
				single_quote = TRUE;
		}
		i++;
	}
	return (!(double_quote || single_quote));
}