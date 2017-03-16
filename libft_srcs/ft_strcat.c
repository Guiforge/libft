/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:52:58 by gpouyat           #+#    #+#             */
/*   Updated: 2016/11/08 19:31:45 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (dest[i])
		i = i + 1;
	while (src[a])
	{
		dest[a + i] = src[a];
		a = a + 1;
	}
	dest[a + i] = '\0';
	return (dest);
}
