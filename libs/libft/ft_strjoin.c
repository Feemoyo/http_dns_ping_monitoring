/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:28:59 by fmoreira          #+#    #+#             */
/*   Updated: 2021/06/17 14:39:08 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ns;

	if (!s1 || !s2)
		return (0);
	ns = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (ns)
	{
		i = 0;
		j = 0;
		while (s1[i])
		{
			ns[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			ns[i + j] = s2[j];
			j++;
		}
	}
	return (ns);
}
