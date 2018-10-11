/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:12:06 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/11 14:30:34 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (0 - ((unsigned char *)s2)[0]);
	else if (!s2)
		return (((unsigned char *)s1)[0]);
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
