/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 10:02:18 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/10/01 16:19:53 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		read_file2(char *line)
{
	int		f;
	char	**tokens;

	f = 1;
	if (ft_strncmp(line, "", 1) != 0)
	{
		tokens = ft_strtoke(line, ',');
		if (is_label(tokens) > 0 && !tokens[1])
		{
			f = 0;
		}
		if (f == 1)
			if (check_line(tokens) == 0)
				return (0);
		if (g_op_tab[g_values->linenbr].acb == 1 && f == 1)
			encode(tokens, g_values);
	}
	return (1);
}

int		read_file(t_file *file)
{
	char		*line;
	int			j;
	int			i;

	i = -1;
	while (((j = get_next_line(file->fds, &line)) > 0
				&& generate_header(&file->header, line, ++i) == 1))
	{
		if ((i == 0 && ft_strlen(line) >= 128) ||
			(i == 1 && ft_strlen(line) >= 2048))
		{
			ft_putstr("Error: name or comment too long\n");
			return (0);
		}
	}
	if (i != 2)
	{
		ft_putstr("Error: enter one name <= (128 bytes) ");
		ft_putstr("and one comment <= (2048 bytes)\n");
		return (0);
	}
	while ((j = get_next_line(file->fds, &line) > 0))
		if (read_file2(line) == 0)
			return (0);
	return (0);
}
