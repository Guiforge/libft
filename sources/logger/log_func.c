/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 23:54:42 by gpouyat           #+#    #+#             */
/*   Updated: 2019/01/11 19:22:37 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	g_tabs = 0;

static void		print_tabs(void)
{
	size_t	tmp;

	tmp = g_tabs;
	while (tmp)
	{
		ft_putchar_fd('	', g_log_fd);
		tmp--;
	}
}

void			log_func_start(const char function[24])
{
	if (!g_log_fd)
		return ;
	print_tabs();
	ft_dprintf(g_log_fd, "{blue}[*] Start -- %s{no}\n", function);
	g_tabs++;
}

void			log_func_end(const char function[24])
{
	if (!g_log_fd)
		return ;
	g_tabs--;
	print_tabs();
	ft_dprintf(g_log_fd, "{blue}[*] End --- %s{no}\n", function);
}
