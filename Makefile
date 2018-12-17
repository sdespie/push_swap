# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/16 21:37:19 by sde-spie          #+#    #+#              #
#    Updated: 2018/12/17 09:47:22 by sde-spie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftswap
SRC = init_struct.c fill_pile.c easy_order.c swap.c\
	  sorting_ft.c solve.c sort_short.c ft_atoi_long.c\
	  get_next_line.c free.c mini_sort.c print_pile.c\
	  utils.c utils2.c mode_mgmt.c
LIB = libftswap.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C ./libft
	@cp ./libft/libft.a $(LIB)
	@$(CC) -c $(FLAGS) $(SRC) -I ./libft/ft_printf.h
	@ar rc $(LIB) $(OBJ)
	@$(CC) $(CFLAGS) push_swap.c -L. -lftswap -o push_swap
	@$(CC) $(CFLAGS) checker.c -L. -lftswap -o checker
	@echo "\033[1;34mpush_swap\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

clean:
	@rm -rf  $(OBJ) $(LIB)
	@make clean -C ./libft/
	@echo "\033[1;34mpush_swap\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm push_swap checker
	@rm -rf ./libft/libft.a
	@make fclean -C ./libft/
	@echo "\033[1;34mpush_swap\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

norme: fclean
	@/usr/bin/norminette $(SRC)
	@echo "\033[1;34mpush_swap\t\033[1;33mNorminette\t\033[0;32m[DONE]\033[0m"
