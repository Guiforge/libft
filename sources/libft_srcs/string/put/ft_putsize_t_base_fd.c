/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsize_t_base_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:33:53 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/02 11:26:54 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	g_base_ref[16] = {
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

void		ft_putsize_t_base_fd(size_t number, unsigned int base, int fd)
{
	if (base > 16 || !base)
		return ;
	if (number >= (size_t)base)
	{
		ft_putsize_t_base_fd(number / base, base, fd);
		ft_putsize_t_base_fd(number % base, base, fd);
	}
	if (number < (size_t)base)
		ft_putchar_fd(g_base_ref[number], fd);
}
