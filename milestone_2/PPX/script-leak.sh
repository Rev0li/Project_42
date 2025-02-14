#!/bin/bash
# script-leak.sh
# Ce script réalise plusieurs tests :
# 1. Exécution normale pour récupérer les codes de retour et les messages d'erreur.
# 2. Exécution sous Valgrind pour visualiser d'où proviennent d'éventuelles fuites mémoire,
#    notamment en cas d'erreur.
#
# Les cas testés sont :
# - Cas de base (commande valide)
# - Infile inaccessible
# - Commande inconnue
# - Outfile inaccessible

# Définition des couleurs pour l'affichage
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
BLUE_BG='\033[44m'
NC='\033[0m'

# Nettoyage des fichiers temporaires et dossiers éventuels
rm -f infile outfile bash_out.txt pipex_err.txt bash_err.txt
rm -rf no_write_dir

##############################################
# 1. Test mémoire (cas de base) et exécution normale
##############################################
echo -e "${BLUE_BG}----------------------------------------${NC}"
echo -e "${YELLOW}Test mémoire (Valgrind - cas de base) :${NC}"
# Création d'un infile valide
echo -e "ligne1\nligne2 mot\nligne3\nligne4 mot" > infile

# Exécution sous Valgrind
valgrind_output_base=$(valgrind --leak-check=full --quiet ./pipex infile "cat" "grep mot" outfile 2>&1)
def_line_base=$(echo "$valgrind_output_base" | grep "definitely lost:")
if [[ $def_line_base != *"0 bytes"* ]]; then
    echo -e "${RED}Fuite de mémoire détectée (cas de base) :${NC}"
    echo "$valgrind_output_base"
else
    echo -e "${GREEN}Aucune fuite de mémoire détectée (cas de base)${NC}"
fi

echo -e "${YELLOW}Exécution normale (cas de base) :${NC}"
./pipex infile "cat" "grep mot" outfile
code_base=$(echo $?)
echo -e "${GREEN}Code retour de Pipex (cas de base) : ${code_base}${NC}"
bash -c "< infile cat | grep mot > bash_out.txt"
code_base_bash=$(echo $?)
echo -e "${GREEN}Code retour de Bash (cas de base) : ${code_base_bash}${NC}"

##############################################
# 2. Test : Infile inaccessible
##############################################
echo -e "${BLUE_BG}----------------------------------------${NC}"
echo -e "${YELLOW}Test : Infile inaccessible (exécution normale) :${NC}"
# On s'assure que infile n'existe pas
rm -f infile

./pipex infile "cat" "grep mot" outfile 2> pipex_err.txt
code_infile=$(echo $?)
echo -e "${GREEN}Code retour de Pipex avec infile inaccessible : ${code_infile}${NC}"
bash -c "< infile cat | grep mot > bash_out.txt" 2> bash_err.txt
code_infile_bash=$(echo $?)
echo -e "${GREEN}Code retour de Bash avec infile inaccessible : ${code_infile_bash}${NC}"
echo -e "${YELLOW}Message d'erreur Pipex :${NC}"
cat pipex_err.txt
echo -e "${YELLOW}Message d'erreur Bash :${NC}"
cat bash_err.txt

echo -e "${YELLOW}Test Valgrind : Infile inaccessible :${NC}"
valgrind_output_infile=$(valgrind --leak-check=full --quiet ./pipex infile "cat" "grep mot" outfile 2>&1)
echo "$valgrind_output_infile"

##############################################
# 3. Test : Commande inconnue
##############################################
echo -e "${BLUE_BG}----------------------------------------${NC}"
echo -e "${YELLOW}Test : Commande inconnue (exécution normale) :${NC}"
# Préparation d'un infile valide
echo -e "ligne1\nligne2" > infile

./pipex infile "cat" "commande_inexistante" outfile 2> pipex_err.txt
code_cmd=$(echo $?)
echo -e "${GREEN}Code retour de Pipex avec commande inconnue : ${code_cmd}${NC}"
bash -c "< infile cat | commande_inexistante > bash_out.txt" 2> bash_err.txt
code_cmd_bash=$(echo $?)
echo -e "${GREEN}Code retour de Bash avec commande inconnue : ${code_cmd_bash}${NC}"
echo -e "${YELLOW}Message d'erreur Pipex :${NC}"
cat pipex_err.txt
echo -e "${YELLOW}Message d'erreur Bash :${NC}"
cat bash_err.txt

echo -e "${YELLOW}Test Valgrind : Commande inconnue :${NC}"
valgrind_output_cmd=$(valgrind --leak-check=full --quiet ./pipex infile "cat" "commande_inexistante" outfile 2>&1)
echo "$valgrind_output_cmd"

##############################################
# 4. Test : Outfile inaccessible
##############################################
echo -e "${BLUE_BG}----------------------------------------${NC}"
echo -e "${YELLOW}Test : Outfile inaccessible (exécution normale) :${NC}"
# Création d'un dossier sans droits d'écriture pour simuler outfile inaccessible
mkdir no_write_dir
chmod 555 no_write_dir
# Préparation d'un infile valide
echo -e "ligne1\nligne2 mot\nligne3\nligne4 mot" > infile

./pipex infile "cat" "grep mot" no_write_dir/outfile 2> pipex_err.txt
code_outfile=$(echo $?)
echo -e "${GREEN}Code retour de Pipex avec outfile inaccessible : ${code_outfile}${NC}"
bash -c "< infile cat | grep mot > no_write_dir/outfile" 2> bash_err.txt
code_outfile_bash=$(echo $?)
echo -e "${GREEN}Code retour de Bash avec outfile inaccessible : ${code_outfile_bash}${NC}"
echo -e "${YELLOW}Message d'erreur Pipex :${NC}"
cat pipex_err.txt
echo -e "${YELLOW}Message d'erreur Bash :${NC}"
cat bash_err.txt

echo -e "${YELLOW}Test Valgrind : Outfile inaccessible :${NC}"
valgrind_output_outfile=$(valgrind --leak-check=full --quiet ./pipex infile "cat" "grep mot" no_write_dir/outfile 2>&1)
echo "$valgrind_output_outfile"
chmod 755 no_write_dir
rm -rf no_write_dir

##############################################
# Nettoyage final
##############################################
rm -f infile outfile bash_out.txt pipex_err.txt bash_err.txt

