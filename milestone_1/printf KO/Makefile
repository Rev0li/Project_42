NAME = libftprintf.a

HEADER = libftprinft.h

SRCS= ft_printf.c ft_putnbr.c ft_putnbr_base.c ft_strlen.c handle_base.c handle_putstr.c

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
