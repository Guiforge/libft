/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:47:37 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/11 14:24:47 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	count;

	count = 0;
	if (!dest || !src)
		return (NULL);
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count = count + 1;
	}
	dest[count] = '\0';
	return (dest);
}
