NAME = libftprintf.a

HEADER = ft_prinft.h

SRCS= ft_printf.c ft_putchar.c ft_putstr.c ft_strlen.c ft_putunbr.c ft_hexa.c ft_putnbr.c ft_pointer.c 

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror 
CC = cc
AR = ar rcs


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)


%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
