/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:00:35 by gpouyat           #+#    #+#             */
/*   Updated: 2019/01/04 15:32:30 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}

void	*ft_memcpy_swap(void *dest, const void *src, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = n - 1;
	if (!dest || !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + j);
		i++;
		j--;
	}
	return (dest);
}
