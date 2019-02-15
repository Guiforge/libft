/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:14:34 by gpouyat           #+#    #+#             */
/*   Updated: 2019/02/15 15:08:40 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <netdb.h>
#include <arpa/inet.h>

char	*ft_getip(void)
{
	char			hostbuffer[256];
	char			*ip_buffer;
	struct hostent	*host_entry;

	if (gethostname(hostbuffer, sizeof(hostbuffer)) == -1)
		return (NULL);
	host_entry = gethostbyname(hostbuffer);
	if (!host_entry)
		return (NULL);
	ip_buffer = inet_ntoa(*((struct in_addr*)
						host_entry->h_addr_list[0]));
	return (ip_buffer);
}
