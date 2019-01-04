/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_new.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 21:03:10 by gpouyat           #+#    #+#             */
/*   Updated: 2019/01/04 15:26:19 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_array_byte	b_new(size_t nb)
{
	t_array_byte	new;

	new.bytes = ft_memalloc(nb);
	if (new.bytes)
		new.nb = nb;
	else
		new.nb = 0;
	return (new);
}

t_array_byte	b_new_secu(size_t nb, size_t lvl)
{
	t_array_byte	new;

	new.bytes = ft_secu_malloc_lvl(nb, lvl);
	if (new.bytes)
		new.nb = nb;
	else
		new.nb = 0;
	return (new);
}
