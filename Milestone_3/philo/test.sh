#!/bin/bash

BINARY=./philo

echo "===== TEST 1: Philosophe meurt seul ====="
$BINARY 1 800 200 200
echo

echo "===== TEST 2: 5 philosophes, pas de mort ====="
$BINARY 5 800 200 200
echo

echo "===== TEST 3: 5 philosophes, 3 repas chacun (stop propre) ====="
$BINARY 5 800 200 200 3
echo

echo "===== TEST 4: Temps de mort très court ====="
$BINARY 5 200 200 200
echo

echo "===== TEST 5: Arguments invalides ====="
$BINARY 0 800 200 200
$BINARY 5 -1 200 200
$BINARY 5 800 abc 200
echo

