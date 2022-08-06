/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 01:33:07 by fmoreira          #+#    #+#             */
/*   Updated: 2021/06/24 12:38:46 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char *s)
{
	char	*i;

	i = (char *)malloc(ft_strlen(s) + 1);
	if (!i)
		return (0);
	ft_memcpy(i, s, ft_strlen(s) + 1);
	return (i);
}
