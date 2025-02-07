#!/bin/bash

# Définition des couleurs pour l'affichage
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
BLUE_BG='\033[44m'
NC='\033[0m'

# Nettoyage des fichiers temporaires et des dossiers éventuels
rm -f infile outfile pipex_err.txt bash_err.txt bash_out.txt large_infile.txt
rm -rf no_write_dir

##############################################
# Test 1 : Fichier d'entrée inexistant
##############################################
echo -e "${BLUE_BG}----------------------------------------${NC}"
echo -e "${YELLOW}Test 1 : Fichier d'entrée inexistant${NC}"
echo ""
echo -e "${GREEN}Pipex (retour d'erreur) :${NC}"
./pipex infile "cat" "wc -w" outfile 2> pipex_err.txt
cat pipex_err.txt
echo -e "${GREEN}Bash (retour d'erreur) :${NC}"
bash -c "< infile cat | wc -w > outfile" 2> bash_err.txt
cat bash_err.txt
echo ""

##############################################
# Test 2 : Cas de base (deux commandes valides)
##############################################
echo -e "${BLUE_BG}----------------------------------------${NC}"
echo -e "${YELLOW}Test 2 : Cas de base (deux commandes valides)${NC}"
# Création d'un fichier d'entrée avec quelques lignes
echo -e "ligne1\nligne2 mot\nligne3\nligne4 mot" > infile
echo -e "${GREEN}Pipex :${NC}"
./pipex infile "cat" "grep mot" outfile
cat outfile
echo -e "${GREEN}Bash :${NC}"
bash -c "< infile cat | grep mot > bash_out.txt"
cat bash_out.txt
diff outfile bash_out.txt > /dev/null && echo -e "${GREEN}Test réussi${NC}" || echo -e "${RED}Test échoué${NC}"
echo ""

##############################################
# Test 3 : Commande inexistante
##############################################
echo -e "${BLUE_BG}----------------------------------------${NC}"
echo -e "${YELLOW}Test 3 : Commande inexistante${NC}"
echo -e "${GREEN}Pipex (retour d'erreur) :${NC}"
./pipex infile "cat" "commande_inexistante" outfile 2> pipex_err.txt
cat pipex_err.txt
echo -e "${GREEN}Bash (retour d'erreur) :${NC}"
bash -c "< infile cat | commande_inexistante > bash_err.txt" 2> bash_err.txt
cat bash_err.txt
echo ""

##############################################
# Test 4 : Fichier de sortie inaccessible
##############################################
echo -e "${BLUE_BG}----------------------------------------${NC}"
echo -e "${YELLOW}Test 4 : Fichier de sortie inaccessible${NC}"
# Création d'un dossier sans droits d'écriture
mkdir no_write_dir
chmod 555 no_write_dir
echo -e "${GREEN}Pipex (retour d'erreur) :${NC}"
./pipex infile "cat" "grep mot" no_write_dir/outfile 2> pipex_err.txt
cat pipex_err.txt
echo -e "${GREEN}Bash (retour d'erreur) :${NC}"
bash -c "< infile cat | grep mot > no_write_dir/outfile" 2> bash_err.txt
cat bash_err.txt
# Rétablissement des droits et suppression du dossier
chmod 755 no_write_dir
rm -rf no_write_dir
echo ""

##############################################
# Test 5 : Commande avec arguments
##############################################
echo -e "${BLUE_BG}----------------------------------------${NC}"
echo -e "${YELLOW}Test 5 : Commande avec arguments${NC}"
# Création d'un infile avec des lignes comportant différentes variations de 'mot'
echo -e "mot1\nMot2\nmot3\nMOT4\nnoMot" > infile
echo -e "${GREEN}Pipex :${NC}"
./pipex infile "grep -i mot" "wc -l" outfile
echo -e "Résultat Pipex :"
cat outfile
echo -e "${GREEN}Bash :${NC}"
bash -c "< infile grep -i mot | wc -l > bash_out.txt"
echo -e "Résultat Bash :"
cat bash_out.txt
diff outfile bash_out.txt > /dev/null && echo -e "${GREEN}Test réussi${NC}" || echo -e "${RED}Test échoué${NC}"
echo ""

# ##############################################
# # Test 6 : Here_doc
# ##############################################
# echo -e "${BLUE_BG}----------------------------------------${NC}"
# echo -e "${YELLOW}Test 6 : Here_doc${NC}"
# # Le mode here_doc : le premier argument est "here_doc", suivi du délimiteur (ici "EOF")
# echo -e "${GREEN}Pipex :${NC}"
# ./pipex here_doc EOF "cat" "grep mot" outfile <<EOF
# ligne sans mot
# ligne avec mot
# une autre ligne avec mot
# EOF
# echo -e "Résultat Pipex :"
# cat outfile
# echo -e "${GREEN}Bash :${NC}"
# bash -c "cat <<EOF | cat | grep mot > bash_out.txt
# ligne sans mot
# ligne avec mot
# une autre ligne avec mot
# EOF"
# echo -e "Résultat Bash :"
# cat bash_out.txt
# diff outfile bash_out.txt > /dev/null && echo -e "${GREEN}Test réussi${NC}" || echo -e "${RED}Test échoué${NC}"
# echo ""
#
# ##############################################
# # Test 7 : Multiples commandes (bonus)
# ##############################################
# echo -e "${BLUE_BG}----------------------------------------${NC}"
# echo -e "${YELLOW}Test 7 : Multiples commandes (bonus)${NC}"
# # Création d'un infile comportant plusieurs lignes incluant 'mot'
# echo -e "première ligne\nligne avec mot\nune autre ligne\nmot dans la ligne" > infile
# echo -e "${GREEN}Pipex :${NC}"
# ./pipex infile "cat" "grep mot" "wc -l" outfile
# echo -e "Résultat Pipex :"
# cat outfile
# echo -e "${GREEN}Bash :${NC}"
# bash -c "< infile cat | grep mot | wc -l > bash_out.txt"
# echo -e "Résultat Bash :"
# cat bash_out.txt
# diff outfile bash_out.txt > /dev/null && echo -e "${GREEN}Test réussi${NC}" || echo -e "${RED}Test échoué${NC}"
# echo ""

# ##############################################
# # Test 8 : Fichier volumineux
# ##############################################
# echo -e "${BLUE_BG}----------------------------------------${NC}"
# echo -e "${YELLOW}Test 8 : Fichier volumineux${NC}"
# # Génération d'un grand fichier d'entrée (ici 10 000 lignes)
# seq 1 10000 > large_infile.txt
# echo -e "${GREEN}Pipex :${NC}"
# ./pipex large_infile.txt "cat" "wc -l" outfile
# echo -e "Résultat Pipex :"
# cat outfile
# echo -e "${GREEN}Bash :${NC}"
# bash -c "< large_infile.txt cat | wc -l > bash_out.txt"
# echo -e "Résultat Bash :"
# cat bash_out.txt
# diff outfile bash_out.txt > /dev/null && echo -e "${GREEN}Test réussi${NC}" || echo -e "${RED}Test échoué${NC}"
# echo ""

# Nettoyage des fichiers temporaires et des dossiers éventuels
rm -f infile outfile pipex_err.txt bash_err.txt bash_out.txt large_infile.txt
rm -rf no_write_dir
