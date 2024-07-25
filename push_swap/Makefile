# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 09:30:18 by bmakhama          #+#    #+#              #
#    Updated: 2024/07/25 12:17:42 by bmakhama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

NAME = push_swap
SRC = push_swap.c add_node.c valid_and_init.c split.c free_stack.c \
		push_operation.c rotate_operation.c rev_rot_operation.c swap_operation.c sorted_stack.c \
		sort_three.c sort_stack.c sort_stack_utils.c moves_a_b.c cheapest_move.c fill_data_struct.c \
		max_min_nb.c valid_and_init_utils.c split_reserve_quotes.c


OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	make -C libft clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean