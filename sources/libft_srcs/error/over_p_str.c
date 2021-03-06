/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_p_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:30:23 by gpouyat           #+#    #+#             */
/*   Updated: 2018/04/29 18:32:08 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*over_p_str(char *str, char *ag)
{
	if (str)
		ft_putstr_fd(str, STDERR_FILENO);
	if (ag)
		ft_putstr_fd(ag, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (NULL);
}
