# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

# Répertoires
SRCDIR = .
TESTDIR = tdd-test
EXEDIR = exe-test

# Fichiers sources et tests
SRC = $(wildcard $(SRCDIR)/ft_*.c)
TESTS = $(wildcard $(TESTDIR)/test_ft_*.c)

# Création des noms de fichiers objets
OBJ = $(SRC:.c=.o)
TEST_OBJ = $(TESTS:.c=.o)

# Noms des exécutables dans exe-test (basés sur les noms des fichiers de test)
EXE = $(patsubst $(TESTDIR)/test_ft_%.c, $(EXEDIR)/test_%, $(TESTS))

# Cible principale pour créer le dossier et compiler tous les exécutables
all: $(EXEDIR) $(EXE)

# Créer le dossier exe-test si nécessaire
$(EXEDIR):
	mkdir -p $(EXEDIR)

# Compilation de chaque exécutable de test en utilisant les fichiers objets nécessaires
$(EXEDIR)/test_%: $(OBJ) $(TESTDIR)/test_ft_%.o | $(EXEDIR)
	$(CC) $(CFLAGS) $^ -o $@

# Génération des fichiers objets pour chaque source et chaque test
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets uniquement
clean:
	rm -f $(OBJ) $(TEST_OBJ)

# Nettoyage complet des fichiers objets et des exécutables
fclean: clean
	rm -rf $(EXEDIR)

# Recompilation complète
re: fclean all

# Exécution de tous les tests
rt: all
	@for exe in $(EXE); do ./$$exe; done

