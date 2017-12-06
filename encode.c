/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:14:30 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/10/01 16:16:34 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	encode(char **newl, t_val *values)
{
	unsigned char	c;
	int				k;
	int				l;

	l = 0;
	if (is_label(newl) == 1)
		l = 1;
	k = 1;
	c = 0;
	while (k <= g_op_tab[values->linenbr].num_params)
	{
		if (newl[k + l][0] == '%')
			c += 0b10;
		else if (newl[k + l][0] == 'r')
			c += 0b01;
		else if (newl[k + l][0] >= '0' && newl[k + l][0] <= '9')
			c += 0b11;
		else
			c += 0b00;
		c = c << 2;
		k++;
	}
	values->encode = c;
}
