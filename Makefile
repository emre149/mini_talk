CC = cc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: src/server.o src/mini_talk_utils.o inc/ft_printf/ft_printf_utils.o inc/ft_printf/ft_printf.o inc/ft_printf/other_utils.o
	$(CC) $(CFLAGS) $^ -o server

client: src/client.o src/mini_talk_utils.o inc/ft_printf/ft_printf_utils.o inc/ft_printf/ft_printf.o inc/ft_printf/other_utils.o
	$(CC) $(CFLAGS) $^ -o client

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

inc/ft_printf/%.o: inc/ft_printf/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o inc/ft_printf/*.o server client
