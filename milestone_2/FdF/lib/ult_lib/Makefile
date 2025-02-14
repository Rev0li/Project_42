NAME = ult_lib.a

HEADER = ult_lib.h

SRCS =	\
		fd/ft_printf.c				\
		fd/ft_printf_utils.c		\
		fd/ft_printf_utils_2.c		\
		fd/get_next_line.c			\
		fd/output_utils.c			\
		\
		list/list_utils.c			\
		list/list_utils_2.c			\
		\
		memory/memory_utils.c		\
		memory/memory_utils_2.c		\
		\
		nbr/conversion_utils.c		\
		nbr/conversion_utils_2.c	\
		\
		string/string_utils_1.c		\
		string/string_utils_3.c		\
		string/string_utils_2.c		\
		string/string_utils_4.c		\
		\
		whoiam/char_utils.c


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

