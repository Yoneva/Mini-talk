# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 16:40:23 by amsbai            #+#    #+#              #
#    Updated: 2024/11/25 20:07:56 by amsbai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =  libftprintf/ft_putchar.c \
		libftprintf/ft_putstr.c \
		libftprintf/ft_putnbr.c \
		libftprintf/ft_strlen.c \
		libftprintf/hexamol.c \
		ft_printf.c \
		libftprintf/Anormfix.c \
		libftprintf/addresss.c
OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h

# prerequisite
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
.c.o: $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

bonus: all

re: fclean all

.PHONY: clean