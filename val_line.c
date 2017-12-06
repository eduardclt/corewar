/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:14:06 by ecloete           #+#    #+#             */
/*   Updated: 2017/10/01 16:20:18 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_p_val(int param[4], char **tokes, int j)
{
	int i;

	if (is_label(tokes) == 1)
		i = j + 1;
	else
		i = j;
	if (tokes[i + 1][0] == 'r' && param[j] == 1)
		return (1);
	if (tokes[i + 1][0] == '%' && param[j] == 2)
		return (1);
	if ((tokes[i + 1][0] == '%' || tokes[i + 1][0] == 'r')
			&& param[j] == 3)
		return (1);
	if ((tokes[i + 1][0] == 'r' || ft_isdigit(tokes[i + 1][0]))
			&& param[j] == 5)
		return (1);
	if ((tokes[i + 1][0] == '%' || ft_isdigit(tokes[i + 1][0]))
			&& param[j] == 6)
		return (1);
	if ((tokes[i + 1][0] == 'r' || ft_isdigit(tokes[i + 1][0])
				|| tokes[i + 1][0] == '%') && param[j] == 7)
		return (1);
	return (0);
}

int		count_params(char **params)
{
	int		i;

	i = 0;
	while (params[i] != '\0')
		i++;
	return (i);
}

int		check_params(char **tokes, int line_num)
{
	int		i;

	i = 0;
	while (i < g_op_tab[line_num].num_params)
	{
		if (check_p_val(g_op_tab[line_num].params, tokes, i) == 0)
		{
			ft_putstr("Error: Invalid params\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int		get_line_num(char **tokes, int sp)
{
	int		line_num;
	int		flag;

	flag = 0;
	line_num = 0;
	while (line_num < 15 && flag == 0)
	{
		if (ft_strcmp(tokes[sp], g_op_tab[line_num].name) == 0)
			flag = 1;
		line_num++;
	}
	line_num--;
	if (flag == 0)
		return (-1);
	return (line_num);
}

int		check_line(char **tokes)
{
	t_labels	*label;
	int			line_num;
	int			lbl;

	label = (t_labels *)malloc(sizeof(t_labels));
	lbl = 0;
	if (is_label(tokes) == 1)
		lbl = 1;
	else if (is_label(tokes) == -1)
	{
		ft_putstr("Error: label must be lowercase ");
		ft_putendl(tokes[0]);
		return (0);
	}
	if ((line_num = get_line_num(tokes, lbl)) == -1)
	{
		ft_putstr("Error: function not found\n");
		return (0);
	}
	g_values->linenbr = line_num;
	if (check_params(tokes, line_num) == 0)
		return (0);
	return (1);
}
