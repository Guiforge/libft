/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:10:21 by gpouyat           #+#    #+#             */
/*   Updated: 2016/11/10 13:06:26 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tab;

	if (size == 0)
		return (NULL);
	tab = (void *)malloc(size);
	if (tab == NULL)
		return (NULL);
	ft_bzero((void *)tab, size);
	return ((void *)tab);
}
