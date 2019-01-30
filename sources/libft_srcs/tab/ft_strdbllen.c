/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdbllen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:06:22 by gpouyat           #+#    #+#             */
/*   Updated: 2019/01/30 12:10:22 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

size_t ft_strdbllen(const char **array)
{
	size_t		i;

	i = 0;
	if (!array)
		return (0);
	while(array[i])
		i++;
	return(i);
}