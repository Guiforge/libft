/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:10:42 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/11 13:55:54 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_replace_init(char *src1, char *src2, int index, int size)
{
	if (!src1 || !src2 || ft_strlen(src1) < (size_t)(index + 1))
		return (-1);
	if ((ft_strlen(&src1[index]) < (size_t)size))
		return (-1);
	return (0);
}

char	*ft_replace(char *src1, char *src2, int index, int size)
{
	char	*begin;
	char	*end;
	char	*ret;

	if (ft_replace_init(src1, src2, index, size))
		return (NULL);
	if ((begin = ft_strnew((index + 1))) == NULL)
		return (NULL);
	begin = ft_strncpy(begin, src1, index);
	end = ft_strjoin(src2, &src1[index + size]);
	if (end)
		ret = ft_strjoin(begin, end);
	else
		ret = NULL;
	ft_fri(&begin);
	ft_fri(&end);
	ft_fri(&src1);
	return (ret);
}
