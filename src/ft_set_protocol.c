/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_protocol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:33:13 by fmoreira          #+#    #+#             */
/*   Updated: 2022/08/03 13:52:19 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/monitoring.h"

void	ft_init_protocol(t_protocol *protocol, char **split)
{
	int	i;
	t_http	http_field;
	t_ping	ping_field;
	t_dns	dns_field;
	
	i = 0;
	ft_init_format(&http_field, &ping_field, &dns_field);
	protocol->name =  ft_strdup(split[i++]);
	protocol->protocol =  ft_strdup(split[i++]);
	protocol->address =  ft_strdup(split[i++]);
	if (!(ft_strcmp(protocol->protocol, "HTTP")))
	{
		http_field = ft_init_s_http(protocol, &http_field, split, i);
		ft_http_play(&http_field);
	}
	else if (!(ft_strcmp(protocol->protocol, "PING")))
	{
		ping_field = ft_init_s_ping(protocol, &ping_field, split, i);
		ft_ping_play(&ping_field);
	}
	else if (!(ft_strcmp(protocol->protocol, "DNS")))
	{
		dns_field = ft_init_s_dns(protocol, &dns_field, split, i);
		ft_dns_play(&dns_field);
	}
	else
		printf("\nSorry, I can't do it. :(\n");
}

void	*ft_init_format(t_http *http_field, t_ping *ping_field, t_dns *dns_field)
{
	http_field = (t_http *)malloc(sizeof(t_http));
	ping_field = (t_ping *)malloc(sizeof(t_ping));
	dns_field = (t_dns *)malloc(sizeof(t_dns));
	if (!http_field || !ping_field || !dns_field)
		exit(0);
}
