# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 11:06:11 by rsumner           #+#    #+#              #
#    Updated: 2019/07/11 13:10:20 by rsumner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

SRC = main.c lists.c get_data.c help.c split.c
OBJ = main.o lists.o get_data.o help.o split.o

all: $(NAME)

$(NAME):
	@cd libft/ && make re
	@gcc -g -Wall -Wextra -Werror $(SRC) -include libft/libft.h -o $(NAME) libft/libft.a

clean:
	@/bin/rm -f $(OBJ)
	@cd libft/ && make clean

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft/libft.a
	@cd libft/ && make fclean

re: fclean all