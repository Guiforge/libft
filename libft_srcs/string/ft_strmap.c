/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:17:49 by gpouyat           #+#    #+#             */
/*   Updated: 2016/11/14 18:08:07 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*tab;
	unsigned	int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	tab = ft_strdup((const char *)s);
	if (tab != NULL && (*f) != NULL)
	{
		while (s[i])
		{
			tab[i] = f(s[i]);
			i++;
		}
		return (tab);
	}
	return (NULL);
}
