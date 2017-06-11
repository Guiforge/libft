/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_p_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:30:23 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/11 13:09:10 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*over_p_str(char *str, char *ag)
{
	if (str)
		ft_putstr_fd(str, 2);
	if (ag)
		ft_putstr_fd(ag, 2);
	ft_putendl_fd("", 2);
	return (NULL);
}
