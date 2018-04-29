/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 15:01:10 by gpouyat           #+#    #+#             */
/*   Updated: 2018/04/29 18:39:19 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getopt.h"

int		g_optind = 1;
int		g_opterr = 1;
char	*g_optarg = NULL;
int		g_optopt;

static int		ft_getopt_init(int argc, char const *argv[])
{
		if (argc <= g_optind || ft_strequ(argv[g_optind], "--") || *argv[g_optind] != '-')
			return (-1);
	return (0);
}

static char ft_getopt_current(char **next, const char **argv)
{
	char	ret;

	if (!*next || !**next)
		*next = (char *)argv[g_optind] + 1;
	ret = **next;
	++*next;
	if (!**next)
		g_optind++;
	g_optopt = ret;
	g_optarg = NULL;	
	return(ret);
}

static int		ft_getopt_check(char search, const char *opstring)
{
	int index;

	index = -1;
	while(opstring && opstring[index++])
		if (opstring[index] == search)
			return (opstring[index + 1] == ':');

	return (-1);
}

static int ft_getopt_error(const char *prgm, char current, int err)
{
	char current_str[2];
	
	current_str[0] = current;
	current_str[1] = 0;	
	ft_putstr_fd(prgm, STDERR_FILENO);	
	if (err == FT_GETOPT_OPT_REQ)
	{
		over_p_str(": option requires an argument --", current_str);	
	}
	else if (err == FT_GETOPT_INV_OPT)
	{
		over_p_str(": illegal option -- ", current_str);
	}
	return ((int)'?');
}

int		ft_getopt(int argc, char const *argv[], const char *optstring)
{
static char *next = NULL;
int			check;
char		current;

	(void)optstring;
	if (ft_getopt_init(argc, argv))
		return (-1);
	current = ft_getopt_current(&next, argv);
	check = ft_getopt_check(current, optstring);
	if (ft_isalnum(current) && check != -1)
	{
		if (check == 1)
		{
			if (*next)
				g_optarg = next;
			else if(argv[g_optind])
				g_optarg = (char *)argv[g_optind];
			else
				return(ft_getopt_error(*argv, current, FT_GETOPT_OPT_REQ));
			next = NULL;
			g_optind++;
		}
		return (g_optopt);
	}
	return(ft_getopt_error(*argv, current, FT_GETOPT_INV_OPT));
}