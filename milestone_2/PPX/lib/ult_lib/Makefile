# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okientzl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 08:16:42 by okientzl          #+#    #+#              #
#    Updated: 2025/02/07 08:16:48 by okientzl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
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

OBJ = $(SRCS:%.c=$(OBJDIR)/%.o)
	
OBJDIR = obj

DEP = $(OBJ:.o=.d)

CFLAGS = -Wall -Wextra -Werror 

CC = cc

AR = ar rcs

all: $(NAME)

$(OBJDIR):
	@mkdir -p $@

$(NAME): $(OBJ) | $(OBJDIR)
	$(AR) $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.c Makefile $(HEADER) | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP) $(DEP_BONUS)

.PHONY: all clean fclean re
