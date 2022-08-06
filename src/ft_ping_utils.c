/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:25:31 by fmoreira          #+#    #+#             */
/*   Updated: 2022/08/03 10:31:54 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/monitoring.h"

t_ping	ft_init_s_ping(t_protocol *protocol, t_ping *ping_field, char **split, int i)
{
	ping_field->standard = protocol;
	ping_field->interval = ft_strdup(split[i]);
	return (*ping_field);
}