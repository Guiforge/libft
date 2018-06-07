/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:46:59 by gpouyat           #+#    #+#             */
/*   Updated: 2018/06/07 18:10:09 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstremove(t_list **lst, t_list *removed)
{
    if (!lst || !removed)
        return ;
    if (removed->prev)
    {
        (removed->prev)->next = removed->next;
        if (removed->next)
            removed->next->prev = removed->prev;
    }
    else
    {
        *lst = removed->next;
        if (removed->next)
            (removed->next)->prev = NULL;
    }
    removed->next = NULL;
    removed->prev = NULL;
}