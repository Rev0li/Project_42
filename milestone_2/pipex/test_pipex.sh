#!/bin/bash
# Nettoyage des fichiers temporaires
rm -f infile outfile pipex_err.txt bash_err.txt bash_out.txt

# Définition des couleurs
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
BLUE_BG='\033[44m'
NC='\033[0m'

echo -e "${BLUE_BG}                                      ${NC}"
echo -e "${YELLOW}Test 1 : infile inexistant${NC}"
echo  ""

echo -e "${GREEN}Pipex (retour d'erreur) :${NC}"
./pipex infile "cat" "wc -w" outfile 2> pipex_err.txt
cat pipex_err.txt

echo -e "${GREEN}Bash (retour d'erreur) :${NC}"
bash -c "< infile cat | wc -w > outfile" 2> bash_err.txt
cat bash_err.txt
echo  ""


# Nettoyage des fichiers temporaires
rm -f infile outfile pipex_err.txt bash_err.txt bash_out.txt

# echo "================================"
# echo "Test 3 : outfile sans droits d'accès"
# echo "--------------------------------"
# # Préparation de infile et outfile
# echo "Hello World" > infile
# echo "Contenu initial" > outfile
# # Retrait des droits d'écriture sur outfile
# chmod 444 outfile
# echo "Pipex (retour d'erreur) :"
# ./pipex infile "cat" "wc -w" outfile 2> pipex_err.txt
# cat pipex_err.txt
# echo "Bash (retour d'erreur sur redirection) :"
# # La redirection vers un fichier non accessible générera une erreur
# bash -c "cat infile | wc -w" > outfile 2> bash_err.txt
# cat bash_err.txt
# # Restauration des droits pour outfile
# chmod 644 outfile
#
#
# # Nettoyage des fichiers temporaires
# rm -f infile outfile pipex_err.txt bash_err.txt bash_out.txt
#
echo -e "${BLUE_BG}                                      ${NC}"
echo -e "${YELLOW}Test 4 : commande invalide${NC}"
echo  ""
# Préparation de infile
echo "Hello World" > infile
echo -e "${GREEN}Pipex (retour d'erreur) :${NC}"
./pipex infile "cat" "invalidcommand" outfile 2> pipex_err.txt
cat pipex_err.txt
echo -e "${GREEN}Bash (retour d'erreur) :${NC}"
bash -c "cat infile | invalidcommand" 2> bash_err.txt
cat bash_err.txt
echo  ""


# Nettoyage des fichiers temporaires
rm -f infile outfile pipex_err.txt bash_err.txt bash_out.txt

# echo "================================"
# echo "Test 5 : manque d'arguments"
# echo "--------------------------------"
# # Exemple : appel avec un nombre insuffisant d'arguments
# echo "Pipex (retour d'erreur) :"
# ./pipex infile "cat" 2> pipex_err.txt
# cat pipex_err.txt
# echo "Bash (commande incomplète) :"
# bash -c "cat infile" 2> bash_err.txt
# cat bash_err.txt
#
#
# # Nettoyage des fichiers temporaires
# rm -f infile outfile pipex_err.txt bash_err.txt bash_out.txt
#
# echo "================================"
# echo "Test 6 : test sleep"
# echo "--------------------------------"
# # Ce test permet de vérifier que votre Pipex gère bien une commande incluant un délai.
# echo "1 2 3 4 5" > infile
# echo "Pipex (sortie) :"
# ./pipex infile "cat" "sh -c 'sleep 1; wc -w'" outfile
# cat outfile
# echo "Bash (sortie) :"
# bash -c "cat infile | sh -c 'sleep 1; wc -w'" > bash_out.txt
# cat bash_out.txt
#
#
# # Nettoyage des fichiers temporaires
# rm -f infile outfile pipex_err.txt bash_err.txt bash_out.txt
#
# echo "================================"
# echo "Test 7 : test leak (Valgrind)"
# echo "--------------------------------"
# # Ce test lance Pipex sous Valgrind pour vérifier les fuites de mémoire.
# echo "Valgrind (Pipex) :"
# echo "Leak test" > infile
# valgrind --leak-check=full --trace-children=yes --error-exitcode=0 ./pipex infile "cat" "wc -w" outfile
#
# # ------------------------------
# # Tests additionnels (optionnels)
# # ------------------------------
# # Nettoyage des fichiers temporaires
# rm -f infile outfile pipex_err.txt bash_err.txt bash_out.txt
#
# echo "================================"
# echo "Test 8 : infile sans droits de lecture"
# echo "--------------------------------"
# echo "Hello World" > infile
# chmod 000 infile
# echo "Pipex (retour d'erreur) :"
# ./pipex infile "cat" "wc -w" outfile 2> pipex_err.txt
# cat pipex_err.txt
# echo "Bash (retour d'erreur) :"
# bash -c "cat infile | wc -w" 2> bash_err.txt
# cat bash_err.txt
# chmod 644 infile
#
#
# # Nettoyage des fichiers temporaires
# rm -f infile outfile pipex_err.txt bash_err.txt bash_out.txt
#
# echo "================================"
# echo "Test 9 : infile est un dossier"
# echo "--------------------------------"
# mkdir -p test_dir
# echo "Pipex (retour d'erreur) :"
# ./pipex test_dir "cat" "wc -w" outfile 2> pipex_err.txt
# cat pipex_err.txt
# echo "Bash (retour d'erreur) :"
# bash -c "< test_dir cat | wc -w > outfile" 2> bash_err.txt
# cat bash_err.txt
# rm -rf test_dir
#
#
# # Nettoyage des fichiers temporaires
# rm -f infile outfile pipex_err.txt bash_err.txt bash_out.txt
#
# echo "================================"
# echo "Test 10 : outfile est un dossier"
# echo "--------------------------------"
# mkdir -p test_dir
# echo "Hello World" > infile
# echo "Pipex (retour d'erreur) :"
# ./pipex infile "cat" "wc -w" test_dir 2> pipex_err.txt
# #cat pipex_err.txt
# echo "Bash (retour d'erreur sur redirection) :"
# bash -c "cat infile | wc -w" > test_dir 2> bash_err.txt
# #cat bash_err.txt
# rm -rf test_dir
#
# echo "================================"
# echo "Fin des tests."

# Nettoyage des fichiers temporaires
rm -f infile outfile pipex_err.txt bash_err.txt bash_out.txt


