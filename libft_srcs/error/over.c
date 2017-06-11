/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:30:23 by gpouyat           #+#    #+#             */
/*   Updated: 2017/02/27 14:50:53 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		over(char *str, int nb)
{
	ft_putendl_fd(str, 2);
	return (nb);
}

int		over_p(char *str, char *ag, int nb)
{
	if (str)
		ft_putstr_fd(str, 2);
	if (ag)
		ft_putstr_fd(ag, 2);
	ft_putendl_fd("", 2);
	return (nb);
}

void	*over_p_str(char *str, char *ag)
{
	if (str)
		ft_putstr_fd(str, 2);
	if (ag)
		ft_putstr_fd(ag, 2);
	ft_putendl_fd("", 2);
	return (NULL);
}

void	*over_str(char *str)
{
	ft_putendl(str);
	return (NULL);
}
