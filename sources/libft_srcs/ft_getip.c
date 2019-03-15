/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:14:34 by gpouyat           #+#    #+#             */
/*   Updated: 2019/03/15 11:47:43 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <netdb.h>
#include <arpa/inet.h>

char	*ft_getip(void)
{
	char			*ip_buffer;
	struct hostent	*host_entry;

	host_entry = gethostbyname("localhost");
	if (!host_entry)
		return (NULL);
	ip_buffer = inet_ntoa(*((struct in_addr*)
						host_entry->h_addr_list[0]));
	return (ip_buffer);
}
