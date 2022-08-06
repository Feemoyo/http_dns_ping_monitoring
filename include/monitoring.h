/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:34:13 by fmoreira          #+#    #+#             */
/*   Updated: 2022/08/03 14:25:00 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MONITORING_H
# define	MONITORING_H

#include	"../libs/libft/libft.h"
#include	<stdio.h>
#include	<fcntl.h>

typedef struct	s_protocol
{
	char	*name;
	char	*protocol;
	char	*address;
}	t_protocol;

typedef struct	s_http
{
	char	*method;
	char	*expected;
	char	*interval;
	struct s_protocol	*standard;
}	t_http;

typedef struct	s_ping
{
	char	*interval;
	struct s_protocol	*standard;
}	t_ping;

typedef struct	s_dns
{
	char	*interval;
	char	*dns_serv;
	struct s_protocol	*standard;
}	t_dns;

void	ft_init_protocol(t_protocol *protocol, char **split);
void	*ft_init_format(t_http *http_field, t_ping *ping_field, t_dns *dns_field);

t_http	ft_init_s_http(t_protocol *protocol, t_http *http_field, char **split, int i);
int		ft_http_play(t_http *http_field);
char	*ft_str_http(t_http	*http_field);

t_ping	ft_init_s_ping(t_protocol *protocol, t_ping *ping_field, char **split, int i);
int	ft_ping_play(t_ping *ping_field);
char	*ft_str_ping(t_ping *ping_field);
char	*ft_str_ping_simp(t_ping *ping_field);

t_dns	ft_init_s_dns(t_protocol *protocol, t_dns *dns_field, char **split, int i);
int	ft_dns_play(t_dns *dns_field);
char	*ft_str_dns(t_dns *dns_field);


#endif
