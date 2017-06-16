/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:56:46 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/16 14:26:28 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isdigit(char *s)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (s && s[i] && !ret)
	{
		if (!ft_isdigit(s[i]))
			ret = 1;
		i++;
	}
	return (ret);
}
