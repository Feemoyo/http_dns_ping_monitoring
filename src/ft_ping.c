/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:37:39 by fmoreira          #+#    #+#             */
/*   Updated: 2022/08/03 13:15:55 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/monitoring.h"

int	ft_ping_play(t_ping *ping_field)
{
	FILE	*output;
	char	*str;
	int		size;

	size = 200;
	output = popen(ft_str_ping(ping_field), "r");
	//if (fgets(str, size, output))
	//	printf("%s", str);
	pclose(output);
	return (0);
}

char	*ft_str_ping(t_ping *ping_field)
{
	char	*str;
	int		i;

	i = 0;
	while(ping_field->interval[i] != 0)
	{
		if (ping_field->interval[i] == '\n')
			ping_field->interval[i] = 0;
		i++;
	}
	str = ft_strjoin("ping -i", ping_field->interval);
	str = ft_strjoin(str, " -c1 ");
	str = ft_strjoin(str, ping_field->standard->address);
	str = ft_strjoin(str, ">> monitoring.log && printf '\n' >> monitoring.log");
	return (str);
}
/*  prototipo do ping --simplify
char	*ft_str_ping_simp(t_ping *ping_field)
{
	char	*str;
	int		i;

	i = 0;
	while(ping_field->interval[i] != 0)
	{
		if (ping_field->interval[i] == '\n')
			ping_field->interval[i] = 0;
		i++;
	}
	str = ft_strjoin("ping -i", ping_field->interval);
	str = ft_strjoin(str, " -c1 ");
	str = ft_strjoin(str, ping_field->standard->address);
	return (str);
}
*/