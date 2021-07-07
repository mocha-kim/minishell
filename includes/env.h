/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:44:38 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/07 19:45:49 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "data.h"
# include "../libft/libft.h"

/*
** env_parse.c
*/
int			env_parse(char *envp[]);
t_env		*env_new(char *envp);
void		env_add(t_env **lst, t_env *new);
char		*env_search(char *name);
/*
** env_change.c
*/
int			env_change(char *name, char *content);
int			env_change2(char *line);
int			env_delone(char *name);
/*
** env_utils.c
*/
char		**make_envp(void);
int			env_cnt(void);

#endif
