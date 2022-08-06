/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:05:11 by fmoreira          #+#    #+#             */
/*   Updated: 2021/06/23 17:57:25 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	ft_number_words(const char *s, char c)
{
	int	n_words;
	int	in_word;

	n_words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			n_words++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (n_words);
}

static char	*ft_word_dup(const char *s, size_t start, size_t finish)
{
	char	*word;
	int		i;
	int		is_print;

	i = 0;
	is_print = 0;
	word = ft_calloc((finish - start) + 1, sizeof(char));
	while (start < finish)
	{
		if (ft_isprint(s[start]))
			is_print++;
		word[i++] = s[start++];
	}
	if (is_print > 0)
		return (word);
	else
		return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	j;
	int		index;

	strs = ft_calloc((ft_number_words(s, c) + 1), sizeof(char *));
	if (!strs)
		return (0);
	i = -1;
	j = 0;
	index = 0;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			if ((size_t)index < i)
				strs[j++] = ft_word_dup(s, index, i);
			index = -1;
		}
	}
	return (strs);
}
