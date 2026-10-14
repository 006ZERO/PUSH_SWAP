

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -Iincludes -Ilibft

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= \
	src/main/push_swap.c \
	src/main/benchmark.c \
	src/main/parse_options.c \
	src/algorithm/disorder.c \
	src/algorithm/simple/simple_big_5number.c \
	src/algorithm/simple/sort_three.c \
	src/algorithm/simple/sort_four.c \
	src/algorithm/simple/sort_five.c \
	src/algorithm/medium/medium_utils.c \
	src/algorithm/medium/sort_medium.c \
	src/algorithm/complex/complex_sort.c \
	src/argument/process_argument.c \
	src/argument/stack_linked.c \
	src/argument/string_argument.c \
	src/operation/push_a_b.c \
	src/operation/rotate_a_b.c \
	src/operation/rotrotate_a_b.c \
	src/operation/swap_a_b.c

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
