/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overwrite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:24:19 by gpouyat           #+#    #+#             */
/*   Updated: 2019/02/15 15:05:50 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_overwrite(char *string, char old, char new, ssize_t count)
{
	size_t	i;

	if (!string)
		return (NULL);
	i = 0;
	while (string[i] && count)
	{
		if (string[i] == old)
		{
			string[i] = new;
			count = (count == -1 ? count : count - 1);
		}
		i++;
	}
	return (string);
}
