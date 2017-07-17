/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:20:22 by gpouyat           #+#    #+#             */
/*   Updated: 2017/02/04 09:22:11 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*next_x(t_flags flags, char *tmp)
{
	if (ft_atoi_base(tmp, 16) < 0 && !flags.type[0] && ft_strlen(tmp) == 16)
		tmp = ft_replace(tmp, "", 0, 8);
	else if (ft_atoi_base(tmp, 16) < 0 && flags.type[0] == 'h' &&\
							flags.type[1] == 0 && ft_strlen(tmp) == 16)
		tmp = ft_replace(tmp, "", 0, 12);
	else if (ft_atoi_base(tmp, 16) < 0 && flags.type[0] == 'h' &&\
							ft_strlen(tmp) == 16)
		tmp = ft_replace(tmp, "", 0, 14);
	if (flags.preci == 0 && ft_atoi(tmp) == 0)
		tmp = ft_replace(tmp, "", 0, 1);
	return (tmp);
}

char		*ft_x(t_flags flags, char *format, va_list ap, int **i)
{
	char	*tmp;
	char	*tmp2;

	tmp = pf_itoa_base(ft_tnum(flags, ap), 16);
	tmp = next_x(flags, tmp);
	tmp2 = preci(flags, tmp);
	free(tmp);
	if (((ft_atoi(tmp2) != 0) && flags.hash) || flags.convers == 'p')
		tmp2 = ft_replace(tmp2, "0X", 0, 0);
	tmp = minus(flags, tmp2);
	free(tmp2);
	tmp2 = width(flags, tmp);
	free(tmp);
	tmp2 = (flags.convers == 'X' ? tmp2 : ft_strtolower(tmp2));
	format = ft_replace(format, tmp2, **i, flags.size + 1);
	**i = **i + ft_strlen(tmp2) - 1;
	free(tmp2);
	return (format);
}
