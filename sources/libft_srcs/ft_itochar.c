/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itochar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 20:33:12 by gpouyat           #+#    #+#             */
/*   Updated: 2019/01/04 15:31:58 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_itochar(size_t size, const void *nb, t_bool is_little)
{
	char	*ret;

	if (!(ret = ft_memalloc(size)))
		return (NULL);
	if (is_little)
		ft_memcpy_swap(ret, nb, size);
	else
		ft_memcpy(ret, nb, size);
	return (ret);
}

char	*ft_itochar_secu(size_t size, const void *nb, t_bool is_little,
																	size_t lvl)
{
	char	*ret;

	if (!(ret = ft_secu_malloc_lvl(size, lvl)))
		return (NULL);
	if (is_little)
		ft_memcpy_swap(ret, nb, size);
	else
		ft_memcpy(ret, nb, size);
	return (ret);
}
