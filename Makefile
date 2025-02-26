#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raphael <raphael@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 13:00:08 by rabiner           #+#    #+#              #
#    Updated: 2025/02/26 23:48:50 by raphael          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = libft

SRCS =	push_swap.c ft_node.c ft_sort.c ft_logic.c\
		ft_swap.c #ft_push.c ft_rotate.c ft_rerotate.c \

SRCSLIB = 	ft_atoi.c \
			#ft_printf.c ft_printf_nbrs.c ft_printf_write.c \

LIBFT_SRCS = $(addprefix $(LIBFTDIR)/, $(SRCSLIB))

SRCSALL = $(SRCS) $(LIBFT_SRCS)

OBJS = $(SRCSALL:.c=.o)

INCLUDES = -Ilibft

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re