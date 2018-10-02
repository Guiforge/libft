/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:32:20 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/02 11:30:24 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int				ft_printf(char *frmt, ...)
{
	va_list		list;
	int			ret;

	ret = 0;
	if (frmt)
	{
		va_start(list, frmt);
		ret = print(STDOUT_FILENO, frmt, list);
		va_end(list);
	}
	return (ret);
}
