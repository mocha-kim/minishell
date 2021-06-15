#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** return 0:start==end(no env args) 1:found
*/

int		find_next_env(int *start, int *end)
{
	int		i;

	*start = ft_strlen(g_state.line);
	*end = *start;
	i = *start;
	while (i >= 0)
	{
		if (g_state.line[i] == '$')
			break ;
		i--;
	}
	*start = i;
	if (i == -1)
		return (0);
	while (g_state.line[i])
	{
		if (g_state.line[i] == ' ')
			break;
		i++;
	}
	*end = i;
	// printf("found >> start : %d, end : %d\n", *start, *end);
	return (1);
}

/*
** return 1:success 0:empty line 127:exit
*/

int		replace_env(int	start, int end, char *content)
{
	char	*pre;
	char	*next;
	char	*tmp;

	if (start == end)
		end = ft_strlen(g_state.line);
	if (!(pre = ft_substr(g_state.line, 0, start)))
		return (print_memory_error(ERR_MALLOC));
	if (!(next = ft_substr(g_state.line, end + 1, ft_strlen(g_state.line) - end)))
	{
		free(pre);
		return (print_memory_error(ERR_MALLOC));
	}
	// printf("pre: %s, next: %s\n", pre, next);
	free(g_state.line);
	tmp = ft_strjoin(pre, content);
	g_state.line = ft_strjoin(tmp, next);
	// printf("tmp : %s, line : %s\n", tmp, g_state.line);
	free(tmp);
	free(pre);
	free(next);
	if (!ft_strcmp(g_state.line, ""))
		return (0);
	return (1);
}

/*
** return 1:success 0:null line 127:exit
*/

int		parse_env(void)
{
	int		start;
	int		end;
	char	*name;
	char	*content;

	start = 1;
	while(start > 0)
	{
		if (!find_next_env(&start, &end))
			return (1);
		while (1)
		{
			name = ft_substr(g_state.line, start + 1, end - start);
			content = env_search(name);
			free(name);
			if (ft_strcmp(content, "") || start == end)
			{
				if (replace_env(start, end, content) != 1)
					return (0);
				break ;
			}
			end--;
		}
	}
	return (1);
}