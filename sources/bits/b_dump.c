/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_dump.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 22:19:18 by gpouyat           #+#    #+#             */
/*   Updated: 2019/01/04 15:24:52 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_array_byte	b_dump(const char *s, size_t len)
{
	t_array_byte	dump;

	dump = b_new(len);
	if (dump.bytes)
		ft_memcpy(dump.bytes, s, len);
	return (dump);
}

t_array_byte	b_dump_secu(const char *s, size_t len, size_t lvl)
{
	t_array_byte	dump;

	dump = b_new_secu(len, lvl);
	if (dump.bytes)
		ft_memcpy(dump.bytes, s, len);
	return (dump);
}
