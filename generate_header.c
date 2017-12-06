/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 09:48:52 by ecloete           #+#    #+#             */
/*   Updated: 2017/10/01 15:43:48 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char			*get_str(char *line, int size)
{
	char	*tmp;
	int		i;
	char	*s;

	i = 0;
	s = (char *)malloc((sizeof(char)) * size);
	tmp = ft_strchr(line, '"');
	++tmp;
	while (tmp[i] != '"')
	{
		s[i] = tmp[i];
		i++;
	}
	return (s);
}

int					generate_header(t_header *header, char *line, int i)
{
	if (ft_strnstr(line, ".name", 5) != NULL && i == 0)
	{
		ft_bzero(header->prog_name, PROG_NAME_LENGTH);
		ft_strcpy(header->prog_name, get_str(line, PROG_NAME_LENGTH + 1));
		return (1);
	}
	else if (i == 0)
	{
		ft_putstr(".name not found or invalid\n");
		return (0);
	}
	if (ft_strnstr(line, ".comment", 8) != NULL && i == 1)
	{
		ft_bzero(header->comment, COMMENT_LENGTH);
		ft_strcpy(header->comment, get_str(line, COMMENT_LENGTH + 1));
		return (1);
	}
	else if (i == 1)
	{
		ft_putstr(".comment not found or invalid\n");
		return (0);
	}
	if (ft_strnstr(line, ".comment", 8) || ft_strnstr(line, ".name", 5))
		return (1);
	return (0);
}
