/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:20:28 by gpouyat           #+#    #+#             */
/*   Updated: 2018/05/10 17:46:35 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = new;
	else
		*alst = new;
}

void	ft_lstpush_new(t_list **alst, void const *content, size_t content_size)
{
	t_list	*new;

	new = ft_lstnew(content, content_size);
	ft_lstpush(alst, new);
}