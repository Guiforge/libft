/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 07:42:13 by gpouyat           #+#    #+#             */
/*   Updated: 2017/02/04 09:22:42 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_d(t_flags flags, char *format, va_list ap, int **i)
{
	char	*tmp;
	char	*tmp2;
	int		base;

	base = (flags.convers == 'b' ? 2 : 10);
	tmp = (flags.plus ? (pf_itoa_plusbase(ft_tnum(flags, ap), base)) :
					(pf_itoa_base(ft_tnum(flags, ap), base)));
	if (flags.preci == 0 && ft_atoi(tmp) == 0)
		tmp = ft_replace(tmp, "", 0, 1);
	tmp2 = preci(flags, tmp);
	free(tmp);
	tmp = minus(flags, tmp2);
	free(tmp2);
	if (flags.space && !flags.plus && ft_atoi(tmp) >= 0)
		tmp = ft_replace(tmp, " ", 0, 0);
	tmp2 = width(flags, tmp);
	free(tmp);
	format = ft_replace(format, tmp2, **i, flags.size + 1);
	**i = **i + ft_strlen(tmp2) - 1;
	free(tmp2);
	return (format);
}

char	*ft_u(t_flags flags, char *format, va_list ap, int **i)
{
	char	*tmp;
	char	*tmp2;

	if (flags.convers == 'U')
	{
		flags.type[0] = 'l';
		flags.type[1] = 0;
	}
	tmp = pf_uitoa_base(ft_utnum(flags, ap), 10);
	if (flags.preci == 0 && ft_atoi(tmp) == 0)
		tmp = ft_replace(tmp, "", 0, 1);
	tmp2 = preci(flags, tmp);
	free(tmp);
	tmp = minus(flags, tmp2);
	free(tmp2);
	tmp2 = width(flags, tmp);
	free(tmp);
	format = ft_replace(format, tmp2, **i, flags.size + 1);
	**i = **i + ft_strlen(tmp2) - 1;
	free(tmp2);
	return (format);
}

char	*ft_hs(t_flags flags, char *format, int **i)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup("%");
	tmp2 = minus(flags, tmp);
	free(tmp);
	tmp = width(flags, tmp2);
	free(tmp2);
	format = ft_replace(format, tmp, **i, flags.size + 1);
	**i = **i + ft_strlen(tmp) - 1;
	free(tmp);
	return (format);
}

char	*ft_convers(t_flags *flgs, char *format, va_list ap, int *i)
{
	t_flags	flags;

	flags = *flgs;
	if (flags.convers == 'd' || flags.convers == 'i' || flags.convers == 'D'\
				|| flags.convers == 'b')
		return (ft_d(flags, format, ap, &i));
	else if (flags.convers == 's')
		return (ft_s(flags, format, ap, &i));
	else if (flags.convers == '%')
		return (ft_hs(flags, format, &i));
	else if (flags.convers == 'x' || flags.convers == 'X'\
				|| flags.convers == 'p')
		return (ft_x(flags, format, ap, &i));
	else if (flags.convers == 'o' || flags.convers == 'O')
		return (ft_o(flags, format, ap, &i));
	else if (flags.convers == 'c')
		return (ft_c(&flgs, format, ap, &i));
	else if (flags.convers == 'u' || flags.convers == 'U')
		return (ft_u(flags, format, ap, &i));
	else if (flags.convers == 'C')
		return (ft_upc(&flgs, format, ap, &i));
	else if (flags.convers == 'S')
		return (ft_ups(flags, format, ap, &i));
	return (format);
}
