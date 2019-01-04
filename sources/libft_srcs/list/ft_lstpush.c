/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:20:28 by gpouyat           #+#    #+#             */
/*   Updated: 2019/01/04 15:57:03 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
	{
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
	}
	else
		*alst = new;
}

void	ft_lstpush_new(t_list **alst, void const *content, size_t content_size)
{
	t_list	*new;

	new = ft_lstnew(content, content_size);
	if (new)
		ft_lstpush(alst, new);
}

void	ft_lstpush_new_secu(t_list **alst, void const *content,
												size_t content_size, size_t lvl)
{
	t_list	*new;

	new = ft_lstnew_secu(content, content_size, lvl);
	if (new)
		ft_lstpush(alst, new);
}

void	ft_lstpush_extra(t_list **alst, void const *content,
															size_t content_size)
{
	t_list	*new;

	new = ft_lstextra(content, content_size);
	if (new)
		ft_lstpush(alst, new);
}

void	ft_lstpush_extra_secu(t_list **alst, void const *content,
												size_t content_size, size_t lvl)
{
	t_list	*new;

	new = ft_lstextra_secu(content, content_size, lvl);
	if (new)
		ft_lstpush(alst, new);
}
