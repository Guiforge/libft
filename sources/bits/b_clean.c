/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_clean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 22:37:28 by gpouyat           #+#    #+#             */
/*   Updated: 2019/01/04 15:24:45 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_array_byte	b_clean(t_array_byte arr)
{
	ft_memdel((void **)&arr.bytes);
	arr.nb = 0;
	return (arr);
}

t_array_byte	b_clean_secu(t_array_byte arr)
{
	ft_secu_free(arr.bytes);
	arr.bytes = NULL;
	arr.nb = 0;
	return (arr);
}
