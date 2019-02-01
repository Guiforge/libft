/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmpa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:31:35 by gpouyat           #+#    #+#             */
/*   Updated: 2019/02/01 17:24:21 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lines_free(char *s1_tmp, char *s2_tmp)
{
	free(s1_tmp);
	free(s2_tmp);
}

int			ft_strcmpa(const char *s1, const char *s2)
{
	int		i;
	int		a;
	char	*s2_tmp;
	char	*s1_tmp;

	i = 0;
	a = 0;
	s2_tmp = ft_strtolower(ft_strdup(s2));
	s1_tmp = ft_strtolower(ft_strdup(s1));
	while (ft_isalpha(s1_tmp[i]) == 0 && s1_tmp[i])
		i++;
	while (ft_isalpha(s2_tmp[a]) == 0 && s2_tmp[a])
		a++;
	while (s1_tmp[i] == s2_tmp[a] && (s1_tmp[i] || s2_tmp[a]))
	{
		i++;
		a++;
		while (ft_isalpha(s1_tmp[i]) == 0 && s1_tmp[i])
			i++;
		while (ft_isalpha(s2_tmp[a]) == 0 && s2_tmp[a])
			a++;
	}
	i = ((unsigned char)s1_tmp[i] - (unsigned char)s2_tmp[a]) % 127;
	lines_free(s1_tmp, s2_tmp);
	return (i);
}
