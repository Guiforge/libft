/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:32:20 by gpouyat           #+#    #+#             */
/*   Updated: 2017/02/04 09:21:55 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_flags	zero(t_flags flags)
{
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.convers = 0;
	flags.type[0] = 0;
	flags.type[1] = 0;
	flags.type[2] = 0;
	flags.minus = 0;
	flags.preci = -1;
	flags.width = 0;
	flags.zero = 0;
	flags.size = 0;
	return (flags);
}

char			*replace_couleur(char *format, int i)
{
	if (!ft_strncmp(&format[i], "{red}", 5))
		format = ft_replace(format, C_RED, i, 5);
	else if (!ft_strncmp(&format[i], "{no}", 4))
		format = ft_replace(format, C_NONE, i, 4);
	else if (!ft_strncmp(&format[i], "{blue}", 6))
		format = ft_replace(format, C_BLUE, i, 6);
	else if (!ft_strncmp(&format[i], "{green}", 7))
		format = ft_replace(format, C_GREEN, i, 7);
	else if (!ft_strncmp(&format[i], "{yellow}", 8))
		format = ft_replace(format, C_YELLOW, i, 8);
	else if (!ft_strncmp(&format[i], "{Bred}", 6))
		format = ft_replace(format, B_RED, i, 6);
	else if (!ft_strncmp(&format[i], "{Bblue}", 7))
		format = ft_replace(format, B_BLUE, i, 7);
	else if (!ft_strncmp(&format[i], "{Bgreen}", 8))
		format = ft_replace(format, B_GREEN, i, 8);
	else if (!ft_strncmp(&format[i], "{Byellow}", 9))
		format = ft_replace(format, B_YELLOW, i, 9);
	return (format);
}

char			*pf_couleur(char *format)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '{')
		{
			format = replace_couleur(format, i);
		}
		i++;
	}
	return (format);
}

static int		ret(int len, char *format, va_list ap)
{
	int		i;

	format = pf_couleur(format);
	ft_putstr(format);
	va_end(ap);
	i = ft_strlen(format);
	free(format);
	return (i + len);
}

int				ft_printf(char *frmt, ...)
{
	va_list		ap;
	t_flags		flags;
	int			i;
	char		*format;
	int			len;

	format = ft_strdup(frmt);
	i = 0;
	len = 0;
	va_start(ap, frmt);
	while (format[i])
	{
		if (format[i] == '%')
		{
			flags = zero(flags);
			flags = get_struct(flags, &format[i]);
			flags.type[0] = ((flags.convers == 'D' || flags.convers == 'O') ?
					flags.type[0] = 'l' : flags.type[0]);
			format = ft_convers(&flags, format, ap, &i);
			if (flags.type[2] == -1)
				len++;
		}
		i++;
	}
	return (ret(len, format, ap));
}
