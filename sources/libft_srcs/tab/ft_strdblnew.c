/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdblnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 16:26:00 by gpouyat           #+#    #+#             */
/*   Updated: 2019/02/11 16:51:38 by gpouyat          ###   ########.fr       */
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
	if (!(str = (char **)ft_memalloc(sizeof(char*) * (size + 1))))
		return (NULL);
	return (str);
}
