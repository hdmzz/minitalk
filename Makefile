NAME 		= client
NAMESV 		= server
SRCS 		= utils.c
SERVER_SRCS	= server.c
CLIENT_SRCS	= client.c
CLIENT_BONUS_SRCS	= client_bonus.c
SERVER_BONUS_SRCS	=server_bonus.c
BONUS_SRCS			= utils_bonus.c

HEADER		= minitalk
CC			= clang
CFLAGS		= -Wall -Wextra -Werror

%.o : %.c $(HEADER) ft_printf/libftprintf.a Makefile
	$(CC) $< -c -o $@

all:		ft_printf $(NAMESV) $(NAME)

ft_printf:
			@make -C ft_printf

$(NAME):	$(CLIENT_SRCS:.c=.o)
			$(CC) $(CFLAGS) $(CLIENT_SRCS) -L. ft_printf/libftprintf.a -o $(NAME)

$(NAMESV):	$(SERVER_SRCS:.c=.o) $(SRCS:.c=.o)
			$(CC) $(CFLAGS) $(SRCS) $(SERVER_SRCS) -L. ft_printf/libftprintf.a -o $(NAMESV)

bonus:	ft_printf server_bonus client_bonus

server_bonus:	$(SERVER_BONUS_SRCS:.c=.o) $(BONUS_SRCS:.c=.o)
				$(CC) $(CFLAGS) $(BONUS_SRCS) $(SERVER_BONUS_SRCS) -L. ft_printf/libftprintf.a -o server

client_bonus:	$(CLIENT_BONUS_SRCS:.c=.o)
				$(CC) $(CFLAGS) $(CLIENT_BONUS_SRCS) -L. ft_printf/libftprintf.a -o client

clean:
			rm -drf $(SERVER_SRCS:.c=.o) $(CLIENT_SRCS:.c=.o) $(SRCS:.c=.o) $(SERVER_BONUS_SRCS:.c=.o) $(CLIENT_BONUS_SRCS:.c=.o) $(BONUS_SRCS:.c=.o)
			@make clean -C ft_printf

fclean:	clean
			rm -drf server client server_bonus client_bonus
			@make fclean -C ft_printf

re:			fclean all

.PHONY:		all ft_printf clean fclean re
