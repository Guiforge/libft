/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:20:24 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/16 15:29:54 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	temp;

	i = 0;
	j = 0;
	if (!big || !little)
		return (NULL)
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		temp = i;
		while (big[temp] == little[j] && big[temp] && little[j])
		{
			temp++;
			j++;
			if (little[j] == '\0')
				return ((char *)(&big[i]));
		}
		i++;
	}
	return (NULL);
}
