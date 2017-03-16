/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:17:04 by gpouyat           #+#    #+#             */
/*   Updated: 2017/01/03 08:08:34 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddnew(t_list **list, void const *content, size_t content_size)
{
	t_list	*new;

	if (!(*list))
	{
		*list = ft_lstnew(content, content_size);
	}
	else
	{
		new = ft_lstnew(content, content_size);
		new->next = *list;
		*list = new;
	}
}

void	ft_lstsuppress(t_list *list)
{
	t_list	*temp;

	if (list == NULL)
		return ;
	while (list)
	{
		temp = list;
		list = list->next;
		free(temp->content);
		free(temp);
	}
}
