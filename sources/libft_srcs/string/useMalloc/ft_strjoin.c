/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:14:03 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/17 15:53:26 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;

	tab = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (tab != NULL)
	{
		if (s1)
			tab = ft_strcat(tab, s1);
		if (s2)
			tab = ft_strcat(tab, s2);
		return (tab);
	}
	return (NULL);
}

char	*ft_strjoincl(char *s1, char const *s2, int free)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	((free == 1 || free == 3) && s1) ? ft_fri((char **)&s1) : 0;
	((free == 2 || free == 3) && s2) ? ft_fri((char **)&s2) : 0;
	return (ret);
}
