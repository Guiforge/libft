/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:20:10 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/16 14:25:22 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isprint(char *s)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (s && s[i] && !ret)
	{
		if (!ft_isprint(s[i]) && s[i] != '\t')
			ret = 1;
		i++;
	}
	return (ret);
}
