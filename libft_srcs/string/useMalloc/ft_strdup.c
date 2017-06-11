/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:17:11 by gpouyat           #+#    #+#             */
/*   Updated: 2016/11/14 19:35:59 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		len;
	int		i;

	if (src == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (!src)
		return (NULL);
	str = (char*)malloc((len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
