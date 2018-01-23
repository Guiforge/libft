/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:07:41 by gpouyat           #+#    #+#             */
/*   Updated: 2018/01/23 12:15:22 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <libft.h>

static char base_ref[16] = {
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

void	ft_putnbr_base_fd(unsigned int number, unsigned int base, int fd)
{
	if (base > 16 || !base)
		return ;
	if (number >= base)
	{
		ft_putsize_t_base_fd(number / base, base, fd);
		ft_putsize_t_base_fd(number % base, base, fd);
	}
	if (number < (size_t)base)
		ft_putchar_fd(base_ref[number], fd);
}
