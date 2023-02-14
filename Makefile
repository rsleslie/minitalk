# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 09:38:40 by rleslie-          #+#    #+#              #
#    Updated: 2023/02/14 16:27:41 by rleslie-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT =  client

SERVER_SRCS = server.c
CLIENT_SRCS =  client.c

CC = -cc
FLAGS = -Wall -Wextra -Werror -g
INCLUDE = libft/libft.a

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER):
	@make -C libft
	$(CC) $(SERVER_SRCS) $(INCLUDE) $(FLAGS) -o $(SERVER)

$(CLIENT):
	@make -C libft
	$(CC) $(CLIENT_SRCS) $(INCLUDE) $(FLAGS) -o $(CLIENT)
	
clean:
		@make fclean -C libft
		rm -rf $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
		rm -rf $(NAME) $(CLIENT) $(SERVER)
		
re: fclean all

	