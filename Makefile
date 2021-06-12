# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 02:09:09 by b00d33r           #+#    #+#              #
#    Updated: 2021/06/12 18:52:56 by hboudhir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
FLAGS		= -Wall -Werror -Wextra
CLIENT		= client
SERVER		= server


all: $(CLIENT) $(SERVER)

$(CLIENT): client.o utils.o minitalk.h
	@$(CC) client.o utils.o -o $@

$(SERVER): server.o utils.o minitalk.h
	@$(CC) server.o utils.o -o $@

%.o: %.c
	@$(CC) $(FLAGS) $< -c 

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf server client
re: fclean all