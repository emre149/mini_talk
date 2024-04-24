# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ededemog <ededemog@student.42.fr>          +#+ +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 15:05:23 by ededemog          #+#    #+#              #
#    Updated: 2024/04/22 14:50:50 by ededemog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Définir les sources pour les versions normales et bonus
CLIENT_SRCS = src/client.c src/mini_talk_utils.o
SERVER_SRCS = src/server.c src/mini_talk_utils.o
CLIENT_BONUS_SRCS = mini_talk_bonus/client_bonus.c src/mini_talk_utils.o
SERVER_BONUS_SRCS = mini_talk_bonus/server_bonus.c src/mini_talk_utils.o

# Définir les sources pour ft_printf
FT_PRINTF_SRCS = inc/ft_printf/ft_printf.c inc/ft_printf/ft_printf_utils.c inc/ft_printf/other_utils.c
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)

CLIENT_NAME = client
SERVER_NAME = server
CLIENT_BONUS_NAME = client_bonus
SERVER_BONUS_NAME = server_bonus

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS) $(FT_PRINTF_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(SERVER_NAME): $(SERVER_SRCS) $(FT_PRINTF_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_SRCS) $(FT_PRINTF_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(SERVER_BONUS_NAME): $(SERVER_BONUS_SRCS) $(FT_PRINTF_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

inc/ft_printf/%.o: inc/ft_printf/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle bonus pour compiler uniquement les fichiers bonus
bonus: $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

clean:
	rm -f src/*.o inc/ft_printf/*.o mini_talk_bonus/*.o

fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
