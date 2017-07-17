/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:02:54 by gpouyat           #+#    #+#             */
/*   Updated: 2016/11/10 14:46:20 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] && i < size)
		i++;
	j = 0;
	while (src[j] && (i + j) < size - 1)
	{
		dest[j + i] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	j = ft_strlen(src);
	return (i + j);
}
