# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 11:44:47 by hutzig            #+#    #+#              #
#    Updated: 2024/05/10 11:28:28 by hutzig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c \
		  ft_printf_char.c \
		  ft_printf_hexadecimal.c \
		  ft_printf_int.c \
		  ft_printf_string.c \
		  ft_printf_pointer.c \
		  ft_printf_unsigned_int.c \

OBJECTS = $(SOURCES:.c=.o)

HEADER = libft/libft.h

CC = cc

CFLGS = -Wall -Werror -Wextra

RM = rm -f

AR = ar rcs

all: $(NAME)
	
%.o:%.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	make -C libft
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
