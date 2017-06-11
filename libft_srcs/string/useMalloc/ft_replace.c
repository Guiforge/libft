/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:10:42 by gpouyat           #+#    #+#             */
/*   Updated: 2017/01/24 08:00:05 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace(char *src1, char *src2, int index, int size)
{
	char	*begin;
	char	*end;
	char	*ret;

	begin = ft_strnew(index);
	begin = ft_strncpy(begin, src1, index);
	end = ft_strjoin(src2, &src1[index + size]);
	ret = ft_strjoin(begin, end);
	free(begin);
	free(end);
	free(src1);
	return (ret);
}
