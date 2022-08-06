/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:00:48 by fmoreira          #+#    #+#             */
/*   Updated: 2021/06/23 17:38:17 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static char	*ft_createstr(long int new_n, int i, int verify_n)
{
	long int	aux;
	char		*str;

	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (0);
	str[i--] = 0;
	while (i >= 0)
	{
		aux = new_n % 10;
		new_n = new_n / 10;
		str[i] = aux + '0';
		i--;
		if (i == 0 && verify_n)
			str[i--] = 45;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	new_n;
	long int	aux;
	int			i;
	int			verify_n;

	verify_n = 0;
	new_n = n;
	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		new_n = (long int)n * -1;
		verify_n = 1;
		i++;
	}
	aux = new_n;
	while (aux)
	{
		aux = aux / 10;
		i++;
	}
	str = (char *)ft_createstr(new_n, i, verify_n);
	return (str);
}
