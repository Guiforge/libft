/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_wrappers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:43:46 by gpouyat           #+#    #+#             */
/*   Updated: 2018/12/27 19:07:46 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	log_fatal(const char *fmt, ...)
{
	va_list		list;

	va_start(list, fmt);
	log_log(LOG_LVL_FATAL, fmt, list);
	va_end(list);
}

void	log_error(const char *fmt, ...)
{
	va_list		list;

	va_start(list, fmt);
	log_log(LOG_LVL_ERROR, fmt, list);
	va_end(list);
}

void	log_warn(const char *fmt, ...)
{
	va_list		list;

	va_start(list, fmt);
	log_log(LOG_LVL_WARN, fmt, list);
	va_end(list);
}

void	log_info(const char *fmt, ...)
{
	va_list		list;

	va_start(list, fmt);
	log_log(LOG_LVL_INFO, fmt, list);
	va_end(list);
}

void	log_debug(const char *fmt, ...)
{
	va_list		list;

	va_start(list, fmt);
	log_log(LOG_LVL_DEBUG, fmt, list);
	va_end(list);
}