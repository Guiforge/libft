/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_secu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 12:45:43 by gpouyat           #+#    #+#             */
/*   Updated: 2018/12/25 23:10:42 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup_secu(const char *str, size_t lvl)
{
	char	*s2;

	s2 = ft_strnew_secu(ft_strlen(str), lvl);
	if (s2 == NULL)
		return (NULL);
	else
		return (ft_strcpy(s2, str));
}
