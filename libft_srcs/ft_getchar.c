/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:51:51 by gpouyat           #+#    #+#             */
/*   Updated: 2017/01/24 07:57:29 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*win_lines(wchar_t c, char *tmp)
{
	if (c <= 1114111 && c > 65535)
	{
		tmp = ft_strnew(4);
		tmp[0] = (c >> 18) + 0xF0;
		tmp[1] = ((c >> 12) & 0x3F) + 0x80;
		tmp[2] = ((c >> 6) & 0x3F) + 0x80;
		tmp[3] = (c & 0x3F) + 0x80;
	}
	return (tmp);
}

char		*ft_getchar(wchar_t c)
{
	char	*tmp;

	tmp = NULL;
	if (c <= 127)
	{
		tmp = ft_strnew(1);
		tmp[0] = c;
	}
	else if (c <= 2047)
	{
		tmp = ft_strnew(2);
		tmp[0] = (c >> 6) + 0xC0;
		tmp[1] = (c & 0x3F) + 0x80;
	}
	else if (c <= 65535)
	{
		tmp = ft_strnew(3);
		tmp[0] = (c >> 12) + 0xE0;
		tmp[1] = ((c >> 6) & 0x3F) + 0x80;
		tmp[2] = (c & 0x3F) + 0x80;
	}
	return (win_lines(c, tmp));
}

char		*ft_getwstr(wchar_t *s)
{
	char	*ret;
	int		i;
	char	*tmp;
	char	*tmp2;

	if (!s)
		return (NULL);
	i = 0;
	ret = ft_strdup("");
	while (s[i])
	{
		tmp = ft_getchar(s[i]);
		tmp2 = ft_strjoin(ret, tmp);
		free(tmp);
		free(ret);
		ret = tmp2;
		i++;
	}
	return (ret);
}
