#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** return 0:start==end(no env args) 1:found
*/

int		find_next_env(int *start, int *end)
{
	int		i;

	i = *start;
	while (g_state.line[i])
	{
		if (g_state.line[i] == '$')
			break ;
		i++;
	}
	start = i;
	while (g_state.line[i])
	{
		if (g_state.line[i] == ' ')
			break;
		i++;
	}
	end = i;
	printf("start : %d(%c), end : %d(%c)\n", *start, g_state.line[*start], *end,  g_state.line[*end]);
	return (!(*start == *end));
}

int		replace_env(int	start, int end)
{

}

/*
** return 1:success 0:failed 127:exit
*/

int		parse_env(void)
{
	int		start;
	int		end;
	char	*name;
	char	*content;

	printf("parse env\n");
	if (!g_state.line)
		return (0);
	printf("line : %s\n", g_state.line);
	while(g_state.line[start])
	{
		if (!find_next_env(&start, &end))
			return (1);
		while (1)
		{
			name = ft_substr(g_state.line, start, end - start);
			printf("name : %s\n", name);
			if (content = env_search(name))
			{
				replace_env(start, end);
				break ;
			}
			if (!content && (start == end))
		}
	}
	return (1);
}