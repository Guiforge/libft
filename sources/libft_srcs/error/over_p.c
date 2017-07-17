/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:30:23 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/11 13:09:21 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		over_p(char *str, char *ag, int nb)
{
	if (str)
		ft_putstr_fd(str, 2);
	if (ag)
		ft_putstr_fd(ag, 2);
	ft_putendl_fd("", 2);
	return (nb);
}
