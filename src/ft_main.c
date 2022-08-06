/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:08:39 by fmoreira          #+#    #+#             */
/*   Updated: 2022/08/03 11:56:20 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/monitoring.h"

int	main(int argc, char	**argv)
{
	int			fd;
	char		*line;
	char		**split;
	t_protocol	*protocol;
	int			timer;

	while (42)
	{
		protocol = (t_protocol *)malloc(sizeof(t_protocol));
		if (!protocol)
		{
			printf("Deu ruim mané :(");
			exit (0);
		}
		fd = open("monitoring.db", O_RDONLY);
		line = ft_get_next_line(fd);
		while (line)
		{
			if (line)
			{
				split = ft_split(line, 9);
				ft_init_protocol(protocol, split);
				free(line);
			}
			line = ft_get_next_line(fd);
		}
		close(fd);
		sleep(60);
	}
}
