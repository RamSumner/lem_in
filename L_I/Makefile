# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 11:06:11 by rsumner           #+#    #+#              #
#    Updated: 2019/08/20 16:30:35 by rsumner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c lists.c get_data.c serv_get.c serv_solut.c solution.c find_path.c print_result.c add_room_link.c serv_main.c lists_moove.c
OBJ = main.o lists.o get_data.o serv_get.o serv_solut.o solution.o find_path.o print_result.o add_room_link.o serv_main.o lists_moove.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo Compiling Lem_in ...
	@gcc -g $(FLAGS) $(SRC) -I ../libft/libft.h -I ../libft/ft_printf/ft_printf.h -o $(NAME) ../libft.a ../libftprintf.a
	@mv $(NAME) ../$(NAME)

new:
	@echo Recompiling Lem_in ...
	@rm -rf ../$(NAME)
	@gcc -g $(FLAGS) $(SRC) -I ../libft/libft.h -I ../libft/ft_printf/ft_printf.h -o $(NAME) ../libft.a ../libftprintf.a
	@mv $(NAME) ../$(NAME)

debug:
	@echo Recompiling Lem_in...
	@rm -rf ../$(NAME)
	@rm -rf ../$(NAME).dSYM
	@gcc -g $(FLAGS) $(SRC) -I ../libft/libft.h -I ../libft/ft_printf/ft_printf.h -o $(NAME) ../libft.a ../libftprintf.a
	@mv $(NAME) ../$(NAME)
	@mv $(NAME).dSYM ../$(NAME).dSYM

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf ../$(NAME)
	@rm -rf ../$(NAME).dSYM

re: fclean all
