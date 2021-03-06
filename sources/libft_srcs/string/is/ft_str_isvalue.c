/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isvalue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:12:55 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/02 11:25:20 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_str_isvalue(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (ft_str_isdigit(s) ||
		((s[0] == '+' || s[0] == '-') && ft_str_isdigit(&s[1])))
		return (1);
	return (0);
}
