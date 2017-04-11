# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 13:04:54 by qmoreaux          #+#    #+#              #
#    Updated: 2016/05/17 11:43:20 by qmoreaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libftprintf.a

SRC_PATH = ./src/
SRC_NAME = ft_printf.c \
		   ft_printf_init.c \
		   ft_parse_1.c \
		   ft_parse_2.c \
		   ft_parse_3.c \
		   ft_print_1.c \
		   ft_print_2.c \
		   ft_print_3.c \
		   convert/d/ft_putnbr_int.c \
	  	   convert/d/ft_putnbr_signed_char.c \
	  	   convert/d/ft_putnbr_short.c \
	  	   convert/d/ft_putnbr_long.c \
	  	   convert/d/ft_putnbr_long_long.c \
	  	   convert/d/ft_putnbr_intmax.c \
	  	   convert/d/ft_putnbr_ptrdiff.c \
	  	   convert/d/ft_putnbr_size.c \
		   convert/boux/ft_putnbr_uint.c \
	  	   convert/boux/ft_putnbr_unsigned_char.c \
	  	   convert/boux/ft_putnbr_ushort.c \
	  	   convert/boux/ft_putnbr_ulong.c \
	  	   convert/boux/ft_putnbr_ulong_long.c \
	  	   convert/boux/ft_putnbr_uintmax.c \
	  	   convert/boux/ft_putnbr_usize.c \
		   convert/boux/ft_tools.c \
		   convert/boux/ft_tools2.c \
		   convert/cs/ft_print_string_normal.c \
		   convert/cs/ft_print_string_wchar.c \
		   convert/cs/ft_print_char.c \
		   convert/cs/ft_print_char_tools.c \
		   convert/p/ft_print_pointer.c \
		   convert/p/ft_print_pointer_tools.c \
		   convert/aefg/ft_putnbr_double_classic.c \
		   convert/aefg/ft_putnbr_long_double_classic.c \
		   convert/aefg/ft_putnbr_double_scientific.c \
		   convert/aefg/ft_putnbr_long_double_scientific.c \
		   convert/aefg/ft_putnbr_double_both.c \
		   convert/aefg/ft_putnbr_long_double_both.c \
		   convert/aefg/ft_putnbr_double_hexa.c \
		   convert/aefg/ft_putnbr_long_double_hexa.c \
		   libft/ft_atoi.c \
	 	   libft/ft_itoa.c \
	       libft/ft_putchar.c \
	  	   libft/ft_putnbr.c \
	  	   libft/ft_putstr.c \
	  	   libft/ft_putnstr.c \
	  	   libft/ft_strchr.c \
	  	   libft/ft_strcmp.c \
	  	   libft/ft_strcpy.c \
	  	   libft/ft_strlen.c \
	  	   libft/ft_strnew.c \
		   libft/ft_memalloc.c \
		   libft/ft_memset.c \


OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./includes/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

CC = gcc
CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@mkdir $(OBJ_PATH)/libft 2> /dev/null || echo "" > /dev/null
	@mkdir $(OBJ_PATH)/convert 2> /dev/null || echo "" > /dev/null
	@mkdir $(OBJ_PATH)/convert/d 2> /dev/null || echo "" > /dev/null
	@mkdir $(OBJ_PATH)/convert/boux 2> /dev/null || echo "" > /dev/null
	@mkdir $(OBJ_PATH)/convert/cs 2> /dev/null || echo "" > /dev/null
	@mkdir $(OBJ_PATH)/convert/p 2> /dev/null || echo "" > /dev/null
	@mkdir $(OBJ_PATH)/convert/aefg 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
