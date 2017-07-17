/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdblprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:32:42 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/17 16:02:31 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdblprint(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return
	ft_putstr("Array{");
	while(tab[i])
	{
		ft_printf("[%d] = %s\n", i, tab[i]);
		i++;
	}
	ft_putstr("     }");
}
