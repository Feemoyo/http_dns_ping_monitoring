/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:08:26 by fmoreira          #+#    #+#             */
/*   Updated: 2022/08/01 23:00:02 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	search_line_break(char **buf, size_t *scissor)
{
	int	i;

	if (!*buf)
		return (0);
	i = 0;
	while ((*buf)[i] != '\0')
	{
		if ((*buf)[i] == '\n')
		{
			*scissor = i;
			return (1);
		}
		i++;
	}
	return (0);
}

static char	*cut_line(char **buf, size_t *scissor)
{
	int		i;
	char	*tmp;
	char	*line;

	i = 0;
	line = NULL;
	if (!*buf)
		return (NULL);
	tmp = ft_strdup(*buf);
	if (search_line_break(&*buf, &*scissor))
	{
		line = ft_substr(*buf, 0, *scissor + 1);
		free(*buf);
		*buf = ft_substr(tmp, *scissor + 1, ft_strlen(tmp));
	}
	else
	{
		i = ft_strlen(tmp);
		if (i > 0)
			line = ft_substr(tmp, 0, i);
		free(*buf);
		*buf = NULL;
	}
	free(tmp);
	return (line);
}

static void	set_buf(char **buf, char **tmp, char **be_read)
{
	if (!*buf)
		*buf = ft_strdup(*be_read);
	else
	{
		*tmp = ft_strdup(*buf);
		free(*buf);
		*buf = ft_strjoin(*tmp, *be_read);
		free(*tmp);
	}
}

char	*ft_get_next_line(int fd)
{
	size_t		scissor;
	size_t		read_int;
	static char	*buf;
	char		*be_read;
	char		*tmp;

	if (fd < 0 || read(fd, NULL, 0) != 0 || BUFFER_SIZE < 0)
		return (NULL);
	be_read = malloc(BUFFER_SIZE + 1);
	read_int = read(fd, be_read, BUFFER_SIZE);
	scissor = 0;
	while (read_int > 0)
	{
		(be_read)[read_int] = '\0';
		set_buf(&buf, &tmp, &be_read);
		if (search_line_break(&buf, &scissor))
			break ;
		read_int = read(fd, be_read, BUFFER_SIZE);
	}
	free(be_read);
	return (cut_line(&buf, &scissor));
}
