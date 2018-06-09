/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:32:43 by gpouyat           #+#    #+#             */
/*   Updated: 2018/06/09 21:43:39 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstsort(t_list **lst, t_bool (*sort)(t_list *a, t_list *b))
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
			if (!sort(smaller, index))
				smaller = index;
			index = index->next;
		}
		ft_lstremove(lst, smaller);
		ft_lstpush(&new_lst, smaller);
	}
	*lst = new_lst;
}

void ft_lstsortrev(t_list **lst, t_bool (*sort)(t_list *a, t_list *b))
{
	ft_lstsort(lst, sort);
	ft_lstrev(lst);
}

void ft_lstrev(t_list **lst)
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_lstremove(lst, tmp);
		ft_lstadd(&new, tmp);
	}
	*lst = new;
}