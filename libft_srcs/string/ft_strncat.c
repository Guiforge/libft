/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:52:58 by gpouyat           #+#    #+#             */
/*   Updated: 2016/11/14 19:38:07 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (dest[i])
		i = i + 1;
	while (src[a] && n > 0)
	{
		dest[a + i] = src[a];
		a = a + 1;
		n = n - 1;
	}
	dest[i + a] = '\0';
	return (dest);
}
