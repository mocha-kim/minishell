/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:28:05 by yoahn             #+#    #+#             */
/*   Updated: 2021/01/15 20:39:27 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_findchar(char *s)
{
	int	i;

	i = 0;
	if (!*s)
		return (-1);
	while (s[i] || s[i] == '\n')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int		save_line(char **dest, char *src, char **save)
{
	int		len;
	char	*tmp;
	char	*tmp2;

	tmp = *dest;
	len = ft_findchar(src);
	if (src[len] == '\n')
	{
		tmp2 = ft_substr(src, 0, len);
		*dest = ft_strjoin(*dest, tmp2);
		if (src[len + 1] != '\0')
			*save = ft_substr(src, len + 1, ft_strlen(src) - len - 1);
		free(tmp);
		free(tmp2);
		return (1);
	}
	*dest = ft_strjoin(*dest, src);
	free(tmp);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*back[OPEN_MAX];
	char		buf[64];
	char		*tmp;
	int			nread;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = ft_substr("", 0, 0);
	if (back[fd])
	{
		tmp = back[fd];
		nread = save_line(line, back[fd], &back[fd]);
		free(tmp);
		if (tmp == back[fd])
			back[fd] = 0;
		if (nread)
			return (1);
	}
	while ((nread = read(fd, buf, 64)) > 0)
	{
		buf[nread] = 0;
		if (save_line(line, buf, &back[fd]) > 0)
			break ;
	}
	return (nread > 0 ? 1 : nread);
}
