# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/16 21:37:19 by sde-spie          #+#    #+#              #
#    Updated: 2018/10/12 10:36:23 by sde-spie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C ./ft_printf/
	@cp ./ft_printf/libftprintf.a $(NAME)
	@echo "\033[1;34mMerged Libs\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

clean:
	@rm -rf  $(OBJ)
	@make clean -C ./libft/
	@make clean -C ./ft_printf/
	@echo "\033[1;34mMerged Libs\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf ./libft/libft.a
	@rm -rf ./ft_printf/libftprintf.a
	@echo "\033[1;34mMerged Libs\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

norme: fclean
	@/usr/bin/norminette $(SRC)
	@echo "\033[1;34mMerged Libs\t\033[1;33mNorminette\t\033[0;32m[DONE]\033[0m"
