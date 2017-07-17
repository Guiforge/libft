/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:17:11 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/17 15:52:29 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s2;

	s2 = ft_strnew(ft_strlen(str));
	if (s2 == NULL)
		return (NULL);
	else
		return (ft_strcpy(s2, str));
}
