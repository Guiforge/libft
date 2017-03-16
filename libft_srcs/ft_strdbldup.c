/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdbldup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:37:40 by gpouyat           #+#    #+#             */
/*   Updated: 2017/02/28 13:07:14 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdbldup(char **str)
{
	int		i;
	char	**ret;

	if (!str)
		return (NULL);
	i = 0;
	while (str && str[i])
		i++;
	if ((ret = ft_strdblnew(i)) == NULL)
		return (NULL);
	i = 0;
	while (ret && str && str[i])
	{
		ret[i] = ft_strdup(str[i]);
		i++;
	}
	return (ret);
}
