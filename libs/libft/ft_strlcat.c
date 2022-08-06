/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:13:53 by fmoreira          #+#    #+#             */
/*   Updated: 2021/06/08 16:06:23 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size <= ft_strlen(dst))
	{
		return (size + ft_strlen(src));
	}
	i = ft_strlen(dst);
	while (*src && i < size - 1)
	{
		dst[i++] = *(src++);
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
