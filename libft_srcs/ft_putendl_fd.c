/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 21:18:17 by gpouyat           #+#    #+#             */
/*   Updated: 2016/11/07 12:21:11 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *str, int fd)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], fd);
		i = i + 1;
	}
	ft_putchar_fd('\n', fd);
}
