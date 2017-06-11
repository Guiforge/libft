/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:14:03 by gpouyat           #+#    #+#             */
/*   Updated: 2017/02/06 15:16:24 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;

	if (s1 == NULL)
		return (NULL);
	tab = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (tab != NULL)
	{
		tab = ft_strcat(tab, s1);
		tab = ft_strcat(tab, s2);
		return (tab);
	}
	return (NULL);
}

char	*ft_fstrjoin(char *s1, char const *s2)
{
	char	*tab;

	if (s1 == NULL)
		return (NULL);
	tab = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (tab != NULL)
	{
		tab = ft_strcat(tab, s1);
		tab = ft_strcat(tab, s2);
		free(s1);
		return (tab);
	}
	return (NULL);
}

char	*ft_strjoinf(char const *s1, char *s2)
{
	char	*tab;

	if (s1 == NULL)
		return (NULL);
	tab = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (tab != NULL)
	{
		tab = ft_strcat(tab, s1);
		tab = ft_strcat(tab, s2);
		free(s2);
		return (tab);
	}
	return (NULL);
}
