/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:07:39 by gpouyat           #+#    #+#             */
/*   Updated: 2018/12/25 22:27:13 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	b_print(int size, void const * const nb)
{
	unsigned char *b;
	unsigned char bit;
	int j;

	b = (unsigned char*) nb;
	while( --size >= 0 )
	{
		j = 8;
		while (--j >= 0)
		{
			bit = (b[size] >> j) & 1;
			ft_putnbr(bit);
		}
	}
}

void	b_print_array(t_array_byte array, char *split)
{
	size_t i;

	i = 0;
	while (i < array.nb)
	{
		if (i)
			ft_putstr(split);
		b_print(sizeof(char), &array.bytes[i]);
		++i;
	}
	ft_putchar('\n');
}