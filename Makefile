# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 13:34:30 by fsuomins          #+#    #+#              #
#    Updated: 2023/02/15 15:59:56 by fsuomins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client

BONUS = minitalk_bonus
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SERVER_SRCS = ./mandatory/src/server.c
CLIENT_SRCS = ./mandatory/src/client.c

SERVER_SRCS_BONUS = ./bonus/src_bonus/server_bonus.c
CLIENT_SRCS_BONUS = ./bonus/src_bonus/client_bonus.c

CC = -cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = libft/libft.a

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER):
	make -C libft
	$(CC) $(SERVER_SRCS) $(INCLUDE) $(FLAGS) -o $(SERVER)

$(CLIENT):
	make -C libft
	$(CC) $(CLIENT_SRCS) $(INCLUDE) $(FLAGS) -o $(CLIENT)

bonus:  $(BONUS)

$(BONUS) : $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS):
	make -C libft
	$(CC) $(SERVER_SRCS_BONUS) $(INCLUDE) $(FLAGS) -o $(SERVER_BONUS)

$(CLIENT_BONUS):
	make -C libft
	$(CC) $(CLIENT_SRCS_BONUS) $(INCLUDE) $(FLAGS) -o $(CLIENT_BONUS)

clean:
	make fclean -C libft

fclean: clean
	rm -rf $(NAME) $(CLIENT) $(SERVER) $(BONUS) $(CLIENT_BONUS) $(SERVER_BONUS)
	
re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus libft clean fclean re
