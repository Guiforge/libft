/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:42:11 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/11 12:28:51 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_inbase(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	else
		return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'A' + base - 10));
}

int			ft_atoi_base(char *str, int base)
{
	int	neg;
	int	ret;

	ret = 0;
	if (!str)
		return (0);
	while (*str == ' ' || *str == '\t')
		str++;
	neg = (*str == '-') ? 1 : 0;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_inbase(*str, base))
	{
		if (*str >= '0' && *str <= '9')
			ret = ret * base + (*str - '0');
		else
			ret = ret * base + (*str - 'A' + 10);
		str++;
	}
	return (neg ? -ret : ret);
}
