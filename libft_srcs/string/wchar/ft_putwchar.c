/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:44:11 by gpouyat           #+#    #+#             */
/*   Updated: 2017/01/24 08:01:24 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar_fd(wchar_t c, int fd)
{
	if (c <= 127)
		ft_putchar_fd(c, fd);
	else if (c <= 2047)
	{
		ft_putchar_fd((c >> 6) + 0xC0, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c <= 65535)
	{
		ft_putchar_fd((c >> 12) + 0xE0, fd);
		ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c <= 1114111)
	{
		ft_putchar_fd((c >> 18) + 0xF0, fd);
		ft_putchar_fd(((c >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
}

void	ft_putwstr_fd(wchar_t *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putwchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putwchar(wchar_t c)
{
	ft_putwchar_fd(c, 1);
}

void	ft_putwstr(wchar_t *s)
{
	ft_putwstr_fd(s, 1);
}
