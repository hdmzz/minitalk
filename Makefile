SERVER_SRCS		= server.c
CLIENT_SRCS		= client.c
HEADER			= minitalk
CC			= clang
CFLAGS		= -Wall -Wextra -Werror

%.o : %.c $(HEADER) ft_printf/libftprintf.a
	$(CC) $< -c -o $@

all:		ft_printf server client

ft_printf:
			@make -C ft_printf

server:		$(SERVER_SRCS:.c=.o) 
				$(CC) $(CFLAGS) $(SERVER_SRCS) -L. ft_printf/libftprintf.a -o server

client:		$(CLIENT_SRCS:.c=.o) 
				$(CC)  $(CLIENT_SRCS)  -o client

clean:
			rm -drf $(SERVER_SRCS:.c=.o) $(CLIENT_SRCS:.c=.o)
			@make clean -C ft_printf

fclean:	clean
			rm -drf server client
			@make fclean -C ft_printf

re:			fclean all

.PHONY:		all ft_printf clean fclean re

