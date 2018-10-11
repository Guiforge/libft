/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:17:11 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/11 13:52:18 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s2;

	if (!str)
		return (NULL);
	s2 = ft_strnew(ft_strlen(str));
	if (s2 == NULL)
		return (NULL);
	else
		return (ft_strcpy(s2, str));
}
