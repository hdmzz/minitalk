NAME =	libftprintf.a

SRCS =	ft_printf.c \
		./ft_put.c \
		./ft_putnb.c

OBJS =	$(SRCS:.c=.o)

CC = gcc -Wall -Wextra -Werror

%.o: %.c ft_prinf.h Makefile
		$(CC) -I. -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) ft_printf.h
		ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
