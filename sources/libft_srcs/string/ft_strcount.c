/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:06:22 by gpouyat           #+#    #+#             */
/*   Updated: 2019/03/15 15:59:30 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

size_t	ft_strcount(char *str, char c)
{
	size_t count;
	size_t i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

size_t	ft_memcount(char *str, char c, size_t len_str)
{
	size_t count;
	size_t i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (i < len_str)
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
