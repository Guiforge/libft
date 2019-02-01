/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:31:35 by gpouyat           #+#    #+#             */
/*   Updated: 2019/02/01 18:49:21 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
	{
		i++;
	}
	if (i == n)
		i--;
	return (((unsigned char)s1[i] - (unsigned char)s2[i]) % 127);
}

int		ft_strncmpi(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && ft_toupper(s1[i]) == ft_toupper(s2[i]) && i < n)
		i++;
	return ((ft_toupper(s1[i]) - ft_toupper(s2[i])) % 127);
}
