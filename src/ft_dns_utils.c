/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dns_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:44:58 by fmoreira          #+#    #+#             */
/*   Updated: 2022/08/02 23:49:32 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/monitoring.h"

t_dns	ft_init_s_dns(t_protocol *protocol, t_dns *dns_field, char **split, int i)
{
	dns_field->standard = protocol;
	dns_field->interval = ft_strdup(split[i++]);
	dns_field->dns_serv = ft_strdup(split[i]);
	return (*dns_field);
}