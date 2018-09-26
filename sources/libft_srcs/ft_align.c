/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:02:47 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/26 13:40:10 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_align(size_t number, size_t divider)
{
	return (((((number - 1) / divider)) * divider) + divider);
}

size_t	ft_align4(size_t number)
{
	return (((((number) - 1) >> 2 ) << 2 ) + 4);
}