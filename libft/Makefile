# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: binr <binr@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 17:26:15 by binr              #+#    #+#              #
#    Updated: 2025/05/01 17:31:49 by binr             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_calloc.c ft_isdigit.c \
		ft_memset.c ft_printf_nbrs.c ft_printf_write.c \
		ft_printf.c ft_split.c ft_strlen.c

OBJS_DIR = objs_libft
OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJS_DIR)/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re