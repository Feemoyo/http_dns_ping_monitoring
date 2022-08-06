/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_http_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 00:41:06 by fmoreira          #+#    #+#             */
/*   Updated: 2022/08/03 10:32:09 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/monitoring.h"

t_http	ft_init_s_http(t_protocol *protocol, t_http *http_field, char **split, int i)
{
	http_field->standard = protocol;
	http_field->method = ft_strdup(split[i++]);
	http_field->expected = ft_strdup(split[i++]);
	http_field->interval = ft_strdup(split[i]);
	return (*http_field);
}


