NAME = ult_lib.a

HEADER = ult_lib.h

SRCS = conversion_utils_2.c list_utils_2.c memory_utils_2.c output_utils.c string_utils_1.c string_utils_3.c char_utils.c conversion_utils.c list_utils.c memory_utils.c string_utils_2.c string_utils_4.c ft_printf.c ft_printf_utils.c ft_printf_utils_2.c get_next_line.c

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

