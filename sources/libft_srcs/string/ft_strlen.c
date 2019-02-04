/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 21:22:16 by gpouyat           #+#    #+#             */
/*   Updated: 2019/02/04 15:40:54 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str && str[i])
		i = i + 1;
	return (i);
}

size_t	ft_strlen_max(const char *str, size_t max)
{
	size_t		i;

	i = 0;
	while (str && str[i] && i < max)
		i = i + 1;
	return (i);
}
