# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adompe <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 18:53:55 by adompe            #+#    #+#              #
#*   Updated: 2016/10/03 14:47:01 by adompe           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME		=	../libft.a

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

SRC_C		=	ft_atoi.c \
				ft_bzero.c \
				ft_free_str_tab.c \
				ft_isalnum.c \
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c \
				ft_lltoi.c\
				ft_lstadd.c\
				ft_lstdel.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_max.c \
				ft_memalloc.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memdel.c\
				ft_memmove.c\
				ft_memset.c\
				ft_min.c \
				ft_power.c \
				ft_putchar.c\
				ft_putchar_fd.c\
				ft_putendl.c\
				ft_putendl_fd.c\
				ft_putnbr.c\
				ft_putnbr_base.c\
				ft_putnbr_fd.c\
				ft_putstr.c\
				ft_putstr_fd.c\
				ft_putstr_precision.c\
				ft_strcat.c\
				ft_strchr.c\
				ft_strclr.c\
				ft_strcmp.c\
				ft_strcpy.c\
				ft_strdel.c\
				ft_strdup.c\
				ft_strequ.c\
				ft_striter.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlen.c\
				ft_strmap.c\
				ft_strmapi.c\
				ft_strncat.c\
				ft_strncmp.c\
				ft_strncpy.c\
				ft_strndup.c \
				ft_strnequ.c\
				ft_strnew.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strsplit.c\
				ft_strstr.c\
				ft_strsub.c\
				ft_strtrim.c\
				ft_swap.c \
				ft_tablen.c\
				ft_tolower.c\
				ft_toupper.c\
				get_next_line.c\

SRC_O		=	$(SRC_C:.c=.o)

OBJ_PATH	=	objs

INC			=	-I ../includes

all:		$(NAME)

$(NAME):
	gcc -c $(SRC_C) $(FLAGS) $(INC)
	ar rc $(NAME) $(SRC_O)
	ranlib $(NAME)
	mkdir -p $(OBJ_PATH)
	mv $(SRC_O) $(OBJ_PATH)

clean:
	rm -rf $(OBJ_PATH)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		fclean clean re
