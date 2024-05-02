# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 11:40:53 by bmakhama          #+#    #+#              #
#    Updated: 2024/05/02 12:48:24 by bmakhama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRCS = ft_conv_char.c ft_conv_hex.c ft_conv_nbr.c ft_conv_ptr.c \
       ft_conv_str.c ft_conv_unnbr.c ft_putchar.c ft_putstr.c ft_printf.c 
OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I.
all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re