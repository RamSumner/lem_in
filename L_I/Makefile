# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 11:06:11 by rsumner           #+#    #+#              #
#    Updated: 2019/08/16 10:47:30 by rsumner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c lists.c get_data.c serv_get.c serv_solut.c split.c solution.c find_path.c print_result.c
OBJ = main.o lists.o get_data.o serv_get.o serv_solut.o split.o solution.o find_path.o print_result.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo Compiling Lem_in ...
	@gcc -g $(FLAGS) $(SRC) -include ../libft/libft.h -o $(NAME) ../libft.a
	@mv $(NAME) ../$(NAME)

new:
	@echo Recompiling Lem_in ...
	@rm -rf ../$(NAME)
	@gcc -g $(FLAGS) $(SRC) -include ../libft/libft.h -o $(NAME) ../libft.a
	@mv $(NAME) ../$(NAME)

debug:
	@echo Recompiling Lem_in...
	@rm -rf ../$(NAME)
	@rm -rf ../$(NAME).dSYM
	@gcc -g $(FLAGS) $(SRC) -include ../libft/libft.h -o $(NAME) ../libft.a
	@mv $(NAME) ../$(NAME)
	@mv $(NAME).dSYM ../$(NAME).dSYM

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf ../$(NAME)
	@rm -rf ../$(NAME).dSYM

re: fclean all
