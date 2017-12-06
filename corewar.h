/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 11:22:02 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/10/01 16:09:49 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "libft/libft.h"
# include "op.h"

typedef	struct		s_file
{
	int				fds;
	int				fdc;
	char			*newname;
	struct s_header	header;
}					t_file;

typedef	struct		s_val
{
	unsigned char	opcode;
	unsigned char	encode;
	unsigned char	*param1;
	unsigned char	*param2;
	unsigned char	*param3;
	int				linenbr;
	int				file_pos;
	struct s_val	*next;
}					t_val;

typedef struct		s_op
{
	char			*name;
	int				num_params;
	int				params[MAX_ARGS_NUMBER];
	int				op_code;
	int				cycle;
	char			*desciption;
	int				acb;
	int				something;
}					t_op;
extern t_op			g_op_tab[17];

typedef struct		s_lines
{
	char			*line;
	int				bytecount;
	int				line_num;
	struct s_lines	*next;
}					t_lines;

typedef struct		s_labels
{
	char			*label;
	int				line_num;
	struct s_label	*next;
}					t_labels;

t_val				*g_values;
int					read_file(t_file *file);
int					generate_header(t_header *header, char *line, int i);
char				**ft_strtoke(char *line, char b);
int					check_line(char **tokes);
void				encode(char **newl, t_val *values);
int					is_label(char **line);

#endif
