NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iincludes -Ilibft

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= \
	src/main/push_swap.c \
	src/main/benchmark.c \
	src/main/parse_options.c \
	src/algo/disorder.c \
	src/algo/simple/simple_big_5number.c \
	src/algo/simple/sort_three.c \
	src/algo/simple/sort_four.c \
	src/algo/simple/sort_five.c \
	src/algo/medium/medium_utils.c \
	src/algo/medium/sort_medium.c \
	src/algo/complex/complex_sort.c \
	src/arg/process_argument.c \
	src/arg/stack_linked.c \
	src/arg/string_argument.c \
	src/op/push_a_b.c \
	src/op/rotate_a_b.c \
	src/op/rotrotate_a_b.c \
	src/op/swap_a_b.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
