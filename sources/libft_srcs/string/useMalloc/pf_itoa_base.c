/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 10:30:41 by gpouyat           #+#    #+#             */
/*   Updated: 2017/01/24 08:07:40 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	nb_of_figure(uintmax_t nb, uintmax_t base)
{
	uintmax_t	figure;

	figure = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		figure++;
		nb = nb / base;
	}
	return (figure);
}

char		*rev(char *str)
{
	char		*rev;
	uintmax_t	i;
	uintmax_t	a;

	a = 0;
	i = 0;
	i = ft_strlen(str);
	rev = ft_strnew(i);
	i--;
	while (str[a])
	{
		rev[a] = str[i];
		a++;
		i--;
	}
	free(str);
	return (rev);
}

char		*pf_itoa_base(intmax_t nb, uintmax_t base)
{
	int				neg;
	char			*str;
	int				i;
	uintmax_t		num;

	i = 0;
	neg = 0;
	if (nb < 0)
	{
		num = -nb;
		if (base == 10 || base == 2)
			neg = 1;
		else if (base == 16 || base == 8)
			num = ULLONG_MAX - num + 1;
	}
	else
		num = nb;
	if (num == 0)
		return (ft_strdup("0"));
	str = win_linesitoa(num, base, &i);
	if (neg)
		str[i] = '-';
	str = rev(str);
	return (str);
}

char		*pf_uitoa_base(uintmax_t nb, uintmax_t base)
{
	char	*str;
	int		i;

	i = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	str = win_linesitoa(nb, base, &i);
	str = rev(str);
	return (str);
}

char		*pf_itoa_plusbase(intmax_t nb, uintmax_t base)
{
	int			neg;
	char		*str;
	int			i;
	uintmax_t	num;

	i = 0;
	neg = 0;
	if (nb < 0)
	{
		num = -nb;
		if (base == 10)
			neg = 1;
		else if (base == 16 || base == 8)
			num = ULLONG_MAX - num + 1;
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
