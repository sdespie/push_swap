# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/16 21:37:19 by sde-spie          #+#    #+#              #
#    Updated: 2018/10/02 21:13:00 by sde-spie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TEST = ft_printf.out
SRC = cut.c flags.c ft_printf.c init_conv.c is_conv.c is_len_modif.c \
	  is_precis.c is_width.c pad.c parse_size_modif.c print_conv.c to_str.c\
	  print_s.c manage_pc.c print_d.c ft_intmax_toa.c print_c.c print_p.c\
	  print_u.c print_pc.c print_x.c print_o.c print_u_tool.c \
	  ft_itoa_base.c ft_strtolower.c get_unsigned.c ft_uintmax_toa.c \
	  ft_l_toa.c ft_int_toa.c put_wchar.c print_wchar.c print_s_uptool.c

CC = gcc
CFLAGS = -Wall -Wextra #-fsanitize=address
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C ../libft
	@cp ../libft/libft.a $(NAME)
	@$(CC) -c $(FLAGS) $(SRC) -I ../libft/libft.h
	@ar rc $(NAME) $(OBJ)
#	@$(CC) $(CFLAGS) main.c $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

clean:
	@rm -rf  $(OBJ)
	@make clean -C ../libft/
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf ../libft/libft.a
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

norme: fclean
	@/usr/bin/norminette $(SRC)
	@echo "\033[1;34mft_printf\t\033[1;33mNorminette\t\033[0;32m[DONE]\033[0m"
