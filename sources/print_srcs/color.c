/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 08:42:28 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/08 16:52:06 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char			*replace_couleur(char *format, int i)
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

char				*pf_couleur(char *format)
{
	int		i;

	if (!format)
		return (NULL);
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
