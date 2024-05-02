# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 12:01:37 by bmakhama          #+#    #+#              #
#    Updated: 2024/05/02 13:16:45 by bmakhama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = lib/libft/libft.a
FT_printf = lib/ft_printf/ft_printf.a

# mandatory
NAME = server
CLIENT = client

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_SERVER = ${SRC_SERVER:.c=.o}
OBJ_CLIENT = ${SRC_CLIENT:.c=.o}

# bonus
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c

OBJ_SERVER_BONUS = ${SRC_SERVER_BONUS:.c=.o}
OBJ_CLIENT_BONUS = ${SRC_CLIENT_BONUS:.c=.o}


all: $(NAME) $(CLIENT)
	
$(NAME): $(LIBFT) $(FT_printf) $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) $(FT_printf) -o $(NAME)

$(CLIENT): $(LIBFT) $(FT_printf) $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) $(FT_printf) -o $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)
	
$(SERVER_BONUS): $(LIBFT) $(FT_printf) $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(LIBFT) $(FT_printf) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(LIBFT) $(FT_printf) $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(LIBFT) $(FT_printf) -o $(CLIENT_BONUS)

$(LIBFT):
	make -C lib/libft

$(FT_printf):
	make -C lib/ft_printf

clean : 
	make -C ./lib/ft_printf clean
	make -C ./lib/libft clean
	rm -rf $(OBJ_SERVER) $(OBJ_CLIENT)
	rm -rf $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean : clean
	make -C ./lib/ft_printf fclean
	make -C ./lib/libft fclean
	rm -rf $(NAME) $(CLIENT)
	rm -rf $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus 