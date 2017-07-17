/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:10:42 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/17 16:02:07 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_replace_init(char *src1, int index, int size)
{
	if (!src1 || ft_strlen(src1) < (size_t)(index + 1))
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

	if (ft_replace_init(src1, index, size))
		return (NULL);
	begin = ft_strnew((index + 1));
	begin = ft_strncpy(begin, src1, index);
	end = ft_strjoin(src2, &src1[index + size]);
	ret = ft_strjoin(begin, end);
	ft_fri(&begin);
	ft_fri(&end);
	ft_fri(&src1);
	return (ret);
}

/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc != 5)
	{
		printf("%s\n", "TOTO");
		return (0);
	}
	char *source = strdup(argv[1]);
	char *ret = strdup(argv[2]);

	source = ft_replace(source, NULL, atoi(argv[3]), atoi(argv[4]));
	printf("source=%s, ret=%s, result = %s\n", argv[1], ret, source);
}*/
