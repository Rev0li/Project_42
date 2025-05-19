# Name of final executables
NAME = philo

include .mk/sources.mk
include .mk/flags.mk
# Directory for obj and dep
OBJDIR = obj
DEPDIR = dep

# Object and dependency files
OBJ = $(SRCS:src/%.c=$(OBJDIR)/%.o)
DEP = $(SRCS:src/%.c=$(DEPDIR)/%.d)

all: $(NAME)

# Create necessary directories
$(OBJDIR) $(DEPDIR):
	@mkdir -p $@

### --- Compilation rules --- ###

# Compilation of the main executable
$(NAME): $(OBJ) | $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Rule of compilation for main exec src 
$(OBJDIR)/%.o: src/%.c Makefile $(HEADER) | $(OBJDIR) $(DEPDIR)
	@mkdir -p $(dir $@) $(DEPDIR)/$(dir $<)
	$(CC) $(CFLAGS) -c $< -o $@ -MF $(DEPDIR)/$(basename $<).d

### --- Classic rules --- ###

# Clean : delete folder obj
clean:
	rm -rf $(OBJDIR) $(DEPDIR)

# Fclean : delete exec and clean
fclean: clean
	rm -f $(NAME)

# Recompile everything from scratch
re: fclean all

# Include file of dep
-include $(DEP)

.PHONY: all clean fclean re
