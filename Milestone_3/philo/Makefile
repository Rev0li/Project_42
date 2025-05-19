# ─── Mandatory and Bonus Makefile ─────────────────────────────

NAME		= philo
BONUS_NAME	= philo_bonus

# Includes
include .mk/sources.mk
include .mk/flags.mk

# Directories
OBJDIR		= obj
DEPDIR		= dep
BONUS_OBJDIR= obj_bonus
BONUS_DEPDIR= dep_bonus

# Mandatory
OBJ			= $(SRCS:src/%.c=$(OBJDIR)/%.o)
DEP			= $(SRCS:src/%.c=$(DEPDIR)/%.d)

# Bonus
BONUS_OBJ	= $(BONUS_SRCS:bonus/%.c=$(BONUS_OBJDIR)/%.o)
BONUS_DEP	= $(BONUS_SRCS:bonus/%.c=$(BONUS_DEPDIR)/%.d)

all: $(NAME)

bonus: $(BONUS_NAME)

# ─── Auto-create folders ──────────────────────────────────────

$(OBJDIR):
	@mkdir -p $@

$(DEPDIR):
	@mkdir -p $@

$(BONUS_OBJDIR):
	@mkdir -p $@

$(BONUS_DEPDIR):
	@mkdir -p $@

# ─── Compilation rules ────────────────────────────────────────

$(NAME): $(OBJ) | $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(BONUS_NAME): $(BONUS_OBJ) | $(BONUS_OBJDIR) $(BONUS_DEPDIR)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJ)

$(OBJDIR)/%.o: src/%.c Makefile $(HEADER)
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(DEPDIR)/$<)
	$(CC) $(CFLAGS) $(INC) -MMD -MP -c $< -o $@ -MF $(DEPDIR)/$(basename $<).d

$(BONUS_OBJDIR)/%.o: bonus/%.c Makefile $(HEADER) | $(BONUS_OBJDIR) $(BONUS_DEPDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -MMD -MP -c $< -o $@ -MF $(BONUS_DEPDIR)/$(basename $<).d

# ─── Cleaning rules ───────────────────────────────────────────

clean:
	rm -rf $(OBJDIR) $(DEPDIR) $(BONUS_OBJDIR) $(BONUS_DEPDIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

-include $(DEP)
-include $(BONUS_DEP)

.PHONY: all clean fclean re bonus

