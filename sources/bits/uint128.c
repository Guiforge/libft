/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint128.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:30:20 by gpouyat           #+#    #+#             */
/*   Updated: 2019/01/18 18:38:13 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_uint128_t		set_simple_uint128(uint64_t x, t_bool is_little)
{
	t_uint128_t		ret;

	if (is_little)
	{
		ret.one = 0;
		ret.two = x;
	}
	else
	{
		ret.one = x;
		ret.two = 0;
	}
	return(ret);
}