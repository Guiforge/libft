/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:50:04 by gpouyat           #+#    #+#             */
/*   Updated: 2018/12/27 17:53:25 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_vprintf(const char *format, va_list ap)
{
	return(print(STDOUT_FILENO, (char *)format, ap));
}

int	ft_vdprintf(int fd,const char *format, va_list ap)
{
	return(print(fd, (char *)format, ap));
}