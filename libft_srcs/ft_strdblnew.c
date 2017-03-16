/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdblnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 16:26:00 by gpouyat           #+#    #+#             */
/*   Updated: 2017/02/17 10:21:25 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdblnew(int size)
{
	char	**str;
	int		i;

	i = 0;
	if (size <= 0)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i <= size)
	{
		str[i] = NULL;
		i++;
	}
	return (str);
}
