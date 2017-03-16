/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:12:29 by gpouyat           #+#    #+#             */
/*   Updated: 2016/11/14 19:37:28 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tab;

	if (s == NULL)
		return (NULL);
	tab = ft_strnew(len);
	if (tab == NULL)
		return (NULL);
	tab = ft_strncpy(tab, &s[start], len);
	return (tab);
}
