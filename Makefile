# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 15:05:23 by ededemog          #+#    #+#              #
#    Updated: 2024/04/19 15:05:26 by ededemog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = src/client.c src/mini_talk_utils.o inc/ft_printf/ft_printf_utils.o inc/ft_printf/ft_printf.o inc/ft_printf/other_utils.o
SERVER_SRCS = src/server.c src/mini_talk_utils.o inc/ft_printf/ft_printf_utils.o inc/ft_printf/ft_printf.o inc/ft_printf/other_utils.o
CLIENT_NAME = client
SERVER_NAME = server

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS)
	$(CC) $(CFLAGS) -o $@ $^

$(SERVER_NAME): $(SERVER_SRCS)
	$(CC) $(CFLAGS) -o $@ $^

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

inc/ft_printf/%.o: inc/ft_printf/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o inc/ft_printf/*.o

fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re
