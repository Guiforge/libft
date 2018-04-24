/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 08:39:39 by gpouyat           #+#    #+#             */
/*   Updated: 2018/04/24 08:54:51 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int				ft_dprintf(int fd, char *frmt, ...)
{
		va_list		list;
		int			ret;

	ret = 0;
	if (frmt)
	{
		va_start(list, frmt);
		ret = print(fd, frmt, list);
		va_end(list);
	}
	return(ret);
}