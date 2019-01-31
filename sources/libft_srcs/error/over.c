/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:30:23 by gpouyat           #+#    #+#             */
/*   Updated: 2019/01/31 21:21:06 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		over(char *str, int nb)
{
	ft_putendl_fd(str, 2);
	return (nb);
}

int		over_log(int ret, enum e_logger_lvl lvl, char *fmt, ...)
{
	va_list		list;

	va_start(list, fmt);
	print(STDERR_FILENO, (char *)fmt, list);
	log_log(lvl, fmt, list);
	va_end(list);
	return(ret);
}