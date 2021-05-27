/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:01:01 by yoahn             #+#    #+#             */
/*   Updated: 2021/01/14 14:47:02 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

int				get_next_line(int fd, char **line);
int				ft_strlen(char *s);
char			*ft_substr(char *str, int start, int len);
int				save_line(char **dest, char *src, char **save);

char			*ft_strdup(char *s1);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, char *src, size_t dstsize);
char			*ft_strjoin(char *s1, char *s2);
int				ft_findchar(char *s);

#endif
