SRCS = server.c \
		client.c \
		client_bonus.c \
		server_bonus.c

OBJS := $(SRCS:.c=.o)

NAME = minitalk

CC = cc

CFLAGS += -Wall -Werror -Wextra

all: $(NAME)

$(NAME): dependencies server client

dependencies:
	make -C ft_printf
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

server:		server.o
		${CC} ${CFLAGS} $? ft_printf/libftprintf.a libft/libft.a -o server

client:		client.o
		${CC} ${CFLAGS} $? ft_printf/libftprintf.a libft/libft.a -o client

bonus: dependencies client_bonus server_bonus

client_bonus:		client_bonus.o
		${CC} ${CFLAGS} $? ft_printf/libftprintf.a libft/libft.a -o client_bonus

server_bonus:		server_bonus.o
		${CC} ${CFLAGS} $? ft_printf/libftprintf.a libft/libft.a -o server_bonus

clean:
	rm -f $(OBJS)
	make clean -C ft_printf
	make clean -C libft

fclean: clean
	rm -f server client server_bonus client_bonus
	make fclean -C ft_printf
	make fclean -C libft

re: fclean all