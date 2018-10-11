/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:08:21 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/11 14:55:35 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*end_format(t_flags flags, char *format, int **i, char *tmp)
{
	char	*tmp2;

	if (!format || !i || !tmp)
	{
		free(tmp);
		return (NULL);
	}
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

char		*ft_s(t_flags flags, char *format, va_list ap, int **i)
{
	char	*tmp;
	char	*tmp2;

	if (!format || !i || !*i)
		return (NULL);
	tmp = va_arg(ap, char*);
	if (tmp && (tmp = ft_strdup(tmp)))
	{
		if ((unsigned int)flags.preci < (unsigned int)ft_strlen(tmp))
			tmp[flags.preci] = 0;
		tmp2 = (ft_strcmp(tmp, "") ? minus(flags, tmp) : ft_strdup(tmp));
		free(tmp);
		tmp = width(flags, tmp2);
		free(tmp2);
		format = ft_replace(format, tmp, **i, flags.size + 1);
		**i = **i + ft_strlen(tmp) - 1;
		free(tmp);
	}
	else
		format = ft_replace(format, "(null)", **i, flags.size + 1);
	return (format);
}

char		*ft_c(t_flags **flgs, char *format, va_list ap, int **i)
{
	char	*tmp;
	int		c;
	t_flags	flags;

	if (!format || !i || !*i)
		return (NULL);
	flags = **flgs;
	if (!(c = va_arg(ap, int)))
	{
		(**flgs).type[2] = -1;
		flags.preci = 0;
		flags.width--;
	}
	if (!(tmp = ft_strnew(1)))
		return (NULL);
	tmp[0] = (char)c;
	return (end_format(flags, format, i, tmp));
}

char		*ft_upc(t_flags **flgs, char *format, va_list ap, int **i)
{
	char	*tmp;
	int		c;
	t_flags	flags;

	if (!format || !i || !*i)
		return (NULL);
	flags = **flgs;
	c = va_arg(ap, wchar_t);
	if (c == 0)
	{
		flags.type[2] = -1;
		return (ft_replace(format, "\0", **i, flags.size + 1));
	}
	tmp = ft_getchar(c);
	return (end_format(flags, format, i, tmp));
}

char		*ft_ups(t_flags flags, char *format, va_list ap, int **i)
{
	char	*tmp;
	char	*tmp2;

	if (!format || !i || !*i)
		return (NULL);
	tmp = ft_getwstr(va_arg(ap, wchar_t*));
	if (tmp)
	{
		if ((unsigned int)flags.preci < (unsigned int)ft_strlen(tmp))
			tmp[flags.preci] = 0;
		tmp2 = minus(flags, tmp);
		free(tmp);
		tmp = width(flags, tmp2);
		free(tmp2);
		format = ft_replace(format, tmp, **i, flags.size + 1);
		**i = **i + ft_strlen(tmp) - 1;
		free(tmp);
	}
	else
		format = ft_replace(format, "(null)", **i, flags.size + 1);
	return (format);
}
