/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secu_malloc_debug.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 23:10:21 by gpouyat           #+#    #+#             */
/*   Updated: 2018/12/25 23:24:08 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void ft_secu_malloc_debug(void)
{
	t_mem			*mem;
	t_secu_malloc	*tmp;

	if (!(mem = get_mem()))
		return ;
	tmp = mem->first;
	ft_putendl("--------- DEBUG SECU MALLOC ---------");
	while (tmp)
	{
		ft_printf("Addr:%#lx, lvl:%lu \n", tmp->ptr, tmp->lvl);
		tmp = tmp->next;
	}
	ft_putendl("--------- ****************** ---------");

}