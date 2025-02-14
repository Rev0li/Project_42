#!/bin/bash
# script-leak-detailed.sh
# Ce script réalise plusieurs tests en exécutant pipex sous Valgrind en mode détaillé.
# La sortie de Valgrind est enregistrée dans des fichiers distincts pour chaque cas,
# ce qui te permettra de visualiser exactement d'où provient l'erreur (fuite, permission, etc.).
#
# Assure-toi que ton programme pipex est compilé avec l'option -g pour obtenir des informations de debug.

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
rm -f valgrind_base.txt valgrind_infile.txt valgrind_cmd.txt valgrind_outfile.txt

##############################################
# 1. Test mémoire (cas de base) avec sortie détaillée
##############################################
echo -e "${BLUE_BG}----------------------------------------${NC}"
echo -e "${YELLOW}Test mémoire (Valgrind - cas de base) :${NC}"
# Création d'un infile valide
echo -e "ligne1\nligne2 mot\nligne3\nligne4 mot" > infile

# Exécution sous Valgrind avec options détaillées
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
  ./pipex infile "cat" "grep mot" outfile 2>&1 | tee valgrind_base.txt
echo -e "${YELLOW}=> Résumé (ligne 'definitely lost') :${NC}"
grep "definitely lost:" valgrind_base.txt
echo ""

##############################################
# 2. Test : Infile inaccessible avec sortie détaillée
##############################################
echo -e "${BLUE_BG}----------------------------------------${NC}"
echo -e "${YELLOW}Test : Infile inaccessible (Valgrind) :${NC}"
# On s'assure que infile n'existe pas
rm -f infile
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
  ./pipex infile "cat" "grep mot" outfile 2>&1 | tee valgrind_infile.txt
echo -e "${YELLOW}=> Extrait d'erreur (recherche 'No such file') :${NC}"
grep "No such file" valgrind_infile.txt
echo ""

##############################################
# 3. Test : Commande inconnue avec sortie détaillée
##############################################
echo -e "${BLUE_BG}----------------------------------------${NC}"
echo -e "${YELLOW}Test : Commande inconnue (Valgrind) :${NC}"
# Préparation d'un infile valide
echo -e "ligne1\nligne2" > infile
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
  ./pipex infile "cat" "commande_inexistante" outfile 2>&1 | tee valgrind_cmd.txt
echo -e "${YELLOW}=> Extrait d'erreur (recherche 'command not found') :${NC}"
grep "command not found" valgrind_cmd.txt
echo ""

##############################################
# 4. Test : Outfile inaccessible avec sortie détaillée
##############################################
echo -e "${BLUE_BG}----------------------------------------${NC}"
echo -e "${YELLOW}Test : Outfile inaccessible (Valgrind) :${NC}"
# Création d'un dossier sans droits d'écriture pour simuler un outfile inaccessible
mkdir no_write_dir
chmod 555 no_write_dir
# Préparation d'un infile valide
echo -e "ligne1\nligne2 mot\nligne3\nligne4 mot" > infile
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
  ./pipex infile "cat" "grep mot" no_write_dir/outfile 2>&1 | tee valgrind_outfile.txt
echo -e "${YELLOW}=> Extrait d'erreur (recherche 'Permission denied') :${NC}"
grep "Permission denied" valgrind_outfile.txt
chmod 755 no_write_dir
rm -rf no_write_dir
echo ""

##############################################
# Récapitulatif et recommandations
##############################################
echo -e "${BLUE_BG}----------------------------------------${NC}"
echo -e "${YELLOW}Les sorties détaillées de Valgrind ont été enregistrées dans les fichiers suivants :${NC}"
echo -e "  - Cas de base       : valgrind_base.txt"
echo -e "  - Infile inaccessible : valgrind_infile.txt"
echo -e "  - Commande inconnue : valgrind_cmd.txt"
echo -e "  - Outfile inaccessible : valgrind_outfile.txt"
echo ""
echo -e "${YELLOW}Conseils supplémentaires :${NC}"
echo -e "- Assure-toi que pipex est compilé avec l'option -g pour obtenir des informations de debug complètes."
echo -e "- Les options --show-leak-kinds=all et --track-origins=yes permettent d'obtenir un maximum de détails sur l'origine des erreurs."
echo -e "- Si ton programme n'a pas de fuite mémoire, Valgrind n'affichera pas de détails de ce côté, mais les messages d'erreur pour les cas d'accès ou de commandes manquantes seront bien présents."

