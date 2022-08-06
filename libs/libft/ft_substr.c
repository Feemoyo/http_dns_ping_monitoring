/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:35:58 by fmoreira          #+#    #+#             */
/*   Updated: 2021/06/23 19:56:02 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*src;

	i = -1;
	j = ft_strlen(s + start);
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_calloc(1, sizeof(char)));
	if (j < len)
		len = j;
	src = ft_calloc(len + 1, sizeof(char));
	if (src)
	{
		while (++i < len)
		{
			src[i] = s[start + i];
		}
		return (src);
	}
	else
		return (0);
}
