/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:59:54 by gpouyat           #+#    #+#             */
/*   Updated: 2019/04/29 15:39:21 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	int		neg;
	int		result;
	int		i;

	i = 0;
	neg = 1;
	result = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' && ft_isdigit(str[i + 1]))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (result * neg);
}

unsigned int		ft_atoi_unsigned(const char *str)
{
	unsigned int		result;
	int					i;

	i = 0;
	result = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' && ft_isdigit(str[i + 1]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (result);
}
