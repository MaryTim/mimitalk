MY_SOURCES = ft_printf.c \
			helpers/print_char.c \
			helpers/print_int.c \
			helpers/print_string.c \
			helpers/print_hexadecimal.c \
			helpers/print_unsigned_d.c \
			helpers/print_pointer.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

NAME = libftprintf.a

CC = gcc

CFLAGS += -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all