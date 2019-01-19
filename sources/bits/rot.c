/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 22:28:31 by gpouyat           #+#    #+#             */
/*   Updated: 2019/01/04 15:30:36 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

uint32_t	left_rot32(uint32_t nb, unsigned int count)
{
	return (nb << count) | (nb >> (32 - count));
}


uint32_t	right_rot32(uint32_t nb, unsigned int count)
{
	return (nb >> count) | (nb << (32 - count));
}

uint64_t	left_rot64(uint64_t nb, unsigned int count)
{
	return (nb << count) | (nb >> (64 - count));
}

uint64_t	right_rot64(uint64_t nb, unsigned int count)
{
	return (nb >> count) | (nb << (64 - count));
}