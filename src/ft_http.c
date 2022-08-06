/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_http.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:05:57 by fmoreira          #+#    #+#             */
/*   Updated: 2022/08/03 13:17:07 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/monitoring.h"

int	ft_http_play(t_http *http_field)
{
	FILE	*output;
	char	*str;
	int		size;
	
	if (ft_strcmp(http_field->method, "GET")) // validaçao do GET
		return (1);
	size = 200;
	output = popen(ft_str_http(http_field), "r");
	//if (fgets(str, size, output))
	//	printf("%s", str);
	pclose(output);
	return (0);
}

char	*ft_str_http(t_http	*http_field)
{
	char	*str;
	int		i;

	i = 0;
	while(http_field->interval[i] != 0)
	{
		if (http_field->interval[i] == '\n')
			http_field->interval[i] = 0;
		i++;
	}
	str = ft_strjoin("curl -s -I -X GET ", http_field->standard->address);
	str = ft_strjoin(str, ">> monitoring.log");
	return (str);
}
