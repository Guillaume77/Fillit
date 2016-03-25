#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/29 17:16:58 by gubourge          #+#    #+#              #
#    Updated: 2016/03/24 14:15:20 by daugier          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

RM	= rm -f

CC = gcc

NAME = fillit

SRCS = 	main.c \
		ft_bit_reset.c \
		ft_check_map.c \
		ft_fillit.c \
		ft_map.c \
		ft_move_bit.c \
		ft_power.c \
		ft_print_bit.c \
		ft_read_map.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strlen.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
