/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoke.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 11:06:02 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/10/01 15:40:22 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static size_t		ft_words(char const *s, char c, char b)
{
	int		i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i] && (s[i] == c || s[i] == b))
		i++;
	while (s[i])
	{
		while (s[i] && (s[i] == c || s[i] == b))
			i++;
		if (s[i])
		{
			while (s[i] && (s[i] != c && s[i] != b))
				i++;
			size++;
		}
	}
	return (size);
}

static char			**mystrsplit(char const *s, char c, char b)
{
	char	**tab;
	size_t	size;
	int		i;
	int		start;

	if (!s || !(tab = (char **)malloc(sizeof(char *) *
										(ft_words(s, c, b) + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == b)
			i++;
		else
		{
			start = i;
			while (s[i] && (s[i] != c && s[i] != b))
				i++;
			tab[size++] = ft_strsub(s, start, i - start);
		}
	}
	tab[size] = NULL;
	return (tab);
}

char				**ft_strtoke(char *line, char b)
{
	char	**newline;

	while ((*line >= '\t' && *line <= '\r') || *line == 32)
		line++;
	newline = mystrsplit(line, ' ', b);
	return (newline);
}
