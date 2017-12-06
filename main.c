/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 11:14:41 by ecloete           #+#    #+#             */
/*   Updated: 2017/10/01 16:19:06 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		store_magic(t_file *file)
{
	unsigned int	magic;

	magic = COREWAR_EXEC_MAGIC;
	magic = ((magic >> 24) & 0xff) | ((magic << 8) & 0xff0000) |
		((magic >> 8) & 0xff00) | ((magic << 24) & 0xff000000);
	file->header.magic = magic;
}

static int		remove_ext(t_file *file, char *s)
{
	file->newname = (char*)malloc(sizeof(char) * ft_strlen(s));
	ft_strncpy(file->newname, s, ft_strlen(s) - 2);
	file->newname[ft_strlen(s) - 2] = '\0';
	file->newname = ft_strjoin(file->newname, ".cor");
	return (0);
}

int				open_file(char *s, t_file *file)
{
	remove_ext(file, s);
	file->fds = open(s, O_RDONLY);
	file->fdc = open(file->newname, O_CREAT | O_WRONLY, 0644);
	if (file->fds < 0 || file->fdc < 0)
	{
		ft_putstr("Error: could not open the file\n");
		return (0);
	}
	return (1);
}

int				checkfile(int argc, char **argv, t_file *file)
{
	int	i;

	if (argc != 2)
	{
		ft_putstr("Error: enter one paramater ./asm example.s\n");
		return (0);
	}
	i = ft_strlen(argv[1]);
	if (argv[1][i - 1] != 's' || argv[1][i - 2] != '.')
	{
		ft_putstr("Error: not a .s file\n");
		return (0);
	}
	if (open_file(argv[1], file) == 0)
		return (0);
	return (1);
}

int				main(int argc, char **argv)
{
	t_file *file;

	g_values = (t_val *)malloc(sizeof(t_val));
	if (!(file = (t_file *)malloc(sizeof(t_file))))
	{
		ft_putstr("Error: could not malloc 'file' struct\n");
		return (0);
	}
	if (checkfile(argc, argv, file) == 0)
		return (0);
	store_magic(file);
	read_file(file);
}
