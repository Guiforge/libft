/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:17:00 by gpouyat           #+#    #+#             */
/*   Updated: 2017/03/02 12:38:34 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	nb_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_split_cut(char **tab, char const *s, unsigned int count,
		char c)
{
	unsigned	int	word;
	unsigned	int	i;
	unsigned	int	temp;

	temp = 0;
	i = 0;
	word = 0;
	while (s[i] && word < count)
	{
		temp = 0;
		if (s[i] != c)
		{
			while (s[temp + i] != c && s[temp + i])
				temp++;
			tab[word] = ft_strsub(s, i, temp);
			word++;
			i = temp + i;
		}
		else
			i++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
	tab = ft_strdblnew(nb_word(s, c));
	if (tab == NULL)
		return (NULL);
	tab = ft_split_cut(tab, s, nb_word(s, c), c);
	return (tab);
}
