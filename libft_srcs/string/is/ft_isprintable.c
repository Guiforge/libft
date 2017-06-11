/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprintable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:20:10 by gpouyat           #+#    #+#             */
/*   Updated: 2017/03/01 17:22:12 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprintable(char *s)
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
