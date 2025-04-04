
NAME = debug

CC = cc
RM = rm -f
CFLAGS = -g -Wall -Wextra -Werror

SRCS =	push_swap.c ft_sort.c ft_logic.c \
		ft_copy_list.c ft_free.c ft_node.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I. -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re