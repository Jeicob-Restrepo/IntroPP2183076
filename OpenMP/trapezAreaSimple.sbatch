#!/bin/bash
#SBATCH --job-name=trapezAreaSimple
#SBATCH --output=output_trapezAreaSimple.txt
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --cpus-per-task=4

gcc -fopenmp omp_trapezAreaSimple.c -o omp_trapecio
./omp_trapecio
