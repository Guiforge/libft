/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 08:41:51 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/11 12:28:06 by gpouyat          ###   ########.fr       */
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

static int		ret(int len, char *format, int fd)
{
	int		i;

	format = pf_couleur(format);
	if (!format)
		return (len);
	ft_putstr_fd(format, fd);
	i = ft_strlen(format);
	free(format);
	return (i + len);
}

static int		chech_error_malloc(void)
{
	ft_putendl_fd("Printf ERROR Malloc\n", STDERR_FILENO);
	return (0);
}

int				print(int fd, char *frmt, va_list ap)
{
	t_flags		flags;
	int			i;
	char		*format;
	int			len;

	if (!(format = ft_strdup(frmt)))
		return (chech_error_malloc());
	i = 0;
	len = 0;
	while (format && format[i])
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
	return (ret(len, format, fd));
}
