/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:28:40 by gpouyat           #+#    #+#             */
/*   Updated: 2017/12/21 19:39:00 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <signal.h>

void	basicerror(char *name, char *error, int ex)
{
	ft_putstr_fd(name, 2);
	perror(error);
	if (ex)
		exit(EXIT_FAILURE);
}

void	basicerror_out(char *name, char *error, int nb)
{
	ft_putstr_fd(name, 2);
	perror(error);
	exit(nb);
}

void	exit_error(const char *progname, const char *error, pid_t pid, int sig)
{
	ft_putstr_fd(progname, STDERR_FILENO);
	ft_putstr_fd(": EXIT-ERROR: ", STDERR_FILENO);
	if (error)
		ft_putendl_fd(error, STDERR_FILENO);
	else
		ft_putendl_fd("", STDERR_FILENO);
	kill(pid, sig);
	exit(EXIT_FAILURE);
}
