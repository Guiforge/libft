/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:58:37 by gpouyat           #+#    #+#             */
/*   Updated: 2017/02/04 09:22:22 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			get_conver(char c)
{
	char	*tab;
	char	result;
	int		i;

	i = 0;
	tab = ft_strdup("sSpdDioOuUxXcCb%%");
	while ((result = tab[i]))
	{
		if (c == tab[i])
		{
			free(tab);
			return (result);
		}
		i++;
	}
	free(tab);
	return (0);
}

t_flags			get_type(char *format, t_flags flags)
{
	if (format[0] == 'z')
		flags.type[0] = 'z';
	else if (format[0] == 'j')
		flags.type[0] = 'j';
	else if (format[0] == 'l' && format[1] != 'l')
		flags.type[0] = 'l';
	else if (format[0] == 'h' && format[1] != 'h')
		flags.type[0] = 'h';
	else if (format[0] == 'l' && format[1] == 'l')
	{
		flags.type[0] = 'l';
		flags.type[1] = 'l';
		flags.size++;
	}
	else if (format[0] == 'h' && format[1] == 'h')
	{
		flags.type[0] = 'h';
		flags.type[1] = 'h';
		flags.size++;
	}
	flags.size++;
	return (flags);
}

t_flags			get_flags(t_flags flags, char *format, int i)
{
	if (format[i] == '#')
		flags.hash = 1;
	else if (format[i] == ' ')
		flags.space = 1;
	else if (format[i] == '+')
		flags.plus = 1;
	else if (format[i] == '-')
		flags.minus = 1;
	else if (format[i] == '0')
		flags.zero = 1;
	return (flags);
}

static t_flags	win_lines(t_flags flags, char *format, int i)
{
	flags.size = i;
	flags.convers = get_conver(format[i]);
	if (!flags.convers)
	{
		flags = get_type(&format[i], flags);
		flags.convers = get_conver(format[flags.size]);
	}
	flags.zero = ((flags.convers == 'd' && flags.preci != -1) ? 0 : flags.zero);
	if (flags.convers == 'p')
	{
		flags.hash = 1;
		flags.type[0] = 'l';
	}
	else if (flags.convers == 'D')
		flags.type[0] = 'l';
	return (flags);
}

t_flags			get_struct(t_flags flags, char *format)
{
	int	i;

	i = 1;
	while (format[i] == '#' || format[i] == ' ' || format[i] == '+'
			|| format[i] == '-' || format[i] == '0')
	{
		flags = get_flags(flags, format, i);
		i++;
	}
	flags.width = ((ft_isdigit(format[i])) ? ft_atoi(&format[i]) : flags.width);
	flags.minus = ((flags.minus && flags.width) ? flags.width : flags.minus);
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == '.')
	{
		i++;
		flags.preci = ft_atoi(&format[i]);
	}
	while (ft_isdigit(format[i]))
		i++;
	return (win_lines(flags, format, i));
}
