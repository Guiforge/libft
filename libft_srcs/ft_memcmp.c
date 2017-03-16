/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@42gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:12:06 by gpouyat           #+#    #+#             */
/*   Updated: 2016/11/11 16:05:55 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (s1 && s2)
	{
		while (((char *)s1)[i] == ((char *)s2)[i] && i <= n)
		{
			i++;
			if (i == n)
				return (0);
		}
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
