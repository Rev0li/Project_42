#!/bin/bash

# Nettoyage des fichiers générés
rm -f infile outfile ref_out err_out

echo "=============================="
echo "Test HARD 1: Infile inexistant"
echo "------------------------------"
# On attend une erreur lorsque l'infile n'existe pas.
./pipex non_existent_file "cat" "wc -w" outfile 2> err_out
ret=$?
if [ $ret -ne 0 ]; then
    echo "Test HARD 1 réussi (erreur sur infile inexistant détectée)"
else
    echo "Test HARD 1 échoué (aucune erreur détectée pour infile inexistant)"
fi
rm -f err_out

echo "=============================="
echo "Test HARD 2: Outfile invalide (chemin de fichier invalide)"
echo "------------------------------"
# On crée un répertoire pour simuler un outfile invalide.
mkdir -p dir_out
./pipex infile "cat" "wc -w" dir_out 2> err_out
ret=$?
if [ $ret -ne 0 ]; then
    echo "Test HARD 2 réussi (erreur sur outfile invalide détectée)"
else
    echo "Test HARD 2 échoué (aucune erreur détectée pour outfile invalide)"
    rm -rf dir_out
fi
rm -f err_out
rm -rf dir_out

echo "=============================="
echo "Test HARD 3: Commande complexe avec sed"
echo "------------------------------"
# On teste une commande de transformation avec sed.
echo "banana apple grape" > infile
cat infile | sed s/a/A/g > ref_out
./pipex infile "cat" "sed s/a/A/g" outfile
if diff ref_out outfile > /dev/null; then
    echo "Test HARD 3 réussi."
else
    echo "Test HARD 3 échoué."
fi

echo "=============================="
echo "Test HARD 4: Manque d'arguments"
echo "------------------------------"
# On exécute pipex avec un nombre d'arguments insuffisant.
./pipex infile "cat" "wc -w" 2> err_out
ret=$?
if [ $ret -ne 0 ]; then
    echo "Test HARD 4 réussi (manque d'arguments détecté)"
else
    echo "Test HARD 4 échoué (manque d'arguments non détecté)"
    rm -f err_out
fi
rm -f err_out

echo "=============================="
echo "Test HARD 5: Fichier d'entrée volumineux"
echo "------------------------------"
# Génération d'un fichier volumineux contenant 10 000 lignes
rm -f infile outfile ref_out
for i in $(seq 1 3500); do
    echo "Ligne numéro $i"
done > infile

cat infile | wc -l > ref_out
./pipex infile "cat" "wc -l" outfile
if diff ref_out outfile > /dev/null; then
    echo "Test HARD 5 réussi."
else
    echo "Test HARD 5 échoué."
fi

echo "=============================="
echo "Test HARD 6: Concurrency (sleep commands)"
echo "------------------------------"
# Création d'un infile vide
touch infile

# Mesurer le temps d'exécution
start=$(date +%s)
./pipex infile "sleep 10" "sleep 5" outfile
end=$(date +%s)
elapsed=$(( end - start ))
echo "Temps écoulé : $elapsed secondes"

# On considère que le temps devrait être inférieur à 12 secondes (avec une marge)
if [ $elapsed -lt 14 ]; then
    echo "Test HARD 6 réussi (exécution concurrente détectée)"
else
    echo "Test HARD 6 échoué (temps d'exécution trop long, comportement séquentiel)"
fi

echo "=============================="
echo "Tous les tests HARD sont terminés."

