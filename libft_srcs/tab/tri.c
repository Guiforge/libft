/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:07:45 by gpouyat           #+#    #+#             */
/*   Updated: 2017/01/24 08:08:31 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**tri_strdbl_r(char **str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	if (!str)
		return (NULL);
	while (str[i + 1])
	{
		if (ft_strcmp(str[i], str[i + 1]) < 0)
		{
			temp = str[i];
			str[i] = str[i + 1];
			str[i + 1] = temp;
			temp = NULL;
			i = 0;
		}
		else
			i++;
	}
	return (str);
}

char	**tri_strdbl(char **str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	if (!str)
		return (NULL);
	while (str[i + 1])
	{
		if (ft_strcmp(str[i], str[i + 1]) > 0)
		{
			temp = str[i];
			str[i] = str[i + 1];
			str[i + 1] = temp;
			temp = NULL;
			i = 0;
		}
		else
			i++;
	}
	return (str);
}
