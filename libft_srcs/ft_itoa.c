/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:16:53 by gpouyat           #+#    #+#             */
/*   Updated: 2017/01/13 17:58:58 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_of_figures(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_number_of_ufigures(unsigned int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*str;
	int		sign;

	sign = 1;
	size = ft_number_of_figures(n);
	str = (char *)malloc(sizeof(str) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[size] = '\0';
	size--;
	if (n < 0)
	{
		str[0] = '-';
		sign = -1;
	}
	while (n)
	{
		str[size] = (((n % 10) * sign) + '0');
		size--;
		n = n / 10;
	}
	return (str);
}

char		*ft_uitoa(unsigned int n)
{
	int		size;
	char	*str;

	size = ft_number_of_ufigures(n);
	str = (char *)malloc(sizeof(str) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[size] = '\0';
	size--;
	while (n)
	{
		str[size] = ((n % 10) + '0');
		size--;
		n = n / 10;
	}
	return (str);
}
