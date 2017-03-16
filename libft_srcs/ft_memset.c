/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:46:45 by gpouyat           #+#    #+#             */
/*   Updated: 2016/11/11 12:33:30 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (s);
	ptr = (unsigned char*)s;
	while (n)
	{
		ptr[i] = (unsigned char)c;
		n--;
		i++;
	}
	return (s);
}
