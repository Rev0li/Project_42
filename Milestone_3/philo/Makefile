# ─── Mandatory and Bonus Makefile ─────────────────────────────

NAME		= philo

# Includes
include .mk/sources.mk
include .mk/flags.mk

# Directories
OBJDIR		= obj
DEPDIR		= dep

# Mandatory
OBJ			= $(SRCS:src/%.c=$(OBJDIR)/%.o)
DEP			= $(SRCS:src/%.c=$(DEPDIR)/%.d)

all: $(NAME)

bonus: $(BONUS_NAME)

# ─── Auto-create folders ──────────────────────────────────────

$(OBJDIR):
	@mkdir -p $@

$(DEPDIR):
	@mkdir -p $@

# ─── Compilation rules ────────────────────────────────────────

$(NAME): $(OBJ) | $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJDIR)/%.o: src/%.c Makefile $(HEADER)
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(DEPDIR)/$<)
	$(CC) $(CFLAGS) $(INC) -MMD -MP -c $< -o $@ -MF $(DEPDIR)/$(basename $<).d

# ─── Cleaning rules ───────────────────────────────────────────

clean:
	rm -rf $(OBJDIR) $(DEPDIR) 

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
