/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:27:15 by gpouyat           #+#    #+#             */
/*   Updated: 2017/03/19 11:53:16 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		exist_stock(char **line, char **stock)
{
	char		*temp;

	if ((temp = ft_strchr(*stock, '\n')))
	{
		*temp = '\0';
		*line = ft_strdup(*stock);
		*stock = ft_strdup(temp + 1);
		temp = NULL;
		return (0);
	}
	return (1);
}

static int		read_gnl(char **stock, char *buf, char **line)
{
	char		*temp;

	if ((temp = ft_strchr(buf, '\n')))
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

static int		win_lines_return(int ret, char **line, char **stock, char **buf)
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

int				get_next_line(const int fd, char **line)
{
	char		*buf;
	int			ret;
	char		*temp;
	static char	*stock = NULL;

	if (stock)
	{
		if ((exist_stock(line, &stock)) == 0)
			return (1);
	}
	else
		stock = ft_strnew(0);
	ret = 0;
	buf = ft_strnew(BUFF_SIZE + 1);
	while ((ret = (int)read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (read_gnl(&stock, buf, line) == 0)
				return (1);
		temp = stock;
		stock = ft_strjoin(stock, buf);
		ft_fri(&temp);
	}
	return (win_lines_return(ret, line, &stock, &buf));
}
