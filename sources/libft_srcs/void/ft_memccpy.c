/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:24:08 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/11 14:12:57 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (i < n)
	{
		((char*)dest)[i] = ((char*)src)[i];
		if (((char*)dest)[i] == c)
		{
			i++;
			return (dest + i);
		}
		i++;
	}
	return (NULL);
}
