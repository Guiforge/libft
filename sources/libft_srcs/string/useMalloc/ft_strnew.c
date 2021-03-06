/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:34:46 by gpouyat           #+#    #+#             */
/*   Updated: 2019/02/11 16:13:47 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;

	tab = (char *)ft_memalloc(size + 1);
	if (tab == NULL)
		return (NULL);
	return (tab);
}
