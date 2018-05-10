/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:20:28 by gpouyat           #+#    #+#             */
/*   Updated: 2018/05/10 14:16:20 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list *alst, t_list *new)
{
	while (alst && alst->next)
		alst = alst->next;
	if (alst)
		alst->next = new;
	else
		alst = new;
}