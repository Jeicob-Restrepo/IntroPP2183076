#!/bin/bash
#SBATCH -N 1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=8
#SBATCH -t 00:05:00

echo "Inicio de la ejecución: $(date)"

module load gcc/9.3.0
gcc -fopenmp trapezAreaSimple.c -o trapezAreaSimple

./trapezAreaSimple

echo "Fin de la ejecución: $(date)"