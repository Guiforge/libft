/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:04:27 by gpouyat           #+#    #+#             */
/*   Updated: 2017/02/04 09:22:30 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

intmax_t	ft_tnum(t_flags flags, va_list ap)
{
	intmax_t	num;
	char		c;
	short int	i;

	num = 0;
	if (flags.type[0] == 'h' && flags.type[1] == 'h')
		return (c = va_arg(ap, int));
	else if (flags.type[0] == 'h')
		return (i = va_arg(ap, int));
	else if (flags.type[0] == 'l' && flags.type[1] == 'l')
		return (num = va_arg(ap, long long int));
	else if (flags.type[0] == 'l')
		return (num = va_arg(ap, long int));
	else if (flags.type[0] == 'j')
		return (num = va_arg(ap, intmax_t));
	else if (flags.type[0] == 'z')
		return (num = va_arg(ap, ssize_t));
	return (num = va_arg(ap, int));
}

uintmax_t	ft_utnum(t_flags flags, va_list ap)
{
	uintmax_t			num;
	unsigned char		c;
	unsigned short int	i;

	num = 0;
	if (flags.type[0] == 'h' && flags.type[1] == 'h')
		return (c = va_arg(ap, unsigned int));
	else if (flags.type[0] == 'h')
		return (i = va_arg(ap, unsigned int));
	else if (flags.type[0] == 'l' && flags.type[1] == 'l')
		return (num = va_arg(ap, unsigned long long int));
	else if (flags.type[0] == 'l')
		return (num = va_arg(ap, unsigned long int));
	else if (flags.type[0] == 'j')
		return (num = va_arg(ap, uintmax_t));
	else if (flags.type[0] == 'z')
		return (num = va_arg(ap, size_t));
	return (num = va_arg(ap, unsigned int));
}
