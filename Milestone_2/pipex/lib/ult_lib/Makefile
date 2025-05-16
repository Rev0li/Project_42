# Name of final library
NAME = ult_lib.a

# Header
HEADER = ult_lib.h

# Source files
SRCS = \
	fd/ft_printf.c \
	fd/ft_printf_utils.c \
	fd/ft_printf_utils_2.c \
	fd/get_next_line.c \
	fd/output_utils.c \
	list/list_utils.c \
	list/list_utils_2.c \
	memory/memory_utils.c \
	memory/memory_utils_2.c \
	nbr/conversion_utils.c \
	nbr/conversion_utils_2.c \
	string/string_utils_1.c \
	string/string_utils_3.c \
	string/string_utils_2.c \
	string/string_utils_4.c \
	whoiam/char_utils.c

# Directory for obj and dep
OBJDIR = obj
DEPDIR = dep

# Object and dependency files
OBJ = $(SRCS:%.c=$(OBJDIR)/%.o)
DEP = $(SRCS:%.c=$(DEPDIR)/%.d)

# Compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP
AR = ar rcs

all: $(NAME)

# Create necessary directories
$(OBJDIR) $(DEPDIR):
	@mkdir -p $@

# Build the library
$(NAME): $(OBJ) | $(OBJDIR) $(DEPDIR)
	$(AR) $(NAME) $(OBJ)

# Compilation rule for .c files
$(OBJDIR)/%.o: %.c Makefile $(HEADER) | $(OBJDIR) $(DEPDIR)
	@mkdir -p $(dir $@) $(DEPDIR)/$(dir $<)
	$(CC) $(CFLAGS) -c $< -o $@ -MF $(DEPDIR)/$(basename $<).d

### --- Cleaning rules --- ###

clean:
	rm -rf $(OBJDIR) $(DEPDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Include dependencies
-include $(DEP)

.PHONY: all clean fclean re
