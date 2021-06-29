/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:26:24 by sunhkim           #+#    #+#             */
/*   Updated: 2021/06/29 20:26:32 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

t_history	*ft_historynew(char *save)
{
	t_history	*new;

	if (!(new = malloc(sizeof(t_history))))
		return (NULL);
	new->save = save;
	new->tmp = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		ft_historyadd_front(t_history **lst, t_history *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}

void		ft_historydelone(t_history *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
	{
		if (lst->save)
			del(lst->save);
		if (lst->tmp)
			del(lst->tmp);
	}
	free(lst);
}

void		ft_historyclear(t_history **lst, void (*del)(void *))
{
	t_history *tmp;

	if (!del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_historydelone(*lst, del);
		(*lst) = tmp;
	}
}
