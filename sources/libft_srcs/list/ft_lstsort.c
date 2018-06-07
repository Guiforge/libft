/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:32:43 by gpouyat           #+#    #+#             */
/*   Updated: 2018/06/07 18:17:59 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstsort(t_list **lst, int (*sort)(t_list *a, t_list *b))
{
	t_list	*new_lst;
	t_list	*smaller;
	t_list	*index;

	new_lst = NULL;
	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		index = *lst;
		smaller = *lst;
		while(index)
		{
			if (sort(smaller, index) > 0)
				smaller = index;
			index = index->next;
		}
		ft_lstremove(lst, smaller);
		ft_lstpush(&new_lst, smaller);
	}
	*lst = new_lst;
}

void ft_lstsortrev(t_list **lst, int (*sort)(t_list *a, t_list *b))
{
	t_list	*new_lst;
	t_list	*smaller;
	t_list	*index;

	new_lst = NULL;
	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		index = *lst;
		smaller = *lst;
		while(index->next)
		{
			if (sort(smaller, index) < 0)
				smaller = index;
			index = index->next;
		}
		ft_lstremove(lst, smaller);
		ft_lstpush(&new_lst, smaller);
	}
	*lst = new_lst;
}