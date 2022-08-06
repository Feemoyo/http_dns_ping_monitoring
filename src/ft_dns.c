/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dns.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:44:53 by fmoreira          #+#    #+#             */
/*   Updated: 2022/08/03 13:16:02 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/monitoring.h"

int	ft_dns_play(t_dns *dns_field)
{
	FILE	*output;
	char	*str;
	int		size;

	size = 200;
	output = popen(ft_str_dns(dns_field), "r");
	//if (fgets(str, size, output))
	//	printf("%s", str);
	pclose(output);
	return (0);
}

char	*ft_str_dns(t_dns *dns_field)
{
	char	*str;

	str = ft_strjoin("dig ", dns_field->standard->address);
	return (str);
}
