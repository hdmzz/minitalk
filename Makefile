NAME 		= client
NAMESV 		= server
SRCS 		= utils.c
SERVER_SRCS	= server.c
CLIENT_SRCS	= client.c
HEADER		= minitalk
CC			= clang
CFLAGS		= -Wall -Wextra -Werror

%.o : %.c $(HEADER) ft_printf/libftprintf.a Makefile
	$(CC) $< -c -o $@

all:		ft_printf $(NAMESV) $(NAME)

ft_printf:
			@make -C ft_printf

$(NAME):	$(CLIENT_SRCS:.c=.o)
			$(CC)  $(CLIENT_SRCS) -L. ft_printf/libftprintf.a -o $(NAME)

$(NAMESV):	$(SERVER_SRCS:.c=.o) $(SRCS:.c=.o)
			$(CC) $(CFLAGS) $(SRCS) $(SERVER_SRCS) -L. ft_printf/libftprintf.a -o $(NAMESV)

clean:
			rm -drf $(SERVER_SRCS:.c=.o) $(CLIENT_SRCS:.c=.o) $(SRCS:.c=.o)
			@make clean -C ft_printf

fclean:	clean
			rm -drf server client
			@make fclean -C ft_printf

re:			fclean all

.PHONY:		all ft_printf clean fclean re

