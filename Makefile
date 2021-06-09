# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: b00d33r <b00d33r@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 02:09:09 by b00d33r           #+#    #+#              #
#    Updated: 2021/06/08 02:24:19 by b00d33r          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
FLAGS		= -Wall -Werror -Wextra
CLIENT		= client
SERVER		= server


all: $(CLIENT) $(SERVER)

$(CLIENT): main_client.o minitalk.h
	@$(CC) main_client.o -o $@ ; echo $@	

$(SERVER): main_server.o minitalk.o
	@$(CC) main_server -o $@

%.o: %.c
	@$(CC) $(FLAGS) $< -c 