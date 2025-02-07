NAME = pipex

HEADER = src/pipex.h

SRCS = src/pipex.c	\
	   src/utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

LIB = ult_lib/ult_lib.a

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	make all -C ult_lib
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C ult_lib

fclean: clean
	$(RM) $(NAME)
	make fclean -C ult_lib

re: fclean all

.PHONY: all clean fclean re

