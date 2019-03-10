/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:27:15 by gpouyat           #+#    #+#             */
/*   Updated: 2019/03/10 14:39:08 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern/get_next_line.h"

static int		exist_stock(char **line, char **stock, char *str)
{
	char		*temp;
	char		*tmp_stock;

	tmp_stock = *stock;
	if ((temp = ft_strstr(*stock, str)))
	{
		*temp = '\0';
		*line = ft_strdup(*stock);
		*stock = ft_strdup(temp + 1);
		temp = NULL;
		ft_strdel(&tmp_stock);
		return (0);
	}
	return (1);
}

static int		read_gnl(char **stock, char *buf, char **line, char *str)
{
	char		*temp;

	if ((temp = ft_strstr(buf, str)))
	{
		*temp = '\0';
		*line = ft_strjoin(*stock, buf);
		free(*stock);
		*stock = ft_strdup(temp + 1);
		free(buf);
		temp = NULL;
		if (*stock && *stock[0] == 0)
			ft_fri(stock);
		return (0);
	}
	return (1);
}

static int		win_lines_return(int ret, char **line, char **stock,
																	char **buf)
{
	if (ret == -1)
		return (-1);
	*line = ft_strdup(*stock);
	free(*stock);
	*stock = NULL;
	free(*buf);
	*buf = NULL;
	if (ret == 0 && *line[0] != '\0')
		return (1);
	return (0);
}

int				get_next_str(const int fd, char **line, char *str)
{
	char		*buf;
	int			ret;
	char		*temp;
	static char	*stock = NULL;

	if (stock)
	{
		if ((exist_stock(line, &stock, str)) == 0)
			return (1);
	}
	else
		stock = ft_strnew(0);
	ret = 0;
	buf = ft_strnew(BUFF_SIZE + 1);
	while ((ret = (int)read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (read_gnl(&stock, buf, line, str) == 0)
			return (1);
		temp = stock;
		stock = ft_strjoin(stock, buf);
		ft_fri(&temp);
	}
	return (win_lines_return(ret, line, &stock, &buf));
}
