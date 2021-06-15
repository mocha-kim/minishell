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
	*start = i;
	while (g_state.line[i])
	{
		if (g_state.line[i] == ' ')
			break;
		i++;
	}
	*end = i;
	printf("start : %d(%c), end : %d(%c)\n", *start, g_state.line[*start], *end,  g_state.line[*end]);
	return (!(*start == *end));
}

/*
** return 1:success 0:failed 127:exit
*/

int		replace_env(int	start, int end, char *content)
{
	char	*pre;
	char	*next;
	char	*tmp;

	if (!(pre = ft_substr(g_state.line, start, end - start)))
		return (print_memory_error(ERR_MALLOC));
	if (!(next = ft_substr(g_state.line, end, ft_strlen(g_state.line) - end)))
	{
		free(pre);
		return (print_memory_error(ERR_MALLOC));
	}
	printf("pre: %s, next: %s\n", pre, next);
	free(g_state.line);
	tmp = ft_strjoin(pre, content);
	g_state.line = ft_strjoin(tmp, next);
	printf("return: %s\n", g_state.line);
	free(tmp);
	free(pre);
	free(next);
	return (1);
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
	start = 0;
	end = 0;
	while(g_state.line[start])
	{
		if (!find_next_env(&start, &end))
			return (1);
		while (1)
		{
			name = ft_substr(g_state.line, start + 1, end - start);
			content = env_search(name);
			printf("name : %s, content : %s\n", name, content);
			replace_env(start, end, content);
			free(name);
		}
	}
	return (1);
}