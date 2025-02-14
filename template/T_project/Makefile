
# Name of final executables
NAME = main
NAME_BONUS = bonus

# Header for main exec
HEADER = include/main.h

# Header for bonus exec
HEADER_BONUS = include/checker_bonus.h

# Source for main exec
SRCS =	src/main.c

# Source for bonus
SRCS_BONUS =	src_bonus/_bonus.c

# Directory for obj and dep
OBJDIR = obj

# Files obj and dep
OBJ = $(SRCS:src/%.c=$(OBJDIR)/%.o)
OBJ_BONUS = $(SRCS_BONUS:src_bonus/%.c=$(OBJDIR)/%.o)

DEP = $(OBJ:.o=.d)
DEP_BONUS = $(OBJ_BONUS:.o=.d)

# Comp flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP

all: $(NAME)

$(OBJDIR):
	@mkdir -p $@

# Compilation of main exec
$(NAME): $(OBJ) | $(OBJDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Rule of compilation for main exec src 
$(OBJDIR)/%.o: src/%.c Makefile $(HEADER) | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

# Compilation of bonus exec
$(NAME_BONUS): $(OBJ_BONUS) | $(OBJDIR)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS)

# Rule of compilation for bonus exec src
$(OBJDIR)/%.o: src_bonus/%.c $(HEADER_BONUS) | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean : delete folder obj
clean:
	rm -rf $(OBJDIR)

# Fclean : delete exec and clean
fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

# Compilation again : fclean to all
re: fclean all

# Include file of dep
-include $(DEP) $(DEP_BONUS)

.PHONY: all clean fclean re bonus

