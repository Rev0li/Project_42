# main Makefile

# Predefined prefix for source files
SRC_DIR = src/

# Include modular sources file
-include .mk/sources.mk .mk/compilation_flags.mk

# Add the SRC_DIR prefix to each source file defined in sources.mk
SRCS := $(addprefix $(SRC_DIR), $(SRCS))

# Name of final library
NAME = ult_lib.a

# Header
HEADER = include/ult_lib.h

# Directory for obj and dep
OBJDIR = obj
DEPDIR = dep

# Object and dependency files
OBJ = $(SRCS:$(SRC_DIR)%.c=$(OBJDIR)/%.o)
DEP = $(SRCS:$(SRC_DIR)%.c=$(DEPDIR)/%.d)

all: $(NAME)

# Create necessary directories
$(OBJDIR) $(DEPDIR):
	@mkdir -p $@

# Build the library
$(NAME): $(OBJ) | $(OBJDIR) $(DEPDIR)
	$(AR) $(NAME) $(OBJ)

# Compilation rule for .c files
$(OBJDIR)/%.o: $(SRC_DIR)%.c Makefile $(HEADER) | $(OBJDIR) $(DEPDIR)
	@mkdir -p $(dir $@) $(DEPDIR)/$(dir $(subst $(SRC_DIR),,$<))
	$(CC) $(CFLAGS) -c $< -o $@ -MF $(DEPDIR)/$(subst $(SRC_DIR),,$(basename $<)).d


### --- Cleaning rules --- ###
clean:
	rm -rf $(OBJDIR) $(DEPDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Include dependencies
-include $(DEP)

.PHONY: all clean fclean re

