/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_multiple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:26:22 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/02 11:22:34 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

ssize_t		ft_next_multiple(ssize_t number, size_t divisor)
{
	while ((number % divisor) && number < SSIZE_MAX)
		number++;
	return (number);
}
