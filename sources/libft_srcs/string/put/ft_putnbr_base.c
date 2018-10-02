/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:07:41 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/02 11:28:20 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	g_base_up[16] = {
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'A',
	'B',
	'C',
	'D',
	'E',
	'F'
};

static char	g_base_low[16] = {
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'a',
	'b',
	'c',
	'd',
	'e',
	'f'
};

static void	ft_putnbr_base_fd_up(unsigned int number, unsigned int base,
				int fd, t_bool up)
{
	char	c;

	if (base > 16 || !base)
		return ;
	if (number >= base)
	{
		ft_putsize_t_base_fd(number / base, base, fd);
		ft_putsize_t_base_fd(number % base, base, fd);
	}
	if (number < (size_t)base)
	{
		c = up ? g_base_up[number] : g_base_low[number];
		ft_putchar_fd(c, fd);
	}
}

void		ft_putnbr_base_fd(unsigned int number, unsigned int base, int fd)
{
	ft_putnbr_base_fd_up(number, base, fd, True);
}

void		t_putnbr_base_fd_low(unsigned int number, unsigned int base, int fd)
{
	ft_putnbr_base_fd_up(number, base, fd, False);
}
