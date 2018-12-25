/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 22:33:31 by gpouyat           #+#    #+#             */
/*   Updated: 2018/12/25 22:33:31 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_array_byte b_join(t_array_byte dest, t_array_byte srcs)
{
	char	*str_join;

	if (!srcs.bytes || !dest.bytes)
		return(dest);
	if(!(str_join = ft_memalloc(dest.nb + srcs.nb)))
		b_clean(dest);
	else
	{
		ft_memcpy(str_join, dest.bytes, dest.nb);
		ft_memcpy(&str_join[dest.nb], srcs.bytes, srcs.nb);
		dest.bytes = str_join;
		dest.nb = dest.nb + srcs.nb;
	}
	return(dest);
}

t_array_byte b_join_secu(t_array_byte dest, t_array_byte srcs, size_t lvl)
{
	char	*str_join;

	if (!srcs.bytes || !dest.bytes)
		return(dest);
	if(!(str_join = ft_secu_malloc_lvl(dest.nb + srcs.nb, lvl)))
		b_clean_secu(dest);
	else
	{
		ft_memcpy(str_join, dest.bytes, dest.nb);
		ft_memcpy(&str_join[dest.nb], srcs.bytes, srcs.nb);
		dest.bytes = str_join;
		dest.nb = dest.nb + srcs.nb;
	}
	return(dest);
}

t_array_byte b_joinf(t_array_byte dest, t_array_byte srcs, int free)
{
	t_array_byte	ret;

	ret = b_join(dest, srcs);
	((free == 1 || free == 3)) ? b_clean(dest) : 0;
	((free == 2 || free == 3)) ? b_clean(srcs) : 0;
	return(ret);
}

t_array_byte b_joinf_secu(t_array_byte dest, t_array_byte srcs, int free,
																	size_t lvl)
{
	t_array_byte	ret;

	ret = b_join_secu(dest, srcs, lvl);
	((free == 1 || free == 3)) ? b_clean_secu(dest) : 0;
	((free == 2 || free == 3)) ? b_clean_secu(srcs) : 0;
	return(ret);
}