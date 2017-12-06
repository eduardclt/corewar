/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 09:02:03 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/10/01 15:49:32 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_label(char **line)
{
	size_t i;

	if (ft_strchr(line[0], ':') != NULL)
	{
		i = 0;
		while (i < ft_strlen(line[0]) - 1)
		{
			if (ft_isupper(line[0][i]))
			{
				return (-1);
			}
			i++;
		}
		return (1);
	}
	return (0);
}
