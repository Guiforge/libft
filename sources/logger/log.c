/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:01:05 by gpouyat           #+#    #+#             */
/*   Updated: 2018/12/27 19:09:08 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <fcntl.h>

int		g_log_fd;

int		log_init(char *filename, int fd)
{
	if (filename) 
		g_log_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else
		g_log_fd = fd;
	if (g_log_fd == -1)
		ft_dprintf(STDERR_FILENO, "Error init logger file: %s\n", filename);
	else
		ft_dprintf(g_log_fd, "\t\t  ***** Logger start *****\n"
		"******************************************************************\n");
	return(g_log_fd);
}

int		log_log(enum e_logger_lvl lvl, const char *format, va_list list)
{
	if (lvl == LOG_LVL_ERROR)
		ft_dprintf(g_log_fd, "{no}[{red}ERROR{no}] >>>: {red}");
	else if( lvl == LOG_LVL_FATAL)
		ft_dprintf(g_log_fd, "{no}{red}[FATAL] !!!!!!!!!: ");
	else if( lvl == LOG_LVL_WARN)
		ft_dprintf(g_log_fd, "{no}{yellow}[Warning]: ");
	else if( lvl == LOG_LVL_INFO)
		ft_dprintf(g_log_fd, "{no}[Info]: ");
	else
		ft_dprintf(g_log_fd, "{no}-> ");
	ft_vdprintf(g_log_fd, format, list);
	ft_dprintf(g_log_fd, "{no}\n");
	return(g_log_fd);
}

void	log_close(void)
{
	ft_dprintf(g_log_fd, "\t\t  ----- Logger END -----\n"
		"-----------------------------------------------------------------*\n");
	close(g_log_fd);
}