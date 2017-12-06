# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/06 10:38:06 by wvon-gra          #+#    #+#              #
#    Updated: 2017/10/01 18:39:06 by prmvinje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= asm

CFLAGS	= -Wall -Werror -Wextra

SRC =	main.c \
		read.c \
		generate_header.c \
		ft_strtoke.c \
		op.c \
		val_line.c \
		encode.c \
		is_label.c \

OBJ = $(SRC:.c=.o)

LIBFLAGS = -I./ -L ./libft -lft

all: $(NAME)

$(NAME):
		make all -C libft/ 
			gcc $(CFLAGS) -o $(NAME) $(SRC) $(LIBFLAGS)
		@echo "-----Compiled-----"
clean:
		rm -f $(OBJ)
			make clean -C libft/

fclean: clean
		rm -f $(NAME)
			make fclean -C libft/

re: fclean all
