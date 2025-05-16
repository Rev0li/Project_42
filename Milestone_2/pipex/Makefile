# ### --- Declaration variable --- ###

# # Name of final executables
# NAME = pipex

# # Header for main exec
# HEADER = \
# 		 include/pipex.h

# # Source for main exec
# SRCS = \
# 	   src/pipex.c \
# 	   src/utils.c	\
# 	   src/clean_free.c

# # Directory for obj and dep
# OBJDIR = obj

# # Files obj and dep
# OBJ = $(SRCS:src/%.c=$(OBJDIR)/%.o)
# DEP = $(OBJ:.o=.d)

# # Comp flags
# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g -MMD -MP -Iinclude

# # For compiling and linking the library
# LIB_DIR = lib/ult_lib
# LIB = $(LIB_DIR)
# # Get all source files from the library
# #LIB_SRCS = $(shell find $(LIB_DIR) -type f -name "*.c")


# all: $(LIB) $(NAME)

# # Compilation of ult_lib
# $(LIB): #$(LIB_SRCS)
# 	@$(MAKE) -C $(LIB_DIR)

# # Create obj directory
# $(OBJDIR):
# 	@mkdir -p $@

# ### --- Compilation rules --- ###

# # Compilation of the main executable
# $(NAME): $(OBJ) $(LIB) | $(OBJDIR)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

# # Rule of compilation for main exec src 
# $(OBJDIR)/%.o: src/%.c Makefile $(HEADER) | $(OBJDIR)
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) -c $< -o $@

# ### --- Classic rules --- ###

# # Clean : delete folder obj
# clean:
# 	rm -rf $(OBJDIR)
# 	@$(MAKE) -C $(LIB_DIR) clean

# # Fclean : delete exec and clean
# fclean: clean
# 	rm -f $(NAME)
# 	@$(MAKE) -C $(LIB_DIR) fclean

# # Recompile everything from scratch
# re: fclean all

# # Include file of dep
# -include $(DEP)

# .PHONY: all clean fclean re

# Name of final executables
NAME = pipex

# Header for main exec
HEADER = \
		 include/pipex.h

# Source for main exec
SRCS = \
	   src/pipex.c \
	   src/utils.c \
	   src/clean_free.c

# Directory for obj and dep
OBJDIR = obj
DEPDIR = dep

# Object and dependency files
OBJ = $(SRCS:src/%.c=$(OBJDIR)/%.o)
DEP = $(SRCS:src/%.c=$(DEPDIR)/%.d)

# Comp flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP -Iinclude

# For compiling and linking the library
LIB_DIR = lib/ult_lib

all: lib $(NAME)

# Compile the library first
lib:
	@$(MAKE) -C $(LIB_DIR)

# Create necessary directories
$(OBJDIR) $(DEPDIR):
	@mkdir -p $@

### --- Compilation rules --- ###

# Compilation of the main executable
$(NAME): $(OBJ) | $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_DIR)/ult_lib.a

# Rule of compilation for main exec src 
$(OBJDIR)/%.o: src/%.c Makefile $(HEADER) | $(OBJDIR) $(DEPDIR)
	@mkdir -p $(dir $@) $(DEPDIR)/$(dir $<)
	$(CC) $(CFLAGS) -c $< -o $@ -MF $(DEPDIR)/$(basename $<).d

### --- Classic rules --- ###

# Clean : delete folder obj
clean:
	rm -rf $(OBJDIR) $(DEPDIR)
	@$(MAKE) -C $(LIB_DIR) clean

# Fclean : delete exec and clean
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean

# Recompile everything from scratch
re: fclean all

# Include file of dep
-include $(DEP)

.PHONY: all clean fclean re lib