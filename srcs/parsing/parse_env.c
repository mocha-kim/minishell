/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:46:26 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/14 18:16:31 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

/*
** return index of $ or -1(no env args)
*/

int		find_env_symbol(char *line, int i, int *quote)
{
	int		is_sq_c;
	int		is_dq_c;

	is_sq_c = TRUE;
	is_dq_c = TRUE;
	while (i >= 0)
	{
		if (is_dq_c && is_quote(line, i) == SINGLE_QUOTE)
			is_sq_c = !is_sq_c;
		else if (is_sq_c && is_quote(line, i) == DOUBLE_QUOTE)
			is_dq_c = !is_dq_c;
		else if (is_sq_c && line[i] == '$'
				&& !(i >= 1 && line[i - 1] == '\\'))
		{
			*quote = is_dq_c;
			return (i);
		}
		i--;
	}
	return (-1);
}

/*
** return -1:$ONLY 0:start==end(no env args) 1:found
*/

int		find_next_env(char *line, int *start, int *end)
{
	int		i;
	int		quote;

	*start = ft_strlen(line);
	*end = *start;
	i = find_env_symbol(line, *start, &quote);
	*start = i;
	if (i == -1)
		return (0);
	while (line[i])
	{
		if (line[i + 1] == ' ' || line[i + 1] == '/' || line[i + 1] == '\0'
			|| (!quote && line[i] == '\"'))
			break ;
		i++;
	}
	if (line[i - 1] == '$')
		return (-1);
	*end = i;
	printf("start: %d end: %d\n", *start, *end);
	return (1);
}

/*
** return -1:$ONLY 1:success 0:empty line 127:exit 128:malloc error
*/

int		replace_env(char **line, int start, int end, char *content)
{
	char	*pre;
	char	*next;
	char	*tmp;

	if (start == end)
		end = ft_strlen(*line) - 1;
	pre = ft_substr(*line, 0, start);
	next = ft_substr(*line, end + 1, ft_strlen(*line) - end);
	tmp = ft_strjoin(pre, content);
	free(*line);
	*line = ft_strjoin(tmp, next);
	printf("pre: %s, next: %s, content: %s, tmp: %s, line: %s\n", pre, next, content, tmp, *line);
	free(tmp);
	free(pre);
	free(next);
	if (!ft_strcmp(*line, ""))
		return (0);
	return (1);
}

/*
** return 1:success 0:null line 127:exit
*/

int		parse_env(char **line)
{
	int		start;
	int		end;
	int		ret;
	char	*name;
	char	*content;

	start = 1;
	end = 1;
	while (1)
	{
		if (find_next_env(*line, &start, &end) != 1)
			return (0);
		name = ft_substr(*line, start + 1, end - start);
		content = env_search(name);
		printf("name: %s, content: %s\n", name, content);
		ft_strdel(&name);
		if ((ret = replace_env(line, start, end, content)) != 1)
			break ;
		printf("ok\n");
		ft_strdel(&content);
	}
	if (content)
		ft_strdel(&content);
	return (ret == 1 ? 1 : 0);
}
