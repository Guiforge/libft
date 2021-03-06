/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_secu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 12:47:29 by gpouyat           #+#    #+#             */
/*   Updated: 2018/12/25 23:10:44 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnew_secu(size_t size, size_t lvl)
{
	char	*tab;

	tab = (char *)ft_secu_malloc_lvl(size + 1, lvl);
	if (tab == NULL)
		return (NULL);
	ft_bzero((void *)tab, size + 1);
	return (tab);
}
