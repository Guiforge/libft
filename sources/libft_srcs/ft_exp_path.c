/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:53:45 by gpouyat           #+#    #+#             */
/*   Updated: 2019/02/15 15:08:52 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** @brief This function will find the first `..` it will find in the string
** `path` and return a pointer to it.
**
** @param path The string to search into
**
** @return Returns a pointer to the first `..` it'll find in `path`
*/

static char		*find_start_ddots(char *path, char *start2)
{
	char	*start;
	char	*tmp;

	if (!path)
		return (NULL);
	start = path;
	while ((tmp = ft_strchr(start, '/')) != start2 && tmp)
	{
		start = tmp;
		start++;
	}
	return (start);
}

/*
** @brief Removes the extraneous dots for given `path`.
**
** @param path String containing a path to remove the extraneous dots from.
**
** @return Returns the modified path without the extraneous dots inside.
*/

static	char	*remove_dots(char *path)
{
	char	*start;
	char	*start2;

	if (!path)
		return (NULL);
	while ((start = ft_strstr(path, "/./")) ||\
								((start = ft_strstr(path, "/.")) && !start[2]))
		ft_memcpy(start, start + 2, ft_strlen(start + 1));
	while ((start2 = ft_strstr(path, "/../")) ||\
							((start2 = ft_strstr(path, "/..")) && !start2[3]))
	{
		start = find_start_ddots(path, start2);
		if (start == path)
			start++;
		if (!*start)
			return (path);
		if (start2[3] == '/')
			start2++;
		ft_memcpy(start, start2 + 3, ft_strlen(start2 + 2));
	}
	if (path && ft_strlen(path) > 2 &&
									ft_strequ(&path[ft_strlen(path) - 2], "/."))
		path[ft_strlen(path) - 1] = 0;
	return (path);
}

/*
** @brief Removes the extraneous backslashes from a given `path`
**
** @param path String containing a path to remove the extraneous backslashes
** from.
**
** @return Returns the modified path without the extraneous backslashes inside.
*/

static char		*remove_backslash(char *path)
{
	char	*start;

	if (!path)
		return (NULL);
	while ((start = ft_strstr(path, "//")) && ft_strlen(start + 2))
		ft_memcpy(start + 1, start + 2, ft_strlen(start + 1));
	while (path && ft_strlen(path) > 1 && path[ft_strlen(path) - 1] == '/')
		path[ft_strlen(path) - 1] = 0;
	return (path);
}

static char		*get_abspath(const char *path, const char *abs_current)
{
	char		current[PATH_MAX + 1];
	char		*ret;

	if (abs_current)
	{
		ft_bzero(current, PATH_MAX + 1);
		ft_strncpy(current, abs_current, PATH_MAX);
	}
	else if (!getcwd(current, PATH_MAX))
		return (NULL);
	if (path && *path != '/')
	{
		ret = ft_strnew(ft_strlen(current) + ft_strlen(path) + 1);
		if (!ret)
			return (NULL);
		ft_strcat(ret, current);
		ft_strcat(ret, "/");
		ft_strcat(ret, path);
	}
	else
		ret = ft_strdup(path);
	return (ret);
}

/*
** @brief This function will expand a path given through a pointer.\n
** It will first remove the dots then the backslashes. If a `./` or a `//` are
** found in the modified string, the function will reset the modified path
** and return the original one.
**
** @param path The filename/path you want to modify
**
** @return path Returns the modified path
*/

char			*ft_exp_path(const char *path, const char *abs_current)
{
	char		*ret;
	size_t		len;

	if (!path)
		return (NULL);
	ret = get_abspath(path, abs_current);
	if (!ret)
		return (NULL);
	ret = remove_dots(remove_backslash(ret));
	if (ret)
	{
		len = ft_strlen(ret) - 1;
		if (ret[len] == '/' && len != 0)
			ret[len] = 0;
	}
	if (ft_strstr(ret, "./") || ft_strstr(ret, "//"))
	{
		log_fatal("CD expand PATH wrong ! (%s) so return (NULL)", ret);
		ft_strdel(&ret);
		return (NULL);
	}
	return (ret);
}
