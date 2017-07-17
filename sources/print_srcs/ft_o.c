/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 14:46:44 by gpouyat           #+#    #+#             */
/*   Updated: 2017/02/04 09:21:47 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*pfoitoa_short(short int nb, uintmax_t base)
{
	char				*str;
	int					i;
	unsigned short int	num;

	i = 0;
	if (nb < 0)
	{
		num = -nb;
		num = USHRT_MAX - num + 1;
	}
	else
		num = nb;
	if (num == 0)
		return (ft_strdup("0"));
	str = ft_strnew(nb_of_figure(num, base) + 2);
	while (num)
	{
		str[i] = ((num % base <= 9) ? num % base + '0' : num % base + 'A' - 10);
		num = num / base;
		i++;
	}
	str = rev(str);
	return (str);
}

char	*pfoitoa_char(char nb, uintmax_t base)
{
	char			*str;
	int				i;
	unsigned char	num;

	i = 0;
	if (nb < 0)
	{
		num = -nb;
		if (base == 16 || base == 8)
			num = UCHAR_MAX - num + 1;
	}
	else
		num = nb;
	if (num == 0)
		return (ft_strdup("0"));
	str = ft_strnew(nb_of_figure(num, base) + 2);
	while (num)
	{
		str[i] = ((num % base <= 9) ? num % base + '0' : num % base + 'A' - 10);
		num = num / base;
		i++;
	}
	str = rev(str);
	return (str);
}

char	*o_itoa(t_flags flags, va_list ap)
{
	uintmax_t num;

	num = ft_tnum(flags, ap);
	if (flags.type[0] == 'h' && flags.type[1] == 'h')
		return (pfoitoa_char(num, 8));
	else if (flags.type[0] == 'h')
		return (pfoitoa_short(num, 8));
	else if (flags.type[0] == 0)
		return (ft_itoa_base(num, 8));
	return (pf_itoa_base(num, 8));
}

char	*ft_o(t_flags flags, char *format, va_list ap, int **i)
{
	char	*tmp;
	char	*tmp2;

	tmp = o_itoa(flags, ap);
	if (ft_atoi(tmp) == 0 && !flags.hash && flags.preci != -1)
		tmp = ft_replace(tmp, "", 0, 1);
	if (flags.hash && ft_atoi(tmp) != 0)
		tmp = ft_replace(tmp, "0", 0, 0);
	tmp2 = preci(flags, tmp);
	free(tmp);
	tmp = minus(flags, tmp2);
	free(tmp2);
	tmp2 = width(flags, tmp);
	free(tmp);
	tmp2 = (flags.convers == 'O' ? tmp2 : ft_strtolower(tmp2));
	format = ft_replace(format, tmp2, **i, flags.size + 1);
	**i = **i + ft_strlen(tmp2) - 1;
	free(tmp2);
	return (format);
}
