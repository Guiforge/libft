/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 10:30:41 by gpouyat           #+#    #+#             */
/*   Updated: 2017/01/24 07:59:17 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*win_linesitoa(uintmax_t num, unsigned int base, int *i)
{
	char	*str;

	str = ft_strnew(nb_of_figure(num, base) + 2);
	while (num)
	{
		str[*i] = ((num % base <= 9) ? num % base + '0'\
				: num % base + 'A' - 10);
		num = num / base;
		*i = *i + 1;
	}
	return (str);
}

char	*ft_itoa_base(int nb, unsigned int base)
{
	int				neg;
	char			*str;
	int				i;
	unsigned int	num;

	i = 0;
	neg = 0;
	if (nb < 0)
	{
		num = -nb;
		if (base == 10)
			neg = 1;
		else if (base == 16 || base == 8)
			num = UINT_MAX - num + 1;
	}
	else
		num = nb;
	if (num == 0)
		return (ft_strdup("0"));
	str = win_linesitoa(num, base, &i);
	str[i] = (neg ? '-' : str[i]);
	str = rev(str);
	return (str);
}

char	*ft_itoa_plusbase(int nb, unsigned int base)
{
	int				neg;
	char			*str;
	int				i;
	unsigned int	num;

	i = 0;
	neg = 0;
	if (nb < 0)
	{
		num = -nb;
		if (base == 10)
			neg = 1;
		else if (base == 16 || base == 8)
			num = 4294967296 - num;
	}
	else
		num = nb;
	if (num == 0)
		return (ft_strdup("+0"));
	str = win_linesitoa(num, base, &i);
	str[i] = (neg ? '-' : '+');
	str = rev(str);
	return (str);
}
