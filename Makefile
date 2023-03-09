CC = cc

CFLAGS = -Werror -Wextra -Wall -o

SRC = ft_lstsize.c move_calc_big.c ft_push_swap_big.c move_calc_small.c \
ft_atoi.c ft_push_swap_small.c operations_push.c ft_execute_move_b.c \
ft_sort3.c operations_rotate.c  helpers1.c helpers2.c helpers3.c \
operations_rotate_r.c ft_execute_move.c ft_ini_list.c operations_swap.c \
ft_lstadd_back.c ft_lstlast.c main.c ft_lstnew.c

BNS_SRC = BONUS/checker.c BONUS/get_next_line_utils.c BONUS/get_next_line.c \
BONUS/checker_utils.c helpers1.c helpers2.c helpers3.c ft_ini_list.c \
operations_rotate.c operations_rotate_r.c operations_swap.c operations_push.c \
ft_lstsize.c ft_lstnew.c ft_lstlast.c ft_lstadd_back.c ft_atoi.c

NAME = push_swap

BNS_NAME = checker

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(NAME) $(SRC)

clean:

fclean: clean
	@-rm -f $(NAME)
	@-rm -f $(BNS_NAME)

BONUS: $(BNS_NAME)

$(BNS_NAME):
	$(CC) $(CFLAGS) $(BNS_NAME) $(BNS_SRC)

re: fclean all
