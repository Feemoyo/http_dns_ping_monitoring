/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:36:34 by fmoreira          #+#    #+#             */
/*   Updated: 2021/06/24 12:03:52 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*i;

	i = malloc(nmemb * size);
	if (i == 0)
		return (0);
	ft_bzero(i, nmemb * size);
	return (i);
}
