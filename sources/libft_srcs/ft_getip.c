/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:14:34 by gpouyat           #+#    #+#             */
/*   Updated: 2019/02/11 10:20:12 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <netdb.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 


char	*ft_getip(void)
{
	char hostbuffer[256]; 
	char *IPbuffer; 
	struct hostent *host_entry; 

	if (gethostname(hostbuffer, sizeof(hostbuffer)) == -1)
		return (NULL);
	host_entry = gethostbyname(hostbuffer);
	if (!host_entry)
		return (NULL);
	IPbuffer = inet_ntoa(*((struct in_addr*) 
						host_entry->h_addr_list[0])); 
	return (IPbuffer);
}