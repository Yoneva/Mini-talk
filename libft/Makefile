# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 13:16:23 by amsbai            #+#    #+#              #
#    Updated: 2024/11/07 23:51:02 by amsbai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_isalpha.c ft_isprint.c ft_memset.c ft_strlen.c ft_toupper.c \
       ft_atoi.c ft_memchr.c ft_strchr.c ft_strncmp.c ft_bzero.c \
       ft_isascii.c ft_memcmp.c ft_strdup.c ft_strnstr.c ft_calloc.c \
       ft_isdigit.c ft_memcpy.c ft_strlcat.c ft_strrchr.c ft_isalnum.c \
       ft_islower.c ft_memmove.c ft_strlcpy.c ft_tolower.c ft_strjoin.c \
	   ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c ft_striteri.c \
	   ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c 
SRCSBON =ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c \
	   ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c\
	   ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstdelone_bonus.c \
	   ft_lstmap_bonus.c
OBJS = $(SRCS:.c=.o)
OBJSBON = $(SRCSBON:.c=.o)
HEADER = libft.h

# prerequisite
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME) $(OBJSBON)
	ar rcs $(NAME) $(OBJSBON)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
