/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:36:30 by gpouyat           #+#    #+#             */
/*   Updated: 2017/02/04 09:21:32 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*preci(t_flags flags, char *str)
{
	char	*tmp;
	char	*complet;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str) - flags.plus - (str[0] == '-');
	if (flags.preci > len)
	{
		tmp = ft_strnew(flags.preci - len);
		if (str[0] == '+' || str[0] == '-')
		{
			tmp[i] = (str[0] == '+') ? '+' : '-';
			str[0] = '0';
			i++;
		}
		while (i != flags.preci - len)
			tmp[i++] = '0';
		complet = ft_strjoin(tmp, str);
		free(tmp);
		return (complet);
	}
	return (ft_strdup(str));
}

char	*width(t_flags flags, char *str)
{
	char	*tmp;
	char	*complet;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (flags.width <= len)
		return (ft_strdup(str));
	tmp = ft_strnew(flags.width - len);
	str[1] = ((flags.hash && flags.zero && str[1]) ? '0' : str[1]);
	while (i <= flags.width - len - 1)
	{
		tmp[i] = (flags.zero ? '0' : ' ');
		i++;
	}
	complet = ft_strjoin(tmp, str);
	if ((str[0] == '-' || str[0] == '+' || str[0] == ' ') && flags.zero)
	{
		complet[0] = str[0];
		complet[flags.width - len] = (flags.zero ? '0' : ' ');
	}
	complet[1] = ((flags.hash && flags.zero && complet[1]) ? 'x' : complet[1]);
	free(tmp);
	return (complet);
}

char	*minus(t_flags flags, char *str)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	if (flags.minus <= len)
		return (ft_strdup(str));
	tmp = ft_strnew(flags.minus + len);
	tmp = ft_strcpy(tmp, str);
	while (len <= flags.minus - 1)
	{
		tmp[len] = ' ';
		len++;
	}
	return (tmp);
}
