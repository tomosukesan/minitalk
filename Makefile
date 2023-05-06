# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 07:12:51 by ttachi            #+#    #+#              #
#    Updated: 2023/05/06 22:08:17 by ttachi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = CC
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_SERVER_BONUS = ./bonus/server_bonus.c
SRC_CLIENT_BONUS = ./bonus/client_bonus.c

OBJ_SERVER = $(SRC_SERVER:%.c=%.o)
OBJ_CLIENT = $(SRC_CLIENT:%.c=%.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:%.c=%.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:%.c=%.o)


ifdef WITH_BONUS
	OBJ_SERVER = $(OBJ_SERVER_BONUS)
	OBJ_CLIENT = $(OBJ_CLIENT_BONUS)
endif

all: $(NAME)
$(NAME): libft server client
libft:
	@make -C libft
server: $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o server $(OBJ_SERVER) $(LIBFT)
client: $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o client $(OBJ_CLIENT) $(LIBFT)

bonus:
	@make WITH_BONUS=1

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) libft/*.o
	$(RM) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
fclean: clean
	$(RM) server client $(LIBFT)
re: fclean all

.PHONY: all libft bonus clean fclean re
