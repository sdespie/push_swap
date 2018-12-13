NAME = libft.a
FLAGS = -Werror -Wall -Wextra
SRC = 	ft_strlen.c \
		ft_isalnum.c \
		ft_itoa.c \
		ft_putendl_fd.c\
		ft_strclr.c \
		ft_striter.c \
		ft_strncmp.c \
		ft_strstr.c \
		ft_isalpha.c \
		ft_memalloc.c \
		ft_putnbr.c \
		ft_strcmp.c \
		ft_striteri.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_isascii.c \
		ft_memdel.c \
		ft_putnbr_fd.c \
		ft_strcpy.c \
		ft_strjoin.c \
		ft_strncpy.c \
		ft_strsplit.c \
		ft_atoi.c \
		ft_isdigit.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strdel.c \
		ft_strequ.c \
		ft_bzero.c \
		ft_isprint.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_strdup.c \
		ft_strnew.c \
		ft_strtrim.c \
		ft_countwords.c \
		ft_isspace.c \
		ft_putendl.c \
		ft_strchr.c \
		ft_strmap.c \
		ft_strnstr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strmapi.c \
		ft_strrchr.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_memccpy.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_lstdel.c \
		ft_lstiter.c \
		ft_lstadd.c \
		ft_lstdelone.c \
		ft_lstnew.c \
		ft_lstmap.c \
		ft_strcat.c \
		ft_strlcat.c \
		ft_strncat.c \
		ft_min2.c \
		ft_min3.c \
		ft_min4.c \
		ft_max2.c \
		ft_max3.c \
		ft_max4.c \
		ft_nbrlen.c \
		ft_realloc.c \
		ft_strjoin1.c

COMP = $(SRC:%.c=%.o)
INC = ./includes/

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) -I $(INC)
	@ar rc $(NAME) $(COMP)
	@ranlib $(NAME)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
